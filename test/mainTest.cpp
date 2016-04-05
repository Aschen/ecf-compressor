# include <QtTest/QTest>
# include "TestFilePool.hh"
# include "TestZippedBuffer.hh"
# include "TestZippedBufferPool.hh"

int main()
{
  TestFilePool filepool;
  TestZippedBuffer zippedbuffer;
  TestZippedBufferPool zippedbufferpool;

  QTest::qExec(&filepool);
  QTest::qExec(&zippedbuffer);
  QTest::qExec(&zippedbufferpool);

  return 0;
}
