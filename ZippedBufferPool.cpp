#include "ZippedBufferPool.hh"

#include "ZippedBuffer.hh"

ZippedBufferPool::ZippedBufferPool()
{
}

void ZippedBufferPool::put(const ZippedBuffer &zippedBuffer)
{
    QMutexLocker    locker(&m_mutex);

    m_zippedBuffers.push_back(zippedBuffer);
}

QPair<bool, ZippedBuffer> ZippedBufferPool::tryGet()
{
    QMutexLocker    locker(&m_mutex);
    QPair<bool, ZippedBuffer>   zippedBuffer(false, ZippedBuffer());

    if ( ! m_zippedBuffers.empty())
    {
        zippedBuffer.first = true;
        zippedBuffer.second = m_zippedBuffers.front();
        m_zippedBuffers.pop_front();
    }


    return zippedBuffer;
}

void ZippedBufferPool::done()
{

}

quint32 ZippedBufferPool::count()
{
    QMutexLocker    locker(&m_mutex);

    return m_zippedBuffers.size();
}

