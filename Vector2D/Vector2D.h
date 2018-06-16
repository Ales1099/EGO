//
// Created by Ales1098 on 17.06.2018.
//

#ifndef EGO_VECTOR2D_H
#define EGO_VECTOR2D_H

#include <iostream>
#include <cmath>

class Vector2D {
private:
    int x_cor, y_cor;
public:

    Vector2D();
    Vector2D(int its_x, int its_y);
    ~Vector2D();

    int get_length_from_center();
    int get_length_from_two_vectors(const Vector2D & vector2D1, const Vector2D & vector2D2);
    int pow(int number);

    friend std::istream &operator>>(std::istream & is, Vector2D & vector2D);
    friend std::ostream &operator<<(std::ostream & os, Vector2D & vector2D);

    Vector2D &operator = (Vector2D & vector2D);

    friend Vector2D &operator+(const Vector2D & vector2D1, const Vector2D & vector2D2);
    Vector2D &operator+=(const Vector2D & vector2D);
    Vector2D &operator++();
    Vector2D &operator++(int);
    Vector2D &operator+(int &number);

    friend Vector2D &operator-(const Vector2D & vector2D1, const Vector2D & vector2D2);
    Vector2D &operator-=(const Vector2D & vector2D);
    Vector2D &operator--();
    Vector2D &operator--(int);
    Vector2D &operator-(int &number);

    friend Vector2D &operator*(const Vector2D & vector2D1, const Vector2D & vector2D2);
    Vector2D &operator*=(const Vector2D & vector2D);
    Vector2D &operator*(int &number);
    Vector2D &operator*(const Vector2D & vector2D);

    friend  Vector2D &operator^(const Vector2D & vector2D1, const Vector2D & vector2D2);
    Vector2D &operator^=(const Vector2D & vector2D);
    Vector2D &operator^(int &number);
    Vector2D &operator^(const Vector2D & vector2D);

};


#endif //EGO_VECTOR2D_H
