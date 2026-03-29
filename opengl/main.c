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
    char *buffer = {0};
    FILE *f = fopen(filePath, "r");
    if(!f) goto error_jump;

    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    if(length <= 0) goto error_jump;
    fseek(f, 0, SEEK_SET);

    buffer = malloc(length+1);
    if(buffer == NULL) goto error_jump;
    if(fread(buffer, 1, length, f) != (size_t) length)
        goto error_jump;
    buffer[length] = '\0';

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
    
    // generate VBO
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

    // get fragment shader
    const char* fragmentShader = getShader("glsl/fragment.glsl");
    unsigned int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderID,1, &fragmentShader, NULL);
    glCompileShader(fragmentShaderID);
    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
        printf("%s", infoLog);
    }

    // generate shader program
    unsigned int shaderProgram = glCreateProgram();
    
    // bind vertex and fragment shaders inside program
    glAttachShader(shaderProgram, vertexShaderID);
    glAttachShader(shaderProgram, fragmentShaderID);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("%s", infoLog);
    }


    // delete vertex and fragment shaders (its not needed anymore). Just a cleanup
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    free((void*)vertexFile);
    free((void*)fragmentShader);

    glVertexAttribPointer(
        0, // layout (location = 0)
        3, // vec3
        GL_FLOAT, // vector consist of float values
        GL_FALSE, // they are already normalized
        3*sizeof(float), // how far away each vec3 is from each other
        (void*)0); // offset of where the data begins in the VBO (probably)
    glEnableVertexAttribArray(0);
    // render loop
    setClearColor(0x282828FF); // configure openGL clearColor mask buffer (changes a state of openGL)
    while(!glfwWindowShouldClose(window)){
        // update
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, true);
        }
        // render
        glClear(GL_COLOR_BUFFER_BIT); // clear color with openGL color
        glUseProgram(shaderProgram);
        // check and call events and swap buffers
        glfwPollEvents(); // for getting events (eg: windowClose)
        glfwSwapBuffers(window); // for double buffering
    }
    glfwTerminate(); // finishes the glfw library
    return 0;
}
