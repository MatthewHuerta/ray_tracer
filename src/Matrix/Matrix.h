#ifndef RAY_TRACER_MATRIX_H
#define RAY_TRACER_MATRIX_H

#include "Tuple.h"

namespace tracer {
    class Matrix {
        struct Row{
            Matrix* m;
            int this_row;
            explicit Row(Matrix* mat, const int& row);
            double& operator[](const int& i) const;
        };
    public:
        unsigned short x;
        unsigned short y;
        unsigned short size;
        double matrix[4][4] = {0};
//        double operator()(const unsigned short& x, const unsigned short& y);
        Row& operator[](const int&);
        bool operator==(const Matrix&) const;
        bool operator!=(const Matrix&) const;
        Matrix operator*(const Matrix&) const;
        Tuple operator*(const Tuple&) const;
        Matrix& operator=(double m[4][4]);
        Matrix();
        Matrix(unsigned short x, unsigned short y);
        Matrix(unsigned short x, unsigned short y, double val);
        explicit Matrix(char);
        [[nodiscard]] Matrix t() const;
        void print();
        Matrix sub(short, short);
    };
}

#endif //RAY_TRACER_MATRIX_H
