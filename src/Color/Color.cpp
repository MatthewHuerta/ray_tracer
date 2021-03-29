#include "Color.h"
#include <iostream>

using namespace tracer;

Color::Color()
        : Tuple::Tuple(){
}


Color::Color(double a, double b, double c)
        : Tuple::Tuple(a, b, c) {
}

Color::Color(const Color& b){
        x = b.x;
        y = b.y;
        z = b.z;
        w = b.w;
}

Color::Color(const Tuple& b){
        x = b.x;
        y = b.y;
        z = b.z;
        w = b.w;
}

bool Color::operator==(const Color& b)
{
        return ((x==b.x)&&(y==b.y)&&(z==b.z));
}


bool Color::operator!=(const Color& b)
{
        return !(*this == b);
}

Color Color::operator*(const Color& b)
{
        Color result = Color();
        result.x = ((*this).x * b.x);
        result.y = ((*this).y * b.y);
        result.z = ((*this).z * b.z);
        return result;
}

void Color::print(){
        std::cout << std::endl << "< " << this->x << ", " << this->y
                  << ", " << this->z << " >" << std::endl
                  << std::endl;
}


