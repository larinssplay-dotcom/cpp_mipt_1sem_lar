#include <iostream>
#include <string>
#include <cmath>

const double PI = 3.1415926535;
const double sr = 1e-6;

class Shape 
{
private:
protected:
    std::string name_;

public:
    Shape() = default;
    const std::string& getName() const;
    
    Shape(const Shape& other) = default;
    Shape(Shape&& other) = default;
    Shape& operator=(const Shape& other) = default;
    Shape& operator=(Shape&& other) = default;
    virtual ~Shape() = default;

    virtual double calcarea() const;
    virtual double calcperimeter() const;
};

class Triangle : public Shape 
{
private:
    double a_;
    double b_;
    double c_;

public:
    Triangle(double a, double b, double c)
    {
    if (a <= 0.0 | b <= 0.0 | c <= 0.0)
        throw std::runtime_error("стороны должны быть >0");
    if (a + b <= c | a + c <= b | b + c <= a)
        throw std::runtime_error("нарушено нерав треугольника");
    }

    Triangle(const Triangle& other) = default;
    Triangle(Triangle&& other) = default;
    Triangle& operator=(const Triangle& other) = default;
    Triangle& operator=(Triangle&& other) = default;
    virtual ~Triangle() = default;

    double calcarea() const override 
    {
        double p = calcperimeter() / 2.0;
        return std::sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }

    double calcperimeter() const override 
    { 
        return a_ + b_ + c_; 
    }
};
class Rectangular : public Shape
{
private:
        double width_;
        double length_;
public:
        virtual double calcperimeter() const override
        {
            return(( width_ + length_) * 2.0);
        }
        virtual double calcarea() const override
        {
            return(width_ * length_);
        }

        Rectangular(double width, double length)
        {
        if (width <= 0.0 | length <= 0.0)
            throw std::runtime_error("стороны должны быть >0");
        }
        virtual ~Rectangular() = default;
        Rectangular(const Rectangular& other) = default;
        Rectangular(Rectangular&& other) = default;
        Rectangular& operator=(const Rectangular& other) = default;
        Rectangular& operator=(Rectangular&& other) = default;
        
    };

class Circle : public Shape
{
private:
        double radius_;
public:
        virtual double calcperimeter() const override
        {
            return(PI * radius_ * 2.0);
        }
        virtual double calcarea() const override
        {
            return(PI * radius_ * radius_);
        }

        Circle(double radius)
        {
            if (radius <= 0)
                throw std::runtime_error("радиус должен быть >0");
        }
        virtual ~Circle() = default;
        Circle(const Circle& other) = default;
        Circle(Circle&& other) = default;
        Circle& operator=(const Circle& other) = default;
        Circle& operator=(Circle&& other) = default;
};

class Square : public Rectangular
{
private:
    double width_ ;
    double length_;
public:
    Square(double width, double length);
    Square(const Square& other) = default;
    Square(Square&& other) = default;
    Square& operator=(const Square& other) = default;
    Square& operator=(Square&& other) = default;
    virtual ~Square() = default;
};

class Shape;
bool operator==(const Shape& lhs, const Shape& rhs) 
{
    return std::abs(lhs.calcarea() - rhs.calcarea()) < sr;
}
bool operator^(const Shape& lhs, const Shape& rhs) {
    return std::abs(lhs.calcperimeter() - rhs.calcperimeter()) < sr;
}
std::ostream& operator<<(std::ostream& stream, const Shape& rhs)
{
    stream << "figr: " << rhs.getName()
       << "area = " << rhs.calcarea()
       << "perimeter= " << rhs.calcperimeter();
    return stream;
}
