#include "Pixel.h"
#include<iostream>

using namespace tracer;

Pixel::Pixel()
  : Tuple::Tuple(){}


  Pixel::Pixel(double a, double b, double c)
    : Tuple::Tuple(a, b, c){}

    void Pixel::print(){
      std::cout << std::endl << "< " << this->x << ", " << this->y
      << ", " << this->z << " >" << std::endl
      << std::endl;
    }
