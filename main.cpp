#include "raylib.h"
#include "src/Object.h"
#include "windowClass/windowClass.h"
#include "src/physics/physics.h"
#include "rlImGui.h"
#include "imgui/imgui.h"
#include "src/scene.h"

int main()
{
    //ScreenHeight, ScreenWidth, targetFps, windowName
    windowClass window(900, 1500, 60, BLACK, "Physics Demo");
    window.init();
    rlImGuiSetup(true);
    //Define Obj1
    //Mass: 50
    //Radius: 50
    //Pos (500, 500)
    scene::objectInitializer Obj0 {1000000000000.0, 50, {500, 500}, {0,0}, {0,0}, WHITE};
    scene::objectInitializer Obj1 {100.0, 10, {500, 300}, {0,0}, {0,0}, WHITE};
    scene Scene({Obj0, Obj1});

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        Scene.updateBodies();
        Scene.drawBodies();

        window.drawUI();

        EndDrawing();
    }
    CloseWindow();
    rlImGuiShutdown();

    return 0;
}
