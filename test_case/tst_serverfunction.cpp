#include <QtTest>
#include <vector>
#include <../server/tasks.cpp>

// add necessary includes here

class serverfunction : public QObject
{
    Q_OBJECT

public:
    serverfunction();
    ~serverfunction();

private slots:
    void test_case_task1();
    void test_case_task2();
    void test_case_task3();
};

serverfunction::serverfunction() {

}

serverfunction::~serverfunction() {

}

void serverfunction::test_case_task1() {
    std::vector<bool> input =  {0, 0, 1, 1, 0};
    QVERIFY(isLinear(input) == false);

}

void serverfunction::test_case_task2() {
    std::vector<bool> input =  {1, 1, 1, 1, 0, 0, 1, 0, 1, 0};
    QVERIFY(isMonotone(input) == false);

}

void serverfunction::test_case_task3() {
    std::vector<bool> input =  {0, 1, 0, 0, 1};
    QVERIFY(isSelfDual(input) == true);
}

QTEST_APPLESS_MAIN(serverfunction)

#include "tst_serverfunction.moc"
