#include"Matrix.h"
#include<iostream>
#include<cmath>


using namespace tracer;

void Matrix::except(unsigned int p, const std::string &function_name) {
    std::cout << "\u001b[31m ERROR: argument '\u001b[33m" << p << "\u001b[31m' in function \u001b[33m" << function_name
              << std::endl;
    throw std::runtime_error("\u001b[31m argument out of range \u001b[0m");
}

void Matrix::except_invert() {
    throw std::runtime_error("\u001b[31m ERROR: matrix is not invertable \u001b[0m");
}


Matrix::Row &Matrix::operator[](const int &i) {
    Row *r = new Row(this, i);
    return *r;
}

bool Matrix::operator==(const Matrix &m) const {
    if (this->x != m.x)
        return false;
    if (this->y != m.y)
        return false;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (matrix[i][j] != m.matrix[i][j])
                return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &m) const {
    return !(*this == m);
}

Matrix Matrix::operator*(const Matrix &other) const {
    Matrix m = Matrix(other.x, y);
    for (int a = 0; a < m.y; a++) {
        for (int b = 0; b < m.x; b++) {
            double sum = 0;
            for (int i = 0; i < x; i++) {
                sum += matrix[a][i] * other.matrix[i][b];
            }
            m.matrix[a][b] = sum;
        }
    }
    return m;
}

Tuple Matrix::operator*(const Tuple &t) const {
    Tuple r = Tuple();
    for (int a = 0; a < y; a++) {
        double sum = 0;
        for (int i = 0; i < x; i++) {
            sum += matrix[a][i] * t.t[i];
        }
        r.t[a] = sum;
    }
    return r;
}

Matrix::Matrix() {
    x = 0;
    y = 0;
}

Matrix::Matrix(unsigned short a, unsigned short b) {
    x = a;
    y = b;
}

Matrix::Matrix(unsigned short a, unsigned short b, double val) {
    x = a;
    y = b;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            matrix[i][j] = val;
        }
    }
}

Matrix::Matrix(char c) {
    x = 4;
    y = 4;
    if (c == 'i' || c == 'I') {
        for (int i = 0; i < 4; i++) {
            matrix[i][i] = 1;
        }
    }
}

Matrix::Matrix(const tracer::Matrix &M) {
    x = M.x;
    y = M.y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            matrix[j][i] = M.matrix[j][i];
        }
    }
}

void Matrix::print() {
    std::cout << std::endl;
    for (int a = 0; a < y; a++) {
        for (int b = 0; b < x; b++) {
            std::cout << matrix[a][b] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::transpose() const {
    Matrix m = Matrix(y, x);
    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++) {
            m.matrix[i][j] = matrix[j][i];
        }
    }
    return m;
}

Matrix Matrix::sub(unsigned Y, unsigned X) {
    try {
        if (X >= x) {
            Matrix::except(X, "Matrix::sub(X,Y)");
        } else if (Y >= y) {
            Matrix::except(Y, "Matrix::sub(X,Y)");
        }
    }
    catch (std::exception const &e) {
        std::cout << e.what() << '\n';
        exit(1);
    }
    Matrix m = Matrix(x - 1, y - 1);
    int A = 0;
    int B = 0;
    for (int a = 0; a < y; a++) {
        if (a == Y) {
            continue;
        }
        for (int b = 0; b < x; b++) {
            if (b == X) {
                continue;
            }
            m.matrix[A][B] = matrix[a][b];
            B++;
            if (B == m.x) {
                A++;
                B = 0;
            }
        }
    }
    return m;
}

double Matrix::det() {
    if (x == 2 && y == 2) {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    }
    double sum = 0;
    for (int X = 0; X < x; X++) {
        sum += matrix[0][X] * this->cofactor(0, X);
    }
    return sum;
}

double Matrix::cofactor(unsigned Y, unsigned X) {
    return (std::pow(-1, (X + Y + 2)) * sub(Y, X).det());
}

Matrix::Row::Row(Matrix *mat, const int &row) {
    m = mat;
    this_row = row;
};

double &Matrix::Row::operator[](const int &i) const {
    double *res = &(m->matrix[i][this_row]);
    delete (this);
    return *res;
}

Matrix Matrix::invert() {
    double d = this->det();
    try {
        if (d == 0) {
            Matrix::except_invert();
        }
    }
    catch (std::exception const &e) {
        std::cout << e.what() << '\n';
        exit(1);
    }
    Matrix I = Matrix(*this);
    for(unsigned short i = 0; i < y; i++){
        for(unsigned short j = 0; j < x; j++){
            I.matrix[i][j] = this->cofactor(i, j);
        }
    }
    I = I.transpose();

    for(unsigned short i = 0; i < y; i++){
        for(unsigned short j = 0; j < x; j++){
            I.matrix[i][j] = I.matrix[i][j] / d;
        }
    }

    return I;
}
