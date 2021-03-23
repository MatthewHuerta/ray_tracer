
#include "Tuple.h"
#include <iostream>
#include <math.h>

using namespace tracer;

void tracer::Tuple::print(){
        std::cout << std::endl << "< " << this->x << ", " << this->y
                  << ", " << this->z << ", " << this->w << " >" << std::endl
                  << std::endl;
}

Tuple::Tuple(){ //called by Point::Point() and Vector::Vector()
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 0;
}
Tuple::Tuple(double a, double b, double c){
        x = a;
        y = b;
        z = c;
        w = 0;
}
Tuple::Tuple(double a, double b, double c, double d){
        x = a;
        y = b;
        z = c;
        w = d;
}


Tuple Tuple::operator+(const Tuple& b) {
        Tuple result = Tuple();
        result.x = (*this).x + b.x;
        result.y = (*this).y + b.y;
        result.z = (*this).z + b.z;
        result.w = (*this).w + b.w;
        return result;
}



Tuple Tuple::operator-(const Tuple& b) {
        Tuple result = Tuple();
        result.x = (*this).x - b.x;
        result.y = (*this).y - b.y;
        result.z = (*this).z - b.z;
        result.w = (*this).w - b.w;
        return result;
}

Tuple Tuple::operator/(const double& b) {
        Tuple result = Tuple();
        result.x = (*this).x / b;
        result.y = (*this).y / b;
        result.z = (*this).z / b;
        result.w = (*this).w / b;
        return result;
}

Tuple Tuple::negate() const {
        Tuple result = Tuple();
        result.x = 0.0 - this->x;
        result.y = 0.0 - this->y;
        result.z = 0.0 - this->z;
        result.w = 0.0 - this->w;
        return result;
}

Tuple Tuple::scale(const double& a){
        Tuple result = Tuple();
        result.x = this->x * a;
        result.y = this->y * a;
        result.z = this->z * a;
        result.w = this->w * a;
        return result;
}
