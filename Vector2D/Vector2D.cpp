//
// Created by Ales1098 on 17.06.2018.
//

#include "Vector2D.h"

Vector2D::Vector2D()
{
   this->x_cor=this->y_cor=1;
}

Vector2D::Vector2D(int its_x, int its_y):x_cor(its_x), y_cor(its_y) {}

Vector2D::~Vector2D()
{
    this->x_cor=this->y_cor=0;
}

int Vector2D::pow(int number)
{
    return  number*number;
}

int Vector2D::get_length_from_center()
{
    return sqrt(pow(this->x_cor)+pow(this->y_cor));
}

int Vector2D::get_length_from_two_vectors(const Vector2D &vector2D1, const Vector2D &vector2D2)
{
    return sqrt(pow(vector2D1.x_cor-vector2D2.x_cor)+pow(vector2D1.x_cor-vector2D2.y_cor));
}

std::istream &operator>>(std::istream & is, Vector2D & vector2D)
{
    std::cin>>vector2D.x_cor>>vector2D.y_cor;
    return is;
}

std::ostream &operator<<(std::ostream & os, Vector2D & vector2D)
{
    os<<vector2D.x_cor<<vector2D.y_cor;
    return os;
}

Vector2D &Vector2D::operator=(Vector2D &vector2D)
{
    this->x_cor=vector2D.x_cor;
    this->y_cor=vector2D.y_cor;
    return (*this);
}

