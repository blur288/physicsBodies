#include "scene.h"

#include <iostream>
#include <ostream>

scene::scene(std::vector<objectInitializer> objectInitlizers) {
    for (auto objectInit : objectInitlizers) {
        //Object(float mass, float radius, Color color, physics::Vec2 position);
        Object newObj = Object(
            objectInit.mass,
            objectInit.radius,
            objectInit.color,
            objectInit.position
            );
        newObj.updateVelocity(objectInit.acceleration);
        newObj.updateAcceleration(objectInit.acceleration);
        newObj.setID(this->ID);
        this->ID++;
        objects.push_back(newObj);
    }
}

void scene::updateBodies() {
    for (Object& object : objects) {
        object.updateObject();
    }
}

void scene::drawBodies() {
    for (auto object : objects) {
        object.drawObject();
    }
}

//this is a crazy func def but it just takes a list of objects and gives an init list
std::vector<scene::objectInitializer> scene::objectInitializer::objectDataConstruct(std::vector<Object> objects) {
    /*
    * float mass = 0;
        float radius = 0;
        physics::Vec2 position = { 0,0};
        physics::Vec2 velocity = { 0,0};
        physics::Vec2 acceleration = { 0,0};
        Color color = WHITE;
    */
    std::vector<scene::objectInitializer> constructedInitializer;
    for (auto object : objects) {

    }
}

//takes in an init list and spits out objects
std::vector<Object> scene::objectInitializer::getObjects(std::vector<objectInitializer> objectData) {
    std::vector<Object> constructedObjects;
    for (auto objectInit : objectData) {
        //Object(float mass, float radius, Color color, physics::Vec2 position);
        Object newObj = Object(
            objectInit.mass,
            objectInit.radius,
            objectInit.color,
            objectInit.position
            );
        newObj.updateVelocity(objectInit.acceleration);
        newObj.updateAcceleration(objectInit.acceleration);
        constructedObjects.push_back(newObj);
    }
    return constructedObjects;
}





/*
 *Outdated 2-body problem
 *
 *
//Gravity!

a = G * (m1 + m2) / (r^2)


if (!window.getState()) {
double productOfMasses = bigBody.getMass() * smallBody.getMass();
double radius = Object::calculateDistanceTwoObjects(bigBody, smallBody);
float f = physics::G * productOfMasses / pow(radius, 2);

bigBody.updateAcceleration({bigBody.calculateDirection(smallBody), f/bigBody.getMass()});
smallBody.updateAcceleration({smallBody.calculateDirection(bigBody), f/smallBody.getMass()});

smallBody.Debug();

bigBody.updateObject();
smallBody.updateObject();
}
*/


