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

void windowClass::drawChildrenPhysicBody(int posX, int posY, scene::objectInitializer objectData, int ID) {
    ImGui::SetNextWindowPos(ImVec2(posX, posY));
    ImGui::SetNextWindowSize(ImVec2(480, 100));
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.15, 0.15, 0.15, 1.0));

    std::string ChildName = "Object" + std::to_string(ID);
    ImGui::BeginChild(ChildName.c_str());

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

void windowClass::drawChildrenPhysicBodies(std::vector<scene::objectInitializer> objectData) {
    //honestly magic offset numbers
    const int rightOffset = 1010;
    const int topOffset = 70;
    //magic margin numbers!
    const int sideMarginLength = 500;
    const int verticleMarginLength = 100;
    //some nice padding after first iteration cuz why not
    int vertPadding = 0;

    for (int i = 0; i < objectData.size(); i++) {
        drawChildrenPhysicBody(rightOffset, topOffset + (verticleMarginLength * i) + vertPadding, objectData[i], i);
        if (!i)
            vertPadding = 10;
    }
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
        drawChildrenPhysicBodies(objectDataList);

    }
    ImGui::End();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();

    rlImGuiEnd();
}




