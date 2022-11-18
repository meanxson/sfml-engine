//
// Created by meanx on 09/11/2022.
//

#ifndef SFML_ENGINE_VECTOR2_H
#define SFML_ENGINE_VECTOR2_H

#include <array>
#include "Vector4.h"

class Vector2 final {
private:
    std::array<double, 2> m_point{};

    static bool is_near(double a, double b);

public:
    Vector2() = default;

    Vector2(const Vector2 &vector2);

    explicit Vector2(const Vector4 &point4);

    explicit Vector2(double x, double y = 0.0);

    Vector2 &operator=(const Vector2 &) = default;

    [[nodiscard]] double x() const { return m_point[0]; }

    [[nodiscard]] double y() const { return m_point[1]; }

    [[nodiscard]] Vector2 operator-() const;

    bool operator==(const Vector2 &vector2) const;

    bool operator!=(const Vector2 &vector2) const;

    [[nodiscard]] Vector2 operator+(const Vector2 &vector2) const;

    [[nodiscard]] Vector2 operator-(const Vector2 &vector2) const;

    [[nodiscard]] double dot(const Vector2 &vector2) const;

    [[nodiscard]] Vector2 operator*(double number) const;

    [[nodiscard]] Vector2 operator/(double number) const;

    [[ nodiscard]] double sqrAbs() const;

    [[nodiscard]] double abs() const;

    [[nodiscard]] Vector2 normalized() const;
};


#endif //SFML_ENGINE_VECTOR2_H
