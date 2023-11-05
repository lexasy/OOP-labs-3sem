#include "figure.hpp"

template <Numeric T>
class Pentagon final : public Figure<T> {
public:
    const std::string return_type() const override {
        return {"Pentagon"};
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
    Pentagon(const Pentagon<T>& fig) { // хз че за конструктор, но думаю благодаря shared_ptr мы можем так сделать
        this->n = fig.n;
        this->points = fig.points;
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
};