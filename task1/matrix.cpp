#include "matrix.hpp"
#include <stdexcept>

Matrix::Matrix(int numRows, int numCols) {
    Reset(numRows, numCols);
}

void Matrix::Reset(int numRows, int numCols) {
    if (numRows == 0 || numCols == 0) {
        w = h = 0;
        data.clear();
        return;
    }

    w = numCols;
    h = numRows;
    data.resize(h);
    for (auto& row : data) {
        row.resize(w);
        row.assign(w, 0);
    }
}

int& Matrix::At(int row, int col) {
    if (row < 0 || row >= h || col < 0 || col >= w) {
        throw std::out_of_range("`row` or `col` arguments are out of matrix size");
    }
    return data[row][col];
}

const int& Matrix::At(int row, int col) const {
    if (row < 0 || row >= h || col < 0 || col >= w) {
        throw std::out_of_range("`row` or `col` arguments are out of matrix size");
    }
    return data[row][col];
}

int Matrix::GetRows() const { return h; }

int Matrix::GetCols() const { return w; }

bool Matrix::operator==(const Matrix& m2) {
    if (w != m2.w || h != m2.h) {
        return false;
    }

    return data == m2.data;
}

bool Matrix::operator!=(const Matrix& m2) {
    return !(*this == m2);
}

Matrix Matrix::operator+(const Matrix& m2) {
    if (w != m2.w || h != m2.h) {
        throw std::invalid_argument("Matrices have different dimensions");
    }
    
    Matrix result(h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            result.At(i, j) = At(i, j) + m2.At(i, j);
        }
    }

    return result;
}
