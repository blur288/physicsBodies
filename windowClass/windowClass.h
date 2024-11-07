#ifndef WINDOWCLASS_H
#define WINDOWCLASS_H
#include <raylib.h>
#include <vector>
#include "../src/scene.h"
#include <string>

class windowClass {
    int screenHeight = 1000;
    int screenWidth = 1000;
    int targetFps = 60;
    Color backgroundColor = BLACK;
    std::string windowName;
    Texture2D pauseButton, playButton;
    //states
    bool paused = false;
    bool gravity = true;
private:
    void drawChildrenPhysicBody(int posX, int posY, scene::objectInitializer objectData, int ID);
    void drawChildrenPhysicBodies(std::vector<scene::objectInitializer> objectData);
    void drawAccVel();
public:
    windowClass();
    ~windowClass();
    windowClass(int ScreenHeight, int ScreenWidth, int TargetFps, Color BackgroundColor, std::string windowName);
    void init();
    void update();
    bool getPaused();
    bool getGravity();
    void drawUI(std::vector<scene::objectInitializer> objectDataList);
};



#endif //WINDOWCLASS_H
