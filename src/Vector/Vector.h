
#ifndef VECTOR_H
#define VECTOR_H
#include<Tuple.h>

namespace tracer{

class Vector : public Tuple{
public:

Vector();

Vector(double a, double b, double c);

Vector(double a, double b, double c, double d);
Vector(const Vector& b);

Vector operator*(const Vector& b); //Cross-product

void print();

double magnitude();

Vector normalize();

double dot(Vector);

};
}
#endif
