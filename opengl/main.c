#define RGFW_IMPLEMENTATION
#include "glad.c"
#include <GLFW/glfw3.h>
#include <assert.h>
#include <stdbool.h>

void framefubber_size_callback(GLFWwindow *window, int width, int height){
    glViewport(0,0,width,height); // used for transformation between openGL coordinates and window coordinates
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
        window  = glfwCreateWindow(100, 100, "hi chat", monitor, NULL);
    } else {
        window = glfwCreateWindow(100, 100, "hi chat", NULL, NULL);
    }
    assert(window != NULL); // window shall be created
    glfwMakeContextCurrent(window);

    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)); // glad shall work
    glfwSetFramebufferSizeCallback(window, framefubber_size_callback); // set callback to resize window

    while(!glfwWindowShouldClose(window)){
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, true);
        }
        glfwSwapBuffers(window); // for double buffering
        glfwPollEvents(); // for getting events (eg: windowClose)
    }
    glfwTerminate(); // finishes the glfw library
    return 0;
}
