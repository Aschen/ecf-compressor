#include "ZippedBufferPool.hh"

#include "ZippedBuffer.hh"

ZippedBufferPool::ZippedBufferPool(QWaitCondition *waitCondition)
    : m_waitCondition(waitCondition)
{
}

void ZippedBufferPool::put(const ZippedBuffer &zippedBuffer)
{
    QMutexLocker    locker(&m_mutex);

    m_zippedBuffers.push_back(zippedBuffer);

    m_waitCondition->wakeOne();
}

ZippedBuffer ZippedBufferPool::tryGet()
{
    QMutexLocker    locker(&m_mutex);
    ZippedBuffer    zippedBuffer;

    if ( ! m_zippedBuffers.empty())
    {
        zippedBuffer = m_zippedBuffers.front();
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

