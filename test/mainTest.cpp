# include <QtTest/QTest>
# include "TestFilePool.hh"
# include "TestZippedBuffer.hh"

int main()
{
  TestFilePool filepool;
  TestZippedBuffer zippedbuffer;

  QTest::qExec(&filepool);
  QTest::qExec(&zippedbuffer);

  return 0;
}
