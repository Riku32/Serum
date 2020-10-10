#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Log.h"
#include "../Events/Event.h"
#include "../Events/ApplicationEvent.h"
#include "../Events/KeyEvent.h"
#include "../Events/MouseEvent.h"

namespace Serum {
    struct Window {
        using EventCallbackFn = std::function<void(Event&)>;

        struct WindowData {
            EventCallbackFn EventCallback;
        };

        static std::pair<double, double> WindowSize;

        static void CreateWindow(int width, int height, const char* title);
        static void CloseWindow();

        static GLFWwindow* GetWindow() { return glfw_window; }

        static void SetEventCallback(const EventCallbackFn& callback) { window_data.EventCallback = callback; }
    private:
        static GLFWwindow* glfw_window;

        static WindowData window_data;
    };
}