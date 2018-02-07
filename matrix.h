#ifndef MATRIX
#define MATRIX

#include <vector>

class Matrix {
public:
    Matrix() = default;

    Matrix(size_t size):
        size_(size),
        matrix_(size * size, 0)
    {}

    size_t size() const {
        return size_;
    }

    int elem(size_t row, size_t col) const {
        return matrix_[coordinateTransform(row, col)];
    }

    int & elem(size_t row, size_t col) {
        return matrix_[coordinateTransform(row, col)];
    }

private:
    size_t coordinateTransform(size_t row, size_t col) const {
        return row * size_ + col;
    }

    size_t size_ = 0;
    std::vector<int> matrix_;
};

#endif // MATRIX

