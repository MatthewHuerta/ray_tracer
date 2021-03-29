#ifndef TUPLE_H
#define TUPLE_H

namespace tracer{

class Tuple
{
public:
    double t[4] = {0};
    double &x = t[0];
    double &y = t[1];
    double &z = t[2];
    double &w = t[3];

virtual void print();

Tuple();
Tuple(double a, double b, double c);
Tuple(double a, double b, double c, double d);

Tuple& operator=(const Tuple&);

Tuple operator+(const Tuple& b);

Tuple operator-(const Tuple& b);

Tuple operator/(const double& b);

[[nodiscard]] Tuple negate() const;

Tuple scale(const double&);

};
}
#endif
