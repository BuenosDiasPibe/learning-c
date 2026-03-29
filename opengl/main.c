#define RGFW_IMPLEMENTATION
#include "glad.c"
#include <GLFW/glfw3.h>
#include <assert.h>
#include <stdbool.h>

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
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    GLFWwindow  *window  = glfwCreateWindow(1000, 1000, "hi chat", monitor, NULL);
    assert(window != NULL); // window shall be created
    glfwMakeContextCurrent(window);

    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)); // glad shall work

    return 0;
}
