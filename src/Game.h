#pragma once

#include "Core/Application/Application.h"

#include <utility>

class Game : public Serum::Application {
    void Initialize() override;
    void LoadResources() override;

    void Update() override;
    void Render() override;

    int width, height;
    GLuint tex_brand;

    bool aboutWindow = false;
public:
    Game(int width, int height, std::string title) : Application(width, height, std::move(title)) {};
};