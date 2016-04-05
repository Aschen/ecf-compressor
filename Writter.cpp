#include "Writter.hh"

#include "ZippedBuffer.hh"
#include "ZippedBufferPool.hh"

Writter::Writter(const QString &ecfFilename)
    : m_ecfFilename(ecfFilename),
      m_file(m_ecfFilename)
{
    init();
}

Writter::Writter(const QString& ecfFilename, ZippedBufferPool* zippedBufferPool)
    : m_ecfFilename(ecfFilename),
      m_zippedBufferPool(zippedBufferPool),
      m_file(m_ecfFilename)
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
    ZippedBuffer    zippedBuffer = m_zippedBufferPool->tryGet();

    while (zippedBuffer.valid())
    {
        m_stream << zippedBuffer;
        zippedBuffer = m_zippedBufferPool->tryGet();
    }
}

void Writter::writeZippedBuffer(ZippedBuffer& zippedBuffer)
{
    m_stream << zippedBuffer;
}