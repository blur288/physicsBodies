#include "Object.h"
#include <cmath>
#include <iostream>

Object::Object(float mass, float radius, Color color, physics::Vec2 position, int ID) {
    this->mass = mass;
    this->radius = radius;
    this->color = color;
    this->position = position;
    this->ID = ID;
}

Object::Object() {
    this->mass = 1;
    this->radius = 1;
    this->color = BLACK;
    this->position = {0,0};
}


void Object::drawObject() {
    physics::Vec2 EndPoint = physics::calculatePositonBasedOnVelocity(position, {velocity.x * 100, velocity.y});
    DrawCircle(position.x, position.y, radius, color);
    DrawLineEx({position.x, position.y}, {EndPoint.x, EndPoint.y}, 2, RED);

    if (velocity.calculateMagnitude() < 0.1) return;
    //arrow ONLY FOR VEL MAG >= 1
    //random values for arrow "wing" that j look good
    /*
    float wingMag = 9;
    float wingRotation = 2.5; //radians
    //first arrow wing
    Vector2 arrowWingOne = {EndPoint.x + wingMag * cos(velocity.y + wingRotation), EndPoint.y + wingMag * sin(velocity.y + wingRotation)};
    DrawLineEx({EndPoint.x, EndPoint.y}, arrowWingOne, 2, RED);

    Vector2 arrowWingTwo = {EndPoint.x + wingMag * cos(velocity.y - wingRotation), EndPoint.y + wingMag * sin(velocity.y - wingRotation)};
    DrawLineEx({EndPoint.x, EndPoint.y}, arrowWingTwo, 2, RED);
    */

}


void Object::updateObject() {
    //convert velocity and acceleration to vector components
    //Velocity in components

    physics::Vec2 velo = {
        velocity.x * cos(velocity.y),
        velocity.x * sin(velocity.y)
    };
    //Acceleration in components
    physics::Vec2 accel = {
        acceleration.x * cos(acceleration.y),
        acceleration.x * sin(acceleration.y)
    };
    //Velocity in components based on v + a
    physics::Vec2 velocityComponents = { velo.x + accel.x, velo.y + accel.y };

    //Convert from components to theta + magnitude
    float Theta = atan2(velocityComponents.y, velocityComponents.x);
    float Magnitude = sqrt(pow(velocityComponents.x, 2) + pow(velocityComponents.y, 2));
    velocity.y = Theta;
    velocity.x = Magnitude;

    //Debug
    physics::Vec2 newPos =  calculatePositonBasedOnVelocity(position, velocity);
    this->position = newPos;
    //End Debug


    //this->position = physics::calculatePositonBasedOnVelocity(position, velocity);
}

void Object::updateVelocity(physics::Vec2 velocity) {
    this->velocity = velocity;
}

void Object::updateAcceleration(physics::Vec2 acceleration) {
    this->acceleration = acceleration;
}

void Object::setID(int ID) {
    this->ID = ID;
}

void Object::Debug() {
    if (ID>=0)
        std::cout << "ID: " << this->ID << "\n";

    std::cout << "Ax: " << this->acceleration.x << "\n";
    std::cout << "Ay: " << this->acceleration.y << "\n";

    std::cout << "Vx: " << this->velocity.x << "\n";
    std::cout << "Vy: " << this->velocity.y << "\n";

    std::cout << "Px: " << this->position.x << "\n";
    std::cout << "Py: " << this->position.y << "\n";
}

//compare distance in cartesion
float Object::calculateDistanceTwoObjects(Object obj1, Object obj2) {
    //Sqrt( arg1^2 + arg2^2 )
    float arg1 = obj1.position.x - obj2.position.x;
    float arg2 = obj1.position.y - obj2.position.y;
    return sqrt(pow(arg1, 2) + pow(arg2, 2));
}

float Object::calculateDirectionTwoObjects(Object obj1, Object obj2) {
    /*Super simple right triangle get theta
     *                   o (x_2, y_2)
     *                   /|
     *                 /  |
     *               /    |
     *             /      | B
     *           /        |
     *         /          |
     *      o/>T__________|
     *      (x_1, y_1)
     *              A
     *      A = x_2 - x_1, B = y_2 - y_1
     *      T = atan( B / A )
     */
    return atan2(obj2.position.y - obj1.position.y, obj2.position.x - obj1.position.x);
}

float Object::calculateDirection(Object object) {
    //Why are we adding pi to this?: not sure, just works
    float d = atan2(object.position.y - this->position.y, object.position.x - this->position.x);
    return atan2(object.position.y - this->position.y, object.position.x - this->position.x) + PI;
}

float Object::getMass() {
    return mass;
}

physics::Vec2 Object::getPosition() {
    return position;
}

float Object::getRadius() {
    return radius;
}
Color Object::getColor() {
    return color;
}

int Object::getID() {
    return ID;
}
physics::Vec2 Object::getVelocity() {
    return velocity;
}
physics::Vec2 Object::getAcceleration() {
    return acceleration;
}









