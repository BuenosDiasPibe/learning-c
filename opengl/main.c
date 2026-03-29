#define RGFW_IMPLEMENTATION
#include "glad.c"
#include <GLFW/glfw3.h>
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
        window  = glfwCreateWindow(1000, 1000, "hi chat", monitor, NULL);
    } else {
        window = glfwCreateWindow(1000, 1000, "hi chat", NULL, NULL);
    }
    assert(window != NULL); // window shall be created
    glfwMakeContextCurrent(window);

    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)); // glad shall work
    glfwSetFramebufferSizeCallback(window, framefubber_size_callback); // set callback to resize window

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
    glfwTerminate(); // finishes the glfw library
    return 0;
}
