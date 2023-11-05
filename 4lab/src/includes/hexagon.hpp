#include "figure.hpp"

template <Numeric T>
class Hexagon final : public Figure<T> {
public:
    friend std::istream& operator>>(std::istream& is, Hexagon<T>& fig) {
        std::cout << "Please type in the coordinates of points of your hexagon, order [x,y], separated by spaces:\n";
        for (size_t i = 0; i < fig.n; i++) {
            std::cout << "Point" << i + 1 << ": "; is >> fig.points[i];
        }
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, Hexagon<T>& fig) {
        os << "Coordinates of hexagon:\n";
        for (size_t i = 0; i < fig.n; i++) {
            os << "Point" << i + 1 << ": " << fig.points[i];
        }
        return os;
    }
    Hexagon() {
        this->n = 6;
        this->points = std::shared_ptr<Point<T>[]>(new Point<T>[this->n]);
    }
    Hexagon(Point<T>& pt1, Point<T>& pt2, Point<T>& pt3, Point<T>& pt4, Point<T>& pt5, Point<T>& pt6) {
        this->n = 6;
        this->points = std::shared_ptr<Point<T>[]>(new Point<T>[this->n]);
        this->points[0] = pt1; this->points[1] = pt2; this->points[2] = pt3; this->points[3] = pt4; this->points[4] = pt5; this->points[5] = pt6;
    }
    void operator=(const Hexagon<T>& fig) {
        this->points[0] = fig.points[0]; this->points[1] = fig.points[1]; this->points[2] = fig.points[2]; this->points[3] = fig.points[3]; this->points[4] = fig.points[4]; this->points[5] = fig.points[5];
    }
    void operator=(Hexagon<T>&& fig) {
        this->n = fig.n;
        this->points = fig.points;
        fig.n = 0;
        fig.points = nullptr;
    }
    bool operator==(const Hexagon<T>& fig) const {
        return static_cast<double>(*this) == static_cast<double>(fig);
    }
    ~Hexagon() = default;
};