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

    scene::objectInitializer Obj0 {100000000.0, 3, {266, 500}, {0,0}, {0,0}, WHITE};
    scene::objectInitializer Obj1 {100000000.0, 3, {499, 500}, {0.5,0}, {0,0}, WHITE};
    scene::objectInitializer Obj2 {100000000.0, 3, {765, 500}, {0.5,0}, {0,0}, WHITE};
    scene Scene({Obj0, Obj1, Obj2});

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (!window.getPaused())
            if (window.getGravity())
                Scene.Gravity();
            Scene.updateBodies();
        Scene.drawBodies();

        //We need to send in body info to the UI
        window.drawUI(scene::objectInitializer::objectDataConstruct(Scene.getObjects()));

        EndDrawing();
    }
    CloseWindow();
    rlImGuiShutdown();

    return 0;
}
