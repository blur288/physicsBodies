#include "physics.h"
#include "math.h"

/*
 * This takes a Vec2 position and Vec2 velocity and calculates
 * a new position given the Theta and Magnitude of velocity
 *
 * @param position Inital position cordinates
 * @param velocty Velocity vector in (theta (rads), magnitude)
 * @return A new position with the updates velocity
 */
physics::Vec2 physics::calculatePositonBasedOnVelocity(Vec2 position, Vec2 velocity) {
    return {
        //x^ = m sin(theta) + x
        //y^ = m cos(theta) + y
        .x = velocity.x * cos(velocity.y) + position.x,
        .y = velocity.x * -sin(velocity.y) + position.y};
}

float physics::Vec2::calculateMagnitude() {
    return sqrt(pow(abs(x), 2) + pow(abs(y), 2));
}

//polar to cartesian
physics::Vec2 physics::Vec2::convertToComponents() {
    return {-x * cos(y), x * sin(y)};

}

physics::Vec2 physics::Vec2::convertToPolar() {
    float Mag = this->calculateMagnitude();
    float Direction = atan2(y, x);
    return {Mag, Direction};

}

