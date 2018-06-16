//
// Created by Ales1098 on 16.06.2018.
//

#ifndef EGO_VECTOR_H
#define EGO_VECTOR_H


#include <iosfwd>
#include <cmath>
#include <iostream>

class Vector3D {
public:
    int x_cor, y_cor, z_cor;
private:
    Vector3D();
    Vector3D(int its_x, int its_y, int its_z);
    ~Vector3D();

    int get_length_from_center();
    int get_length_between_ends_two_vectors(const Vector3D & vector3D1, const Vector3D & vector3D2);
    int pow(int number);

    friend std::istream &operator>>(std::istream & is, Vector3D & vector3D);
    friend std::ostream &operator<<(std::ostream & os, Vector3D & vector3D);

    Vector3D &operator = (Vector3D & vector3D);

    friend Vector3D &operator+(const Vector3D & vector3D1, const Vector3D & vector3D2);
    Vector3D &operator+=(const Vector3D & vector3D);
    Vector3D &operator++();
    Vector3D &operator++(int);
    Vector3D &operator+(int &number);

    friend Vector3D &operator-(const Vector3D & vector3D1, const Vector3D & vector3D2);
    Vector3D &operator-=(const Vector3D & vector3D);
    Vector3D &operator--();
    Vector3D &operator--(int);
    Vector3D &operator-(int &number);

    friend Vector3D &operator*(const Vector3D & vector3D1, const Vector3D & vector3D2);
    Vector3D &operator*=(const Vector3D & vector3D);
    Vector3D &operator*(int &number);
    Vector3D &operator*(const Vector3D & vector3D);

    friend  Vector3D &operator^(const Vector3D & vector3D1, const Vector3D & vector3D2);
    Vector3D &operator^=(const Vector3D & vector3D);
    Vector3D &operator^(int &number);
    Vector3D &operator^(const Vector3D & vector3D);
};


#endif //EGO_VECTOR_H
