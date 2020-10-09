#include "WindowManager.h"

namespace Serum {
    GLFWwindow* WindowManager::Window;
    std::pair<double, double> WindowManager::WindowSize;

    void WindowManager::CreateWindow(int width, int height, const char* title) {
        WindowSize = std::pair<double, double>(width, height);

        if (!glfwInit()) {
            CORE_FATAL("GLFW could not be initialized!");
        }

        // Initialize window profiles
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindowHint(GLFW_RESIZABLE, true);
        glfwWindowHint(GLFW_FOCUSED, true);

        Window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        if (!Window) {
            CORE_FATAL("Window could not be initialized!");
        }

        glfwMakeContextCurrent(Window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            CORE_FATAL("GLAD could not be initialized!");
        }

        glViewport(0, 0, width, height);

        // Turn on vsync
        glfwSwapInterval(1);
    }

    void WindowManager::CloseWindow() {
        glfwTerminate();
    }
}