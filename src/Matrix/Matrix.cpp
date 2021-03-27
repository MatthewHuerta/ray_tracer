#include"Matrix.h"
#include<iostream>

using namespace tracer;

//double Matrix::operator()(const unsigned short& a, const unsigned short& b){
//    return this->matrix[a][b];
//}
Matrix::Row& Matrix::operator[](int i) {
    Row* r = new Row(this, i);
    return *r;
}

Matrix::Matrix() {
    x = 0;
    y = 0;
    size = 0;
}

Matrix::Matrix(unsigned short a, unsigned short b) {
    x = a;
    y = b;
    size = a*b;
}

Matrix::Matrix(unsigned short a, unsigned short b, double val) {
    x = a;
    y = b;
    size = a*b;
    for (int j = 0; j < this->y; j++) {
        for (int i = 0; i < this->x; i++) {
            this->matrix[i][j] = val;
        }
    }
}

void Matrix::print() {

        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            if(i%x == x-1)
                std::cout << matrix[i%x][i/y] << '\n';
            else
                std::cout << *(*( matrix + i%x) + i/y) << ' ';
        }
}

    Matrix::Row::Row(Matrix* mat, int row){
        m = mat;
        this_row = row;
    };
    double& Matrix::Row::operator[](int i) const{
        double *res = &(m->matrix[this_row][i]);
        delete(this);
        return *res;
    }
