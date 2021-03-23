#include "Point.h"
#include<iostream>
using namespace tracer;

Point::Point()
        : Tuple::Tuple(){
          this->w = 1;
}

Point::Point(double a, double b, double c)
        : Tuple::Tuple(a, b, c){
          this->w = 1;
}

void Point::print(){
  std::cout << std::endl << "< " << this->x << ", " << this->y
  << ", " << this->z << " >" << std::endl
  << std::endl;
}
