#include "figure.hpp"

template <Numeric T>
class Octagon final : public Figure<T> {
public:
    const std::string return_type() const override {
        return {"Octagon"};
    }
    Octagon() {
        this->n = 8;
        this->points = std::shared_ptr<Point<T>[]>(new Point<T>[this->n]);
    }
    Octagon(Point<T>& pt1, Point<T>& pt2, Point<T>& pt3, Point<T>& pt4, Point<T>& pt5, Point<T>& pt6, Point<T>& pt7, Point<T>& pt8) {
        this->n = 8;
        this->points = std::shared_ptr<Point<T>[]>(new Point<T>[this->n]);
        this->points[0] = pt1; this->points[1] = pt2; this->points[2] = pt3; this->points[3] = pt4; this->points[4] = pt5; this->points[5] = pt6; this->points[6] = pt7; this->points[7] = pt8;
    }
    Octagon(const Octagon<T>& fig) { // хз че за конструктор, но думаю благодаря shared_ptr мы можем так сделать
        this->n = fig.n;
        this->points = fig.points;
    }
    void operator=(const Octagon<T>& fig) {
        this->points[0] = fig.points[0]; this->points[1] = fig.points[1]; this->points[2] = fig.points[2]; this->points[3] = fig.points[3]; this->points[4] = fig.points[4]; this->points[5] = fig.points[5]; this->points[6] = fig.points[6]; this->points[7] = fig.points[7];
    }
    bool operator==(const Octagon<T>& fig) const {
        return static_cast<double>(*this) == static_cast<double>(fig);
    }
    ~Octagon() = default;
};