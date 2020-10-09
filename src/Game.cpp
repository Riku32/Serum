#include "Game.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb_image_resize.h>

#include "version.h"

#include <cmath>

void Game::Initialize() {

}

void Game::LoadResources() {
    int channels;
    unsigned char *img = stbi_load("../assets/Banner_White.png", &width, &height, nullptr, 4);

    glGenTextures(1, &tex_brand);
    glBindTexture(GL_TEXTURE_2D, tex_brand);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(img);
}

void Game::Update() {

}

void Game::Render() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    {
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

        // About page
        ImGui::Begin("About Serum");
        ImGui::Image((void*)(intptr_t)tex_brand, ImVec2(width/4, height/4));
        ImGui::TextColored(ImVec4(1,1,0,1), "About");
        ImGui::Text("Git commit: %s", GIT_COMMIT_HASH());
        ImGui::Text("Branch: %s", GIT_BRANCH());
        ImGui::End();

        ImGui::Begin("Demo window#");
        ImGui::Button("Hello!");
        ImGui::End();
    }
}