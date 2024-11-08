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
            objectInit.position,
            objectInit.ID
            );
        newObj.updateVelocity(objectInit.velocity);
        newObj.updateAcceleration(objectInit.acceleration);
        newObj.setID(this->ID);
        this->ID++;
        objects.push_back(newObj);
    }
}

void scene::removeBody(int ID) {
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i].getID() == ID) objects.erase(objects.begin() + i);
    }
}


std::vector<Object> scene::getObjects() {
    //IMPORTANT: this will return a COPY of objects
    return this->objects;
}

physics::Vec2 *scene::getAcceleration() {
    return newAcceleration;
}

physics::Vec2 *scene::getVelocity() {
    return newVelocity;
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
    std::vector<scene::objectInitializer> constructedInitializerList;
    for (auto object : objects) {
        objectInitializer newObjectInitializer = objectInitializer(
            object.getMass(),
            object.getRadius(),
            object.getPosition(),
            object.getVelocity(),
            object.getAcceleration(),
            object.getColor(),
            object.getID()
            );
        constructedInitializerList.push_back(newObjectInitializer);
    }
    return constructedInitializerList;
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
            objectInit.position,
            objectInit.ID
            );
        newObj.updateVelocity(objectInit.velocity);
        newObj.updateAcceleration(objectInit.acceleration);
        constructedObjects.push_back(newObj);
    }
    return constructedObjects;
}

void scene::getInput() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mousePosition = GetMousePosition();
        if (mousePosition.x >= 1000) return;

        Object newObj = Object(*newMass, *newRadius, WHITE, {mousePosition.x, mousePosition.y});
        newObj.updateAcceleration({newAcceleration->x * -1, newAcceleration->y });
        newObj.updateVelocity({newVelocity->x * -1, newVelocity->y});
        newObj.setID(this->ID);
        this->ID++;

        objects.push_back(newObj);

    }
}


void scene::Gravity() {
    //Add all forces
    physics::Vec2 totalForce = {};
    std::vector<physics::Vec2> Forces = {};
    for (Object &object : objects) {
        Forces = {};
        for (auto comparatorObject : objects) {
            if (comparatorObject.getID() == object.getID()) continue;
            //f = G * (m1 + m2) / (r^2)
            double productOfMasses = object.getMass() * comparatorObject.getMass(); //(m1 + m2)
            double radius = Object::calculateDistanceTwoObjects(object, comparatorObject); //(r^2)
            float force = physics::G * productOfMasses / pow(radius, 2);
            float direction = comparatorObject.calculateDirection(object) + PI;
            Forces.push_back({force, direction});
        }

        //Add all forces
        totalForce = {};
        for (auto Force : Forces) {
            //Convert to x y component
            physics::Vec2 forceInComponent = Force.convertToComponents();
            totalForce.x += forceInComponent.x;
            totalForce.y += forceInComponent.y;
        }
        totalForce = totalForce.convertToPolar();
        //2nd law of motion
        totalForce.x /= object.getMass();
        //coles law of hacky fixes
        totalForce.x *= 10000;
        //Convert totalForce to (r, t)
        object.updateAcceleration(totalForce);
    }
}

scene::~scene() {
    free(newVelocity);
    free(newAcceleration);
    free(newMass);
    free(newRadius);
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


