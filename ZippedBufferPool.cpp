#include "ZippedBufferPool.hh"

#include "ZippedBuffer.hh"

ZippedBufferPool::ZippedBufferPool(QWaitCondition *waitCondition)
    : m_waitCondition(waitCondition),
      m_started(false)
{
}

void ZippedBufferPool::put(const ZippedBuffer &zippedBuffer)
{
    QMutexLocker    locker(&m_mutex);

    m_zippedBuffers.push_back(zippedBuffer);

    if (m_waitCondition && ! m_started)
    {
        m_waitCondition->wakeOne();
        m_started = true;
    }
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

void ZippedBufferPool::done(bool end)
{
    QMutexLocker    locker(&m_mutex);

    m_done = end;
}

bool ZippedBufferPool::done()
{
    QMutexLocker    locker(&m_mutex);

    return m_done;
}

quint32 ZippedBufferPool::count()
{
    QMutexLocker    locker(&m_mutex);

    return m_zippedBuffers.size();
}

