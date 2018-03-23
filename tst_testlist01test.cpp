#include <QString>
#include <QtTest>
#include "templatelist.h"

class TestList01Test : public QObject
{
    Q_OBJECT

public:
    TestList01Test();

private Q_SLOTS:
    void testAppendAt();
    void testAppendAt_data();
};

TestList01Test::TestList01Test()
{
}

void TestList01Test::testAppendAt_data()
{

    // int values of TemplateList
    QTest::addColumn<int>("QList_values");
    QTest::addColumn<int>("TemplateList_values");
    QTest::addColumn<QString>("Expected_values");

    QList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(7);

    TemplateList<int> tempList(1);
    tempList.append(2);
    tempList.append(7);

    QTest::newRow("first elem: ") << list1.at(0) << tempList.at(0) << "1";
    QTest::newRow("second elem: ") << list1.at(1) << tempList.at(1) << "2";
    QTest::newRow("third elem: ") << list1.at(2) << tempList.at(2) << "7";

    // char values of TemplateList
    QTest::addColumn<char>("char_list");
    QTest::addColumn<char>("char_expected");

    TemplateList<char> tempList2('a');
    tempList2.append('b');
    tempList2.append('f');




}

void TestList01Test::testAppendAt()
{
    QFETCH(int, QList_values);
    QFETCH(int, TemplateList_values);
    QFETCH(QString, Expected_values);

    QCOMPARE(QList_values, TemplateList_values);
    //QCOMPARE(QString::number(TemplateList_values), Expected_values);
}

QTEST_APPLESS_MAIN(TestList01Test)

#include "tst_testlist01test.moc"
