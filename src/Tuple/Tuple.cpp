
#include "Tuple.h"
#include <iostream>
#include <math.h>

using namespace tracer;

void tracer::Tuple::print(){
        std::cout << std::endl << "< " << t[0] << ", " << t[1]
                  << ", " << t[2] << ", " << t[3] << " >" << std::endl
                  << std::endl;
}

Tuple::Tuple(){
    for(unsigned int i : t){
        t[i] = 0;
    }
}
Tuple::Tuple(double a, double b, double c){
        t[0] = a;
        t[1] = b;
        t[2] = c;
        t[3] = 0;
}
Tuple::Tuple(double a, double b, double c, double d){
    t[0] = a;
    t[1] = b;
    t[2] = c;
    t[3] = d;
}


Tuple Tuple::operator+(const Tuple& b) {
        Tuple result = Tuple();
        result.t[0] = (*this).x + b.x;
        result.t[1] = (*this).y + b.y;
        result.t[2] = (*this).z + b.z;
        result.t[3] = (*this).w + b.w;
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

Tuple& Tuple::operator=(const Tuple & T) {
    if (this == &T)
        return *this;

    t[0] = T.t[0];
    t[1] = T.t[1];
    t[2] = T.t[2];
    t[3] = T.t[3];
return *this;
}
