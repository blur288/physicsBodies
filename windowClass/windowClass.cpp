#include "windowClass.h"
#include <iostream>
#include <ostream>
#include "imgui/imgui.h"
#include "rlImGui.h"

windowClass::windowClass(int screenHeight, int screenWidth, int targetFps, Color backgroundColor, std::string windowName) {
    this->screenHeight = screenHeight;
    this->screenWidth = screenWidth;
    this->targetFps = targetFps;
    this->backgroundColor = backgroundColor;
    this->windowName = windowName;
}

windowClass::~windowClass() {
    CloseWindow();
}


void windowClass::init() {
    std::cout << screenWidth << "x" << screenHeight << std::endl;
    InitWindow(screenWidth, screenHeight, windowName.c_str());
    SetTargetFPS(targetFps);
    pauseButton = LoadTexture("../asset/pause.png");
    playButton = LoadTexture("../asset/play.png");
}

bool windowClass::getState() {
    return paused;
}

void windowClass::update() {
    DrawCircle(50, 50, 70, WHITE);
    if (paused)
        DrawTexture(playButton, 0, 0, WHITE);
    else
        DrawTexture(pauseButton, 0, 0, WHITE);

    //Check clicked
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        float mX = GetMouseX();
        float mY = GetMouseY();
        if (CheckCollisionPointCircle({mX, mY}, {50, 50}, 70)) {
            paused = !paused;
        }
    }
}

void windowClass::drawUI() {
    rlImGuiBegin();

    ImGui::SetNextWindowPos(ImVec2(1000, 0));
    ImGui::SetNextWindowSize(ImVec2(500, this->screenHeight));

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.21f, 0.21f, 0.21f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_TitleBg, ImVec4(0.14f, 0.14f, 0.14f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.14f, 0.14f, 0.14f, 1.0f));

    ImGui::Begin("Settings", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
    {
        ImGui::Checkbox("Paused", &paused);
        ImGui::Checkbox("Gravity", &gravity);

        //Objects
        ImGui::SetNextWindowPos(ImVec2(1010, 70));
        ImGui::SetNextWindowSize(ImVec2(500, 100));
        ImGui::BeginChild("Object");
        for (int n = 0; n < 50; n++)
            ImGui::Text("%04d: Some text", n);
        ImGui::EndChild();
    }
    ImGui::End();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();

    rlImGuiEnd();
}




