#ifndef SCENE_H
#define SCENE_H

#include "Object.h"
#include "physics/physics.h"
#include <vector>

class scene {

    //Physics Bodies within the scene
    std::vector<Object> objects;
    int ID = 0;
public:
    static struct objectInitializer {
        float mass = 0;
        float radius = 0;
        physics::Vec2 position = { 0,0};
        physics::Vec2 velocity = { 0,0};
        physics::Vec2 acceleration = { 0,0};
        Color color = WHITE;
        int ID = -1;

        objectInitializer(float m, float r, physics::Vec2 p, physics::Vec2 v, physics::Vec2 a, Color c)
            :mass(m), radius(r), position(p), velocity(v), acceleration(a), color(c)
        {}

        static std::vector<objectInitializer> objectDataConstruct(std::vector<Object> objects);
        static std::vector<Object> getObjects(std::vector<objectInitializer> objectData);
    };

    scene(std::vector<objectInitializer> objects);
    void updateBodies();
    void drawBodies();
};



#endif //SCENE_H
