#include"Vector.h"
#include<math.h>
#include<iostream>

using namespace tracer;

Vector::Vector()
  : Tuple::Tuple(){}

Vector::Vector(double a, double b, double c)
  : Tuple::Tuple(a, b, c){}

Vector::Vector(double a, double b, double c, double d)
  : Tuple::Tuple(a, b, c, d){}

  Vector::Vector(const Vector& b)
  : Tuple::Tuple(b) {
      this->x = b.x;
      this->y = b.y;
      this->z = b.z;
      this->w = b.w;
    }

Vector Vector::operator*(const Vector& b)
  {
          Vector result = Vector();
          result.x = ((*this).y * b.z) - ((*this).z * b.y);
          result.y = ((*this).z * b.x) - ((*this).x * b.z);
          result.z = ((*this).x * b.y) - ((*this).y * b.x);
          result.w = 0;
          return result;
  }

  void Vector::print(){
    std::cout << std::endl << "< " << this->x << ", " << this->y
    << ", " << this->z << " >" << std::endl
    << std::endl;
  }

    double Vector::magnitude(){
      return sqrt((this->x * this->x) + (this->y * this->y)
      + (this->z * this->z));
  }

Vector Vector::normalize(){
  Vector result = Vector();
  double magnitude = (*this).magnitude();
  result.x = this->x / magnitude;
  result.y = this->y / magnitude;
  result.z = this->z / magnitude;
  return result;
}

double Vector::dot(Vector b){
  return ((this->x * b.x) + (this->y * b.y)
  + (this->z * b.z));
}
