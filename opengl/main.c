#include "glad.c"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
    unsigned char r,g,b,a;
} Color;
typedef struct {
    float r,g,b,a;
}ColorF;

void framefubber_size_callback(GLFWwindow *window, int width, int height){
    glViewport(0,0,width,height); // used for transformation between openGL coordinates and window coordinates
}

void setClearColor(unsigned int colorHex){
    ColorF color = {0};
    color.r = (float)((colorHex >> 24) & 0xFF)/255;
    color.g = (float)((colorHex >> 16) & 0xFF)/255;
    color.b = (float)((colorHex >> 8) & 0xFF)/255;
    color.a = (float)(colorHex & 0xFF)/255;
    glClearColor(color.r, color.g, color.b,color.a);
}

const char* getShader(const char* filePath){ // can return null
    FILE *f = fopen(filePath, "r");
    if(!f) goto error_jump;

    fseek(f, 0, SEEK_END);
    long lenght = ftell(f);
    if(lenght <= 0) goto error_jump;
    fseek(f, 0, SEEK_SET);

    char *buffer = malloc(lenght+1);
    if(buffer == NULL) goto error_jump;
    if(fread(buffer, 1, lenght, f) != (size_t) lenght)
        goto error_jump;
    buffer[lenght] = '\0';

    fclose(f);
    return buffer;

    error_jump:
        fclose(f);
        free(buffer);
        return NULL;
}

float vertices[] = {
    // x, y, z
    -.5f, -.5f, 0.f,
    .5f, -.5f, 0.f,
    0.f, .5f, 0.f
};

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // max version to run
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // minor version to run
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // small subset of openGL (since the other functions are for backward compatibility)
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
#ifdef __APPLE__ // macOS compatible
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPACT, GL_TRUE);
#endif
    // start window context
    GLFWwindow *window = NULL;
    if(0){ // for funsies
        GLFWmonitor *monitor = glfwGetPrimaryMonitor(); // apparently is for fullscren?
        window  = glfwCreateWindow(800, 600, "hi chat", monitor, NULL);
    } else {
        window  = glfwCreateWindow(800, 600, "hi chat", NULL, NULL);
    }
    assert(window != NULL); // window shall be created
    glfwMakeContextCurrent(window);

    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)); // glad shall work
    glfwSetFramebufferSizeCallback(window, framefubber_size_callback); // set callback to resize window
    
    unsigned int VBO = 0; // id of the VBO.
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // get vertex shader
    const char* vertexFile = getShader("glsl/vertex.glsl");
    assert(vertexFile != NULL);
    unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID, 1, &vertexFile, NULL);
    glCompileShader(vertexShaderID);
    int success = 0;
    char infoLog[512] = {0};
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
        printf("%s", infoLog);
    }

    // render loop
    setClearColor(0x282828FF); // configure openGL clearColor mask buffer (changes a state of openGL)
    while(!glfwWindowShouldClose(window)){
        // update
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, true);
        }
        // render
        glClear(GL_COLOR_BUFFER_BIT); // clear color with openGL color
        // check and call events and swap buffers
        glfwPollEvents(); // for getting events (eg: windowClose)
        glfwSwapBuffers(window); // for double buffering
    }
    free((void*)vertexFile);
    glfwTerminate(); // finishes the glfw library
    return 0;
}
