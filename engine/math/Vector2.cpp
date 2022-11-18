//
// Created by meanx on 09/11/2022.
//

#include "Vector2.h"

//Todo: Realize

bool Vector2::is_near(double a, double b) {
    return false;
}

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

    return false;
}

bool Vector2::operator!=(const Vector2 &vector2) const {
    return false;
}

Vector2 Vector2::operator+(const Vector2 &vector2) const {
    return Vector2();
}

Vector2 Vector2::operator-(const Vector2 &vector2) const {
    return Vector2();
}

double Vector2::dot(const Vector2 &vector2) const {
    return 0;
}

Vector2 Vector2::operator*(double number) const {
    return Vector2();
}

Vector2 Vector2::operator/(double number) const {
    return Vector2();
}

double Vector2::sqrAbs() const {
    return 0;
}

double Vector2::abs() const {
    return 0;
}

Vector2 Vector2::normalized() const {
    return Vector2();
}

