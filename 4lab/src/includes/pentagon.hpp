#include "figure.hpp"

template <Numeric T>
class Pentagon final : public Figure<T> {
public:
    friend std::istream& operator>>(std::istream& is, Pentagon<T>& fig) {
        std::cout << "Please type in the coordinates of points of your pentagon, order [x,y], separated by spaces:\n";
        for (size_t i = 0; i < fig.n; i++) {
            std::cout << "Point" << i + 1 << ": "; is >> fig.points[i];
        }
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, Pentagon<T>& fig) {
        os << "Coordinates of pentagon:\n";
        for (size_t i = 0; i < fig.n; i++) {
            os << "Point" << i + 1 << ": " << fig.points[i];
        }
        return os;
    }
    Pentagon() {
        this->n = 5;
        this->points = std::shared_ptr<Point<T>[]>(new Point<T>[this->n]);
    }
    Pentagon(Point<T>& pt1, Point<T>& pt2, Point<T>& pt3, Point<T>& pt4, Point<T>& pt5) {
        this->n = 5;
        this->points = std::shared_ptr<Point<T>[]>(new Point<T>[this->n]);
        this->points[0] = pt1; this->points[1] = pt2; this->points[2] = pt3; this->points[3] = pt4; this->points[4] = pt5;
    }
    void operator=(const Pentagon<T>& fig) {
        this->points[0] = fig.points[0]; this->points[1] = fig.points[1]; this->points[2] = fig.points[2]; this->points[3] = fig.points[3]; this->points[4] = fig.points[4];
    }
    void operator=(Pentagon<T>&& fig) {
        this->n = fig.n;
        this->points = fig.points;
        fig.n = 0;
        fig.points = nullptr;
    }
    bool operator==(const Pentagon<T>& fig) const {
        return static_cast<double>(*this) == static_cast<double>(fig);
    }
    ~Pentagon() = default;
};