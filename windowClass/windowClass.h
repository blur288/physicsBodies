#ifndef WINDOWCLASS_H
#define WINDOWCLASS_H
#include <raylib.h>
#include <vector>
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
public:
    windowClass();
    ~windowClass();
    windowClass(int ScreenHeight, int ScreenWidth, int TargetFps, Color BackgroundColor, std::string windowName);
    void init();
    void update();
    bool getState();
    void drawUI();
};



#endif //WINDOWCLASS_H
