#ifndef TEST
#define TEST

#include <QString>
#include <QtTest>

class Test : public QObject
{
    Q_OBJECT

public:
    Test();

private Q_SLOTS:
    void testMatrixSize();
    void testMatrixSize_data();
    void testMatrixAccess();

    void testGraphBaseSymetricEdges();
    void testGraphBaseSymetricEdges_data();
    void testGraphBaseFindPath();

    void testOnlyOneMiss();
    void testOnlyOneMiss_data();

    void testToGraph();
};

#endif // TEST

