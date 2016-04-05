# include <QtTest/QTest>
# include "TestFilePool.hh"
# include "TestZippedBuffer.hh"
# include "TestZippedBufferPool.hh"
# include "TestZipper.hh"
# include "TestWritter.hh"

int main()
{
  TestFilePool filepool;
  TestZippedBuffer zippedbuffer;
  TestZippedBufferPool zippedbufferpool;
  TestZipper zipper;
  TestWritter writter;

  QTest::qExec(&filepool);
  QTest::qExec(&zippedbuffer);
  QTest::qExec(&zippedbufferpool);
  QTest::qExec(&zipper);
  QTest::qExec(&writter);

  return 0;
}
