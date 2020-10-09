#include "Application.h"

namespace Serum {
    void Application::Run() {
        Log::Init();

        Initialize();

        WindowManager::CreateWindow(InitialWindowWidth, InitialWindowHeight, InitialWindowTitle.c_str());

        // Initialize ImGui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO(); (void)io;

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Keyboard controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable docking mode
        //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Multi viewport

        ImGui_ImplGlfw_InitForOpenGL(WindowManager::Window, true);
        ImGui_ImplOpenGL3_Init("#version 410");
        ImGui::StyleColorsDark();

        // When viewport enabled tweak WindowRounding/WindowBg
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;

        LoadResources();

        while(!glfwWindowShouldClose(WindowManager::Window)) {
            this->DeltaTime = static_cast<float>(glfwGetTime()) - this->TotalElapsedSeconds;
            this->TotalElapsedSeconds = static_cast<float>(glfwGetTime());

            glfwPollEvents();

            // Register next frame on ImGui
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            Update();
            Render();

            io.DisplaySize = ImVec2((float)std::get<0>(WindowManager::WindowSize), (float)std::get<1>(WindowManager::WindowSize));

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(WindowManager::Window);
        }

        // Destroy ImGui
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        WindowManager::CloseWindow();
    }

    Application::Application(int initialWindowWidth, int initialWindowHeight, std::string initialWindowTitle)
            : InitialWindowWidth(initialWindowWidth), InitialWindowHeight(initialWindowHeight),
              InitialWindowTitle(std::move(initialWindowTitle)) {}
}