#include "TestZippedBufferPool.hh"

#include "../ZippedBufferPool.hh"
#include "../ZippedBuffer.hh"

TestZippedBufferPool::TestZippedBufferPool()
{
}

void TestZippedBufferPool::put()
{
    ZippedBufferPool    pool(nullptr);

    pool.put(ZippedBuffer());
    pool.put(ZippedBuffer());
    pool.put(ZippedBuffer());

    QVERIFY2(pool.count() == 3, "Error when putting ZippedBuffer in pool");
}

void TestZippedBufferPool::tryGet()
{
    ZippedBufferPool    pool(nullptr);

    pool.put(ZippedBuffer("Buf1", QByteArray()));
    pool.put(ZippedBuffer("Buf2", QByteArray()));
    ZippedBuffer    zippedBuffer = pool.tryGet();
    pool.tryGet();

    QVERIFY2(zippedBuffer.valid() == true, "ZipperBuffer should be valid");
    QVERIFY2(zippedBuffer.filepath() == "Buf1", "Error in ZippedBuffer order in pool");
    QVERIFY2(pool.tryGet().valid() == false, "ZippedBuffer should be false");
}

