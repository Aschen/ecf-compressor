# include <QtTest/QTest>
# include "TestFilePool.hh"
# include "TestZippedBuffer.hh"
# include "TestZippedBufferPool.hh"
# include "TestZipper.hh"

int main()
{
  TestFilePool filepool;
  TestZippedBuffer zippedbuffer;
  TestZippedBufferPool zippedbufferpool;
  TestZipper zipper;

  QTest::qExec(&filepool);
  QTest::qExec(&zippedbuffer);
  QTest::qExec(&zippedbufferpool);
  QTest::qExec(&zipper);

  return 0;
}
