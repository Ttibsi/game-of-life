#ifndef TEMPLATES_H
#define TEMPLATES_H

// coordinate on screen
struct Point2d {
    float x;
    float y;
};

// Triangle coordinates
struct Triangle2d {
    Point2d v1;
    Point2d v2;
    Point2d v3;
};

#endif
