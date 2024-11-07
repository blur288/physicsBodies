#include "windowClass.h"
#include <iostream>
#include <ostream>

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

bool windowClass::getPaused() {
    return paused;
}

bool windowClass::getGravity() {
    return gravity;
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
    ImVec2 v2CSP = ImGui::GetCursorScreenPos();
    ImGui::SetNextWindowPos(ImVec2(posX, posY));
    ImGui::SetNextWindowSize(ImVec2(480, 100));
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.15, 0.15, 0.15, 1.0));

    std::string ChildName = "Object" + std::to_string(ID);
    ImGui::BeginChild(ChildName.c_str());

    std::string idText = "Object ID: " + std::to_string(objectData.ID);
    ImGui::Text(idText.c_str());

    std::string posText = "Object Pos: " + std::to_string(objectData.position.x) + ", " + std::to_string(objectData.position.y);
    ImGui::Text(posText.c_str());

    std::string velText = "Object Acceleration: " + std::to_string(objectData.acceleration.x) + ", " + std::to_string(objectData.acceleration.y);
    ImGui::Text(velText.c_str());

    std::string accText = "Object Velocity: " + std::to_string(objectData.velocity.x) + ", " + std::to_string(objectData.velocity.y);
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


    ImVec2 v2CSP = ImGui::GetCursorScreenPos();
    for (int i = 0; i < objectData.size(); i++) {
        //drawChildrenPhysicBody(rightOffset, topOffset + (verticleMarginLength * i), objectData[i], i);
        drawChildrenPhysicBody(v2CSP.x, v2CSP.y + (verticleMarginLength * i) + 50, objectData[i], i);
    }
}

// ImVec2 windowClassLL:CaptureClick() {
//     if (ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
//         ImVec2 clickPos = ImGui::GetMousePos();
//     }
// }

void windowClass::drawAccVel(physics::Vec2* Acceleration, physics::Vec2* Velocity) {
    if (ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
        ImVec2 clickPos = ImGui::GetMousePos();

        //Acceleration
        if (clickPos.x > 1100 && clickPos.x < 1200 && clickPos.y > 20 && clickPos.y < 120) {
            float a = (clickPos.x - 1150);
            float b = (clickPos.y - 70);
            //calc radius and normalize
            float r = sqrt(a * a + b * b)/100;
            float t = atan2(b, -a);
            Acceleration->x = r;
            Acceleration->y = t;
        }
        //Velocity
        if (clickPos.x > 1250 && clickPos.x < 1350 && clickPos.y > 20 && clickPos.y < 120) {
            float a = (clickPos.x - 1300);
            float b = (clickPos.y - 70);
            //calc radius and normalize
            float r = sqrt(a * a + b * b)/100;
            float t = atan2(b, -a);
            Velocity->x = r;
            Velocity->y = t;
        }
    }

    ImDrawList* drawList = ImGui::GetWindowDrawList();

    //Calculate Acceleration Line
    physics::Vec2 AccEndLine = physics::Vec2({Acceleration->x * 100, Acceleration->y}).convertToComponents();
    drawList->AddRectFilled({1100, 20}, {1200, 120}, IM_COL32_WHITE);
    drawList->AddLine({1150, 70}, {1150 + AccEndLine.x, 70 + AccEndLine.y}, ImGui::GetColorU32(ImVec4(1, 0, 0, 1)), 4);

    //Calculate Velocity Line
    physics::Vec2 VelEndLine = physics::Vec2({Velocity->x * 100, Velocity->y}).convertToComponents();
    drawList->AddRectFilled({1250, 20}, {1350, 120}, IM_COL32_WHITE);
    drawList->AddLine({1300, 70}, {1300 + VelEndLine.x, 70 + VelEndLine.y}, ImGui::GetColorU32(ImVec4(1, 0, 0, 1)), 4);
}

void windowClass::drawUI(scene& Scene) {
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
        drawAccVel(Scene.getAcceleration(), Scene.getVelocity());

        ImGui::BeginChild("objects");
            drawChildrenPhysicBodies(scene::objectInitializer::objectDataConstruct(Scene.getObjects()));
        ImGui::EndChild();

    }
    ImGui::End();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();
    ImGui::PopStyleColor();

    rlImGuiEnd();
}




