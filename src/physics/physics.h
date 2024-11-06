#ifndef PHYSICS_H
#define PHYSICS_H


namespace physics {
    struct Vec2 {
        float x; float y;
        float calculateMagnitude();
        //Convert from (r, t) -> (x, y)
        physics::Vec2 convertToComponents();
        //(x, y) -> (r, t)
        physics::Vec2 convertToPolar();
    };
    const double G = 0.000000000066742;
    Vec2 calculatePositonBasedOnVelocity(Vec2 position, Vec2 velocity);
};



#endif //PHYSICS_H
