#include"Matrix.h"
#include<iostream>

using namespace tracer;

//double Matrix::operator()(const unsigned short& a, const unsigned short& b){
//    return this->matrix[a][b];
//}
Matrix::Row& Matrix::operator[](const int& i) {
    Row* r = new Row(this, i);
    return *r;
}
bool Matrix::operator== (const Matrix& m)const{
    if(this->x != m.x)
        return false;
    if(this->y != m.y)
        return false;
    for (int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            if (matrix[i][j] != m.matrix[i][j])
                return false;
        }
    }
    return true;
}

Matrix& Matrix::operator= (double m[4][4]){
    double k = 0;
        for(int j = 0; j < y; j++) {
            for (int i = 0; i < x; i++) {
               matrix[j][i] = m[j][i];
            }
        }
        return *this;
}

bool Matrix::operator!= (const Matrix& m) const{
return !(*this == m);
}

Matrix Matrix::operator*(const Matrix& other) const{
    Matrix m = Matrix(other.x, y);
    for(int a = 0; a < m.y; a++){
        for(int b = 0; b < m.x; b++){
            double sum = 0;
            for(int i = 0; i < x; i++){
                sum += matrix[a][i] * other.matrix[i][b];
            }
            m.matrix[a][b] = sum;
        }
    }
    return m;
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
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            matrix[i][j] = val;
        }
    }
}

void Matrix::print() {
    std::cout<<std::endl;
for(int a = 0; a < y; a++){
    for(int b = 0; b < x; b++){
        std::cout<< matrix[a][b] <<" ";
    }
    std::cout<<std::endl;
}
}


    Matrix::Row::Row(Matrix* mat, const int& row){
        m = mat;
        this_row = row;
    };
    double& Matrix::Row::operator[](const int& i) const{
        double *res = &(m->matrix[i][this_row]);
        delete(this);
        return *res;
    }
