#pragma once

#include <memory>
#include <stdexcept>

enum class FigureType
{
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
};

class Figure {
public:
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
    FigureType Type() const;
    double Perimeter() const;
    double Area() const;
};

class Triangle : public Figure
{
private:
    double a, b, c;

public:
    Triangle(double side_a, double side_b, double side_c);
    FigureType Type() const;
    double Perimeter() const;
    double Area() const;
};

class Circle : public Figure
{
private:
    double radius;

public:
    Circle(double r);
    FigureType Type() const;
    double Perimeter() const;
    double Area() const;
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

