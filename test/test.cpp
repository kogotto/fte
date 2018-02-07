#include "test.h"

#include "matrix.h"

Q_DECLARE_METATYPE(Matrix);

Test::Test()
{
}

void Test::testMatrixSize()
{
    QFETCH(Matrix, matrix);
    QFETCH(size_t, size);

    QCOMPARE(matrix.size(), size);
}

void Test::testMatrixSize_data()
{
    QTest::addColumn<Matrix>("matrix");
    QTest::addColumn<size_t>("size");

    QTest::newRow("size = 3") << Matrix(3u) << 3u;
    QTest::newRow("size = 4") << Matrix(4u) << 4u;
    QTest::newRow("size = 400") << Matrix(400u) << 400u;
}

void Test::testMatrixAccess()
{
    constexpr size_t size = 5;
    constexpr int magicNumber = 2;
    Matrix matrix(size);
    const Matrix & constRef = matrix;

    for (size_t row = 0; row < size; row += 2) {
        for (size_t col = 0; col < size; col += 2) {
            matrix.elem(row, col) = magicNumber;
        }
    }

    for (size_t row = 0; row < size; ++row) {
        for (size_t col = 0; col < size; ++col) {
            if (row % 2 == 0 && col % 2 == 0) {
                QCOMPARE(constRef.elem(row, col), magicNumber);
            } else {
                QCOMPARE(constRef.elem(row, col), 0);
            }
        }
    }
}


