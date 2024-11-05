#ifndef PHYSICS_H
#define PHYSICS_H


namespace physics {
    struct Vec2 {
        float x; float y;
    };
    const double G = 0.000000000066742;
    Vec2 calculatePositonBasedOnVelocity(Vec2 position, Vec2 velocity);
};



#endif //PHYSICS_H
