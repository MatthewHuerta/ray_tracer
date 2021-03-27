#ifndef RAY_TRACER_MATRIX_H
#define RAY_TRACER_MATRIX_H

namespace tracer {
    class Matrix {
        struct Row{
            Matrix* m;
            int this_row;
            explicit Row(Matrix* mat, int row);
            double& operator[](int i) const;
        };
    public:
        unsigned short x;
        unsigned short y;
        unsigned short size;
        double matrix[4][4] =
                {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
        };
//        double operator()(const unsigned short& x, const unsigned short& y);
        Row& operator[](int);
        Matrix();
        Matrix(unsigned short x, unsigned short y);
        Matrix(unsigned short x, unsigned short y, double val);
        void print();
    };
}

#endif //RAY_TRACER_MATRIX_H
