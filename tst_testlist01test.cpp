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

QTEST_APPLESS_MAIN(TestList01Test)

#include "tst_testlist01test.moc"
