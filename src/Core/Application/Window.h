#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Log.h"

namespace Serum {
    struct WindowManager {
        static GLFWwindow* Window;
        static std::pair<double, double> WindowSize;

        static void CreateWindow(int width, int height, const char* title);
        static void CloseWindow();
    };
}