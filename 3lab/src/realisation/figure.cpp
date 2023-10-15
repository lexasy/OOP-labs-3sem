#include "../includes/figure.hpp"

Point Figure::geometrical_centre() const {
    for (int i = 1; i < n; i++) {
        if (round(length_btw_points(points[i], points[i + 1 == n ? 0 : i + 1]) * 1000) / 1000 != round(length_btw_points(points[0], points[1]) * 1000) / 1000) {
            throw std::logic_error{"That's not a correct figure!\n"};
        }
    }
    Point result;
    for (int i = 0; i < n; i++) {
        result.x += points[i].x;
        result.y += points[i].y;
    }
    result.x /= n; result.y /= n;
    result.x = round(result.x * 1000) / 1000;
    result.y = round(result.y * 1000) / 1000;
    return result;
}

Figure::operator double() const {
    for (int i = 1; i < n; i++) {
        if (round(length_btw_points(points[i], points[i + 1 == n ? 0 : i + 1]) * 1000) / 1000 != round(length_btw_points(points[0], points[1]) * 1000) / 1000) {
            throw std::logic_error{"That's not a correct figure!\n"};
        }
    }
    return round((n * length_btw_points(points[1], points[0]) * length_btw_points(points[1], points[0]) / 4) * (1 / tan(M_PI / n)) * 1000) / 1000; // round to 3 digits
}

Point *Figure::get_array_pointer() const {
    return points;
}