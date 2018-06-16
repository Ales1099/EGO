//
// Created by Ales1098 on 16.06.2018.
//

#include "Vector3D.h"

Vector3D::Vector3D()
{
   this->x_cor=this->y_cor=this->z_cor=1;
}

Vector3D::Vector3D(int its_x, int its_y, int its_z): x_cor(its_x), y_cor(its_y), z_cor(its_z) {}

Vector3D::~Vector3D()
{
    this->x_cor=this->y_cor=this->z_cor=0;
}

int Vector3D::get_length_from_center()
{
    return sqrt(pow(this->x_cor)+pow(this->y_cor)+pow(this->z_cor));
}

int Vector3D::pow(int number)
{
    return number*number;
}

int Vector3D::get_length_between_ends_two_vectors(const Vector3D &vector3D1, const Vector3D &vector3D2)
{
    return sqrt(pow(vector3D1.x_cor-vector3D2.x_cor)+ pow(vector3D1.y_cor-vector3D2.y_cor)+pow(vector3D1.z_cor-vector3D2.z_cor));
}

std::istream &operator>>(std::istream &is, Vector3D &vector3D)
{
    std::cin>>vector3D.x_cor>>vector3D.y_cor>>vector3D.z_cor;
    return is;
}

std::ostream &operator<<(std::ostream &os, Vector3D &vector3D)
{
    os<<vector3D.x_cor<<vector3D.y_cor<<vector3D.z_cor;
    return os;
}

Vector3D &Vector3D::operator=(Vector3D &vector3D)
{
    this->x_cor=vector3D.x_cor;
    this->y_cor=vector3D.y_cor;
    this->z_cor=vector3D.z_cor;
    return (*this);
}
