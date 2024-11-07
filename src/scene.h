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

        objectInitializer(float m, float r, physics::Vec2 p, physics::Vec2 v, physics::Vec2 a, Color c, int id=-1)
            :mass(m), radius(r), position(p), velocity(v), acceleration(a), color(c), ID(id)
        {}

        static std::vector<objectInitializer> objectDataConstruct(std::vector<Object> objects);
        static std::vector<Object> getObjects(std::vector<objectInitializer> objectData);
    };

    //Acceleration / Velocity for new object
    physics::Vec2* acceleration = new physics::Vec2{0, 0};
    physics::Vec2* velocity = new physics::Vec2{0, 0};

    scene(std::vector<objectInitializer> objects);
    void updateBodies();
    void drawBodies();
    void Gravity();

    void getInput();
    physics::Vec2* getAcceleration();
    physics::Vec2* getVelocity();

    std::vector<Object> getObjects();

    ~scene();
};



#endif //SCENE_H
