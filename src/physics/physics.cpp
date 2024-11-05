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
        .x = velocity.y * cos(velocity.x) + position.x,
        .y = velocity.y * -sin(velocity.x) + position.y};
}