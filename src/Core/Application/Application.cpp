#include "Application.h"

#include "../imgui_impl/imgui_theme.h"
#include "../Events/ApplicationEvent.h"

namespace Serum {
    void Application::Run() {
        Log::Init();

        Initialize();

        Window::CreateWindow(InitialWindowWidth, InitialWindowHeight, InitialWindowTitle.c_str());
        Window::SetEventCallback(BIND_EVENT_FN(OnEvent));

        // Initialize ImGui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO(); (void)io;

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;kok

        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui_ImplGlfw_InitForOpenGL(Window::GetWindow(), true);
        ImGui_ImplOpenGL3_Init("#version 410");
        ImGui::StyleColorsDark();

        UseTheme();
        LoadResources();

        while(!glfwWindowShouldClose(Window::GetWindow())) {
            this->DeltaTime = static_cast<float>(glfwGetTime()) - this->TotalElapsedSeconds;
            this->TotalElapsedSeconds = static_cast<float>(glfwGetTime());

            glfwPollEvents();

            // Register next frame on ImGui
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            Update();
            Render();

            io.DisplaySize = ImVec2((float)std::get<0>(Window::WindowSize), (float)std::get<1>(Window::WindowSize));

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(Window::GetWindow());
        }

        // Destroy ImGui
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        Window::CloseWindow();
    }

    Application::Application(int initialWindowWidth, int initialWindowHeight, std::string initialWindowTitle)
            : InitialWindowWidth(initialWindowWidth), InitialWindowHeight(initialWindowHeight),
              InitialWindowTitle(std::move(initialWindowTitle)) {}

    void Application::OnEvent(Event &e) {
    }
}