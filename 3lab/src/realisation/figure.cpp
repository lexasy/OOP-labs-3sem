#include "../includes/figure.hpp"

Point Figure::geometrical_centre() const {
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
    return round((n * length_btw_points(points[1], points[0]) * length_btw_points(points[1], points[0]) / 4) * (1 / tan(M_PI / n)) * 1000) / 1000; // round to 3 digits
}

Point *Figure::get_array_pointer() {
    return points;
}