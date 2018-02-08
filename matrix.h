#ifndef MATRIX
#define MATRIX

#include <vector>


// вспомогательный класс для храниния матрицы смежности графа
class Matrix {
public:
    Matrix() = default;

    Matrix(size_t size):
        size(size),
        matrix(size * size, 0)
    {}

    size_t getSize() const {
        return size;
    }

    int elem(size_t row, size_t col) const {
        return matrix[coordinateTransform(row, col)];
    }

    int & elem(size_t row, size_t col) {
        return matrix[coordinateTransform(row, col)];
    }

private:
    size_t coordinateTransform(size_t row, size_t col) const {
        return row * size + col;
    }

    size_t size = 0;
    std::vector<int> matrix;
};

#endif // MATRIX

