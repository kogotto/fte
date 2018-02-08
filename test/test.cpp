#include "test.h"

#include "matrix.h"
#include "graphbase.h"
#include "stringgraph.h"

Q_DECLARE_METATYPE(Matrix);
Q_DECLARE_METATYPE(std::string);

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

void Test::testGraphBaseSymetricEdges()
{
    QFETCH(size_t, vertexCount);
    QFETCH(size_t, left);
    QFETCH(size_t, right);

    GraphBase graph(vertexCount);
    graph.setEdge(left, right);

    QVERIFY2(graph.hasEdge(right, left),
             "not oriented graph must have edge for switched left and right");
}

void Test::testGraphBaseSymetricEdges_data()
{
    QTest::addColumn<size_t>("vertexCount");
    QTest::addColumn<size_t>("left");
    QTest::addColumn<size_t>("right");

    QTest::newRow("some test 1") << 3u << 0u << 1u;
    QTest::newRow("some test 2") << 3u << 0u << 2u;
    QTest::newRow("some test 3") << 3u << 1u << 2u;
}

void Test::testGraphBaseFindPath()
{
    GraphBase graph(4u);
    graph.setEdge(0u, 1u);
    graph.setEdge(1u, 2u);
    graph.setEdge(2u, 3u);
    graph.setEdge(3u, 0u);

    const auto path = graph.findPath(0, 2);
    const auto pathSize = path.size();

    QCOMPARE(pathSize, 3u);

    for (size_t i = 0; i < pathSize - 1; ++i) {
        QVERIFY2(graph.hasEdge(path[i], path[i + 1]),
                "adjacent vertexes in path must has edge");
    }
}

void Test::testOnlyOneMiss()
{
    QFETCH(std::string, left);
    QFETCH(std::string, right);
    QFETCH(bool, result);

    QCOMPARE(onlyOneMiss(left, right), result);
}

void Test::testOnlyOneMiss_data()
{
    QTest::addColumn<std::string>("left");
    QTest::addColumn<std::string>("right");
    QTest::addColumn<bool>("result");

    QTest::newRow("one miss 1") << std::string("bear")
                                << std::string("beer")
                                << true;
    QTest::newRow("one miss 2") << std::string("toy")
                                << std::string("boy")
                                << true;
    QTest::newRow("one miss 3") << std::string("me")
                                << std::string("my")
                                << true;
    QTest::newRow("one miss 4") << std::string("fuck")   // :D
                                << std::string("suck")
                                << true;

    QTest::newRow("equal 1") << std::string("123")
                             << std::string("123")
                             << false;
    QTest::newRow("equal 2") << std::string("cow")
                             << std::string("cow")
                             << false;
    QTest::newRow("equal 3") << std::string("fly")
                             << std::string("fly")
                             << false;
    QTest::newRow("equal 4") << std::string("elefant")
                             << std::string("elefant")
                             << false;

    QTest::newRow("more than one 1") << std::string("1234")
                                     << std::string("5678")
                                     << false;
    QTest::newRow("more than one 4") << std::string("beer")
                                     << std::string("four")
                                     << false;
    QTest::newRow("more than one 4") << std::string("as")
                                     << std::string("me")
                                     << false;
    QTest::newRow("more than one 4") << std::string("abstraction")
                                     << std::string("incapsulati")
                                     << false;
}

void Test::testToGraph()
{
    const Dictionary dictionary{ "toy",
                                 "boy",
                                 "bot" };
    const auto graph = toGraph(dictionary);

    QVERIFY2(graph.hasEdge(0u, 1u), "toy-boy edge");
    QVERIFY2(graph.hasEdge(1u, 0u), "toy-boy edge");
    QVERIFY2(!graph.hasEdge(0u, 2u), "toy-bot without edge");
    QVERIFY2(!graph.hasEdge(2u, 0u), "toy-bot without edge");
    QVERIFY2(graph.hasEdge(1u, 2u), "boy-bot edge");
    QVERIFY2(graph.hasEdge(2u, 1u), "boy-bot edge");
}

