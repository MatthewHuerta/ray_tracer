#ifndef TUPLE_H
#define TUPLE_H

namespace tracer{

class Tuple
{
public:
double x;
double y;
double z;
double w;

void print();

Tuple();
Tuple(double a, double b, double c);
Tuple(double a, double b, double c, double d);

Tuple operator+(const Tuple& b);

Tuple operator-(const Tuple& b);

Tuple operator/(double b);

Tuple negate() const;

Tuple scale(double);

};
}
#endif
