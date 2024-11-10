#include "figures.hpp"
#include <cmath>

Rect::Rect(double a, double b) {
    if (a <= 0 || b <= 0) {
        throw LessThanZeroParam("Rectangle parameters must be positive");
    }
    length = a;
    height = b;
}

FigureType Rect::Type() const {
    return FigureType::RECTANGLE;
}

double Rect::Perimeter() const {
    return 2 * (length + height);
}

double Rect::Area() const {
    return length * height;
}

Triangle::Triangle(double side_a, double side_b, double side_c) {
    if (side_a <= 0 || side_b <= 0 || side_c <= 0) {
        throw LessThanZeroParam("Triangle sides must be positive");
    }
    
    a = side_a;
    b = side_b;
    c = side_c;

    if (!((a + b > c) && (b + c > a) && (a + c > b))) {
        throw WrongTriangle("Triangle with given sides cannot exist");
    }
}

FigureType Triangle::Type() const {
    return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const {
    return a + b + c;
}

double Triangle::Area() const {
    // Using Heron's formula
    double s = Perimeter() / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

Circle::Circle(double r) {
    if (r <= 0) {
        throw LessThanZeroParam("Circle radius must be positive");
    }
    radius = r;
}

FigureType Circle::Type() const {
    return FigureType::CIRCLE;
}

double Circle::Perimeter() const {
    return 2 * PI * radius;
}

double Circle::Area() const {
    return PI * radius * radius;
}

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) {
    switch (type) {
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(a, b);
        
        case FigureType::TRIANGLE:
            return std::make_unique<Triangle>(a, b, c);
        
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(a);
        
        default:
            throw std::invalid_argument("Unknown figure type");
    }
}
