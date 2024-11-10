#pragma once

#include <memory>
#include <stdexcept>

// Make PI accessible to tests and other code
constexpr double PI = 3.14;

enum class FigureType
{
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
};

class Figure {
public:
    virtual ~Figure() = default;  // Add virtual destructor for proper cleanup
    virtual FigureType Type() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Rect : public Figure
{
private:
    double length;
    double height;

public:
    Rect(double a, double b);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Triangle : public Figure
{
private:
    double a, b, c;

public:
    Triangle(double side_a, double side_b, double side_c);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Circle : public Figure
{
private:
    double radius;

public:
    Circle(double r);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;
};

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

class WrongTriangle : public std::invalid_argument
{
public:
    using std::invalid_argument::invalid_argument;
};

class LessThanZeroParam : public std::invalid_argument
{
public:
    using std::invalid_argument::invalid_argument;
};
