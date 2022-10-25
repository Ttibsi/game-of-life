#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

struct Point {
    int x_cord;
    int y_cord;
    bool live;
};

inline std::ostream &operator<<(std::ostream &os, const Point &c) {
    os << std::string("{") << std::to_string(c.x_cord) << std::string(", ")
       << std::to_string(c.y_cord) << std::string(" : ")
       << std::to_string(c.live) << std::string("}");

    return os;
}

inline bool operator==(const Point &c, const Point &d) {
    if (c.x_cord == d.x_cord && c.y_cord == d.y_cord) {
        return true;
    } else {
        return false;
    }
}

using board_t = std::vector<Point>;

#endif
