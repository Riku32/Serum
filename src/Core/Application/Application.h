#pragma once

#include <string>

#include <imgui.h>
#include "../imgui_impl/imgui_impl_glfw.h"
#include "../imgui_impl/imgui_impl_opengl3.h"

#include "Window.h"
#include "../Events/Event.h"
#include "../Events/ApplicationEvent.h"

namespace Serum {
    class Application {
    public:
        Application(int initialWindowWidth, int initialWindowHeight, std::string initialWindowTitle);

        void OnEvent(Event& e);

        void Run();
    protected:
        int InitialWindowWidth;
        int InitialWindowHeight;
        std::string InitialWindowTitle;

        float DeltaTime, TotalElapsedSeconds;

        virtual void Initialize() = 0;
        virtual void LoadResources() = 0;

        virtual void Update() = 0;
        virtual void Render() = 0;

        bool OnWindowClose(WindowCloseEvent &e);

        bool OnWindowResize(WindowResizeEvent &e);
    };
}