#ifndef RAY_TRACER_MATRIX_H
#define RAY_TRACER_MATRIX_H

#include "Tuple.h"
#include<string>

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
        double matrix[4][4] = {0};
        Row& operator[](const int&);
        bool operator==(const Matrix&) const;
        bool operator!=(const Matrix&) const;
        Matrix operator*(const Matrix&) const;
        Tuple operator*(const Tuple&) const;
        template <int W, int H>
        Matrix& operator=(double const (&arr)[W][H]){
            x = H;
            y = W;
            for(int j = 0; j < W; j++) {
                for (int i = 0; i < H; i++) {
                    matrix[j][i] = arr[j][i];
                }
            }
            return *this;
        }
        Matrix();
        Matrix(unsigned short x, unsigned short y);
        Matrix(unsigned short x, unsigned short y, double val);
        explicit Matrix(char);
        Matrix(const Matrix&);
        [[nodiscard]] Matrix transpose() const;
        void print();
        Matrix sub(short, short);
        void except(unsigned int p, const std::string&);
    };
}

#endif //RAY_TRACER_MATRIX_H
