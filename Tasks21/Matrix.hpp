#ifndef MATRIX
#define MATRIX

#include <iostream>

template<class Type>
class Matrix {
private:
    unsigned n;
    unsigned m;
    Type **data;
public:
    Matrix(unsigned n, unsigned m) {
        this->n = n;
        this->m = m;
        this->data = new Type*[n];
        for(unsigned i = 0; i < n; i++)
            this->data[i] = new Type[m];
    }
    unsigned rows() {
        return this->n;
    }
    unsigned columns() {
        return this->m;
    }
    Type& at(unsigned i, unsigned j) {
        return this->data[i][j];
    }
    ~Matrix() {
        for(unsigned i = 0; i < this->n; i++)
            delete[] this->data[i];
        delete[] this->data;
    }
};

#endif //MATRIX