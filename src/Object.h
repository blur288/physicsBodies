#ifndef OBJECT_H
#define OBJECT_H

#include <string>

#include "raylib.h"
#include "physics/physics.h"

class Object {
    //properties
    float mass;
    float radius;
    //Position
    physics::Vec2 position;
    //Velocity (Defined by theta and magnitude)
    physics::Vec2 velocity;
    //acceleration (T, M)
    physics::Vec2 acceleration;
    //visuals
    Color color;
    int ID = 0;
public:
    Object();
    Object(float mass, float radius, Color color, physics::Vec2 position);

    float getMass();
    float getRadius();
    Color getColor();
    int getID();
    physics::Vec2 getVelocity();
    physics::Vec2 getAcceleration();
    physics::Vec2 getPosition();

    void updateVelocity(physics::Vec2 velocity);
    void updateAcceleration(physics::Vec2 acceleration);
    void setID(int ID);

    void updateObject();
    physics::Vec2 calculatePosition();
    float calculateDirection(Object object);

    void drawObject();
    void Debug();

    static float calculateDistanceTwoObjects(Object obj1, Object obj2);
    static float calculateDirectionTwoObjects(Object obj1, Object obj2);
};



#endif //OBJECT_H
