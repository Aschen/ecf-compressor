# include <QtTest/QTest>
# include "TestFilePool.hh"
# include "TestZippedBuffer.hh"
# include "TestZippedBufferPool.hh"
# include "TestZipper.hh"
# include "TestWritter.hh"
# include "TestEpsiFileCompressor.hh"

int main()
{
  TestFilePool filepool;
  TestZippedBuffer zippedbuffer;
  TestZippedBufferPool zippedbufferpool;
  TestZipper zipper;
  TestWritter writter;
  TestEpsiFileCompressor compressor;

  QTest::qExec(&filepool);
  QTest::qExec(&zippedbuffer);
  QTest::qExec(&zippedbufferpool);
  QTest::qExec(&zipper);
  QTest::qExec(&writter);
  QTest::qExec(&compressor);

  return 0;
}
