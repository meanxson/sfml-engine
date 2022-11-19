//
// Created by meanx on 09/11/2022.
//

#include <valarray>
#include "Vector2.h"
#include "../Consts.h"

Vector2::Vector2(const Vector2 &vector2) {
    m_point[0] = vector2.x();
    m_point[1] = vector2.y();
}

Vector2::Vector2(const Vector4 &point4) {
    // m_point[0] = point4.x();
    // m_point[1] = point4.y();
}

Vector2::Vector2(double x, double y) {
    m_point[0] = x;
    m_point[1] = y;
}

Vector2 Vector2::operator-() const {
    return Vector2(-x(), -y());
}

bool Vector2::operator==(const Vector2 &vector2) const {
    Vector2 diff = *this - vector2;

    return diff.sqrAbs() < Consts::EPS;
}

bool Vector2::operator!=(const Vector2 &vector2) const {
    return !(*this == vector2);
}

Vector2 Vector2::operator+(const Vector2 &vector2) const {
    return Vector2(x() + vector2.x(), y() + vector2.y());
}

Vector2 Vector2::operator-(const Vector2 &vector2) const {
    return Vector2(x() - vector2.x(), y() - vector2.y());
}

Vector2 Vector2::operator*(double number) const {
    return Vector2(x() * number, y() * number);
}

Vector2 Vector2::operator/(double number) const {
    if (std::abs(number) > Consts::EPS) {
        return Vector2(x() / number, y() / number);
    } else {
        throw std::domain_error{"Vector2::operator/(double number): division by zero"};
    }
}

double Vector2::sqrAbs() const {
    return x() * x() + y() * y();
}

double Vector2::abs() const {
    return std::sqrt(sqrAbs());
}

double Vector2::dot(const Vector2 &vector2) const {
    return x() * vector2.x() + y() * vector2.y();
}

Vector2 Vector2::normalized() const {
    return Vector2();
}

bool Vector2::is_near(double a, double b) {
    return std::abs(a - b) < Consts::EPS;
}

