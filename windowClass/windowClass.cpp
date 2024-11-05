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

void windowClass::drawChildrenPhysicBodies(int posX, int posY, scene::objectInitializer objectData) {
    ImGui::SetNextWindowPos(ImVec2(posX, posY));
    ImGui::SetNextWindowSize(ImVec2(500, 100));
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.15, 0.15, 0.15, 1.0));

    ImGui::BeginChild("Object");

    std::string idText = "Object ID: " + std::to_string(objectData.ID);
    ImGui::Text(idText.c_str());

    std::string posText = "Object Pos: " + std::to_string(objectData.position.x) + ", " + std::to_string(objectData.position.y);
    ImGui::Text(posText.c_str());

    std::string velText = "Object Velocity: " + std::to_string(objectData.acceleration.x) + ", " + std::to_string(objectData.acceleration.y);
    ImGui::Text(velText.c_str());

    std::string accText = "Object Acceleration: " + std::to_string(objectData.velocity.x) + ", " + std::to_string(objectData.velocity.y);
    ImGui::Text(accText.c_str());

    ImGui::EndChild();
    ImGui::PopStyleColor();
}

void windowClass::drawUI(std::vector<scene::objectInitializer> objectDataList) {
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
        drawChildrenPhysicBodies(1010, 70, objectDataList[0]);
    }
    ImGui::End();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();

    rlImGuiEnd();
}




