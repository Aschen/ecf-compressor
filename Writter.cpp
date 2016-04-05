#include "Writter.hh"

#include "ZippedBuffer.hh"
#include "ZippedBufferPool.hh"

Writter::Writter(const QString &ecfFilename)
    : m_ecfFilename(ecfFilename),
      m_file(m_ecfFilename)
{
    init();
}

Writter::Writter(const QString& ecfFilename, ZippedBufferPool* zippedBufferPool,
                 QWaitCondition *waitCondition)
    : m_ecfFilename(ecfFilename),
      m_zippedBufferPool(zippedBufferPool),
      m_file(m_ecfFilename),
      m_waitCondition(waitCondition)
{
    init();
}

void Writter::init()
{
    // Assert this ?
    m_file.open(QIODevice::WriteOnly);

    m_stream.setDevice(&m_file);
}

Writter::~Writter()
{
    if (m_file.isOpen())
        m_file.close();
}

void Writter::run()
{
    m_waitCondition->wait(&m_mutex);

    ZippedBuffer    zippedBuffer = m_zippedBufferPool->tryGet();

    while (zippedBuffer.valid())
    {
        qDebug() << "Write compressed file";
        m_stream << zippedBuffer;
        m_waitCondition->wait(&m_mutex);
        zippedBuffer = m_zippedBufferPool->tryGet();
    }
}

void Writter::writeZippedBuffer(ZippedBuffer& zippedBuffer)
{
    m_stream << zippedBuffer;
}
