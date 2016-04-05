#include "TestZippedBufferPool.hh"

#include "../ZippedBufferPool.hh"
#include "../ZippedBuffer.hh"

TestZippedBufferPool::TestZippedBufferPool()
{
}

void TestZippedBufferPool::put()
{
    ZippedBufferPool    pool;

    pool.put(ZippedBuffer());
    pool.put(ZippedBuffer());
    pool.put(ZippedBuffer());

    QVERIFY2(pool.count() == 3, "Error when putting ZippedBuffer in pool");
}

void TestZippedBufferPool::tryGet()
{
    ZippedBufferPool    pool;

    pool.put(ZippedBuffer("Buf1"));
    pool.put(ZippedBuffer("Buf2"));
    QPair<bool, ZippedBuffer>   pair = pool.tryGet();
    pool.tryGet();

    QVERIFY2(pair.first == true, "ZipperBuffer should be valid");
    QVERIFY2(pair.second.filepath() == "Buf1", "Error in ZippedBuffer order in pool");
    QVERIFY2(pool.tryGet().first == false, "ZippedBuffer should be false");
}

