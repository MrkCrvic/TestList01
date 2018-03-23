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
    // index testing
    void testIndex();
    void testIndex_data();
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
    // char values of TemplateList
    QTest::addColumn<char>("char_list");
    QTest::addColumn<char>("char_expected");
    // QString values of TemplateList
    QTest::addColumn<QString>("stringList");
    QTest::addColumn<QString>("stringExpected");

    QList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(7);

    TemplateList<int> tempList(1);
    tempList.append(2);
    tempList.append(7);

    TemplateList<char> tempList2('a');
    tempList2.append('b');
    tempList2.append('f');

    TemplateList<QString> tempList3("ja");
    tempList3.append("sam");
    tempList3.append("Marko");

    QTest::newRow("first elem: ") << list1.at(0) << tempList.at(0) << "1" << tempList2.at(0) << 'a' << tempList3.at(0) << "ja";
    QTest::newRow("second elem: ") << list1.at(1) << tempList.at(1) << "2" << tempList2.at(1) << 'b' << tempList3.at(1) << "sam";
    QTest::newRow("third elem: ") << list1.at(2) << tempList.at(2) << "7" << tempList2.at(2) << 'f' << tempList3.at(2) << "Marko";

}

void TestList01Test::testAppendAt()
{
    // int fetch
    QFETCH(int, QList_values);
    QFETCH(int, TemplateList_values);
    QFETCH(QString, Expected_values);
    //char fetch
    QFETCH(char, char_list);
    QFETCH(char, char_expected);
    //QString fetch
    QFETCH(QString, stringList);
    QFETCH(QString, stringExpected);

    // int compare
    QCOMPARE(QList_values, TemplateList_values);
    QCOMPARE(QString::number(TemplateList_values), Expected_values);
    // char compare
    QCOMPARE(char_list, char_expected);
    // QString compare
    QCOMPARE(stringList, stringExpected);
}

void TestList01Test::testIndex_data()
{

    // int columns
    QTest::addColumn<int>("intList");
    // char columns
    QTest::addColumn<int>("charList");
    // QString columns
    QTest::addColumn<int>("stringList");
    // Expected
    QTest::addColumn<QString>("Expected");

    TemplateList<int> tempList1(1);
    tempList1.append(10);
    tempList1.append(100);

    TemplateList<char> tempList2('a');
    tempList2.append('m');
    tempList2.append('s');

    TemplateList<QString> tempList3("Ja");
    tempList3.append(" igram ");
    tempList3.append("tenis!\n");

    QTest::newRow("first row: ") << tempList1.index(100) << tempList2.index('s') << tempList3.index("tenis!\n") << "2";
    QTest::newRow("second row: ") << tempList1.index(1) << tempList2.index('a') << tempList3.index("Ja") << "0";
    QTest::newRow("third row: ") << tempList1.index(10) << tempList2.index('m') << tempList3.index(" igram ") << "1";

}

void TestList01Test::testIndex()
{
    QFETCH(int, intList);
    QFETCH(int, charList);
    QFETCH(int, stringList);
    QFETCH(QString, Expected);

    QCOMPARE(QString::number(intList), Expected);
    QCOMPARE(QString::number(charList), Expected);
    QCOMPARE(QString::number(stringList), Expected);

}

QTEST_APPLESS_MAIN(TestList01Test)

#include "tst_testlist01test.moc"
