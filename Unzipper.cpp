#include "Unzipper.hh"

#include <QFileInfo>
#include <QDir>

#include "ZippedBuffer.hh"

class ZippedBufferPool;

Unzipper::Unzipper(const QString &destFolder, ZippedBufferPool* zippedBufferPool,
                   QWaitCondition *waitCondition)
    : m_destFolder(destFolder),
      m_zippedBufferPool(zippedBufferPool),
      m_waitCondition(waitCondition)
{
}

void Unzipper::run()
{
    m_waitCondition->wait(&m_mutex);

    ZippedBuffer    zippedBuffer = m_zippedBufferPool->tryGet();

    while ( ! m_zippedBufferPool->done())
    {
        if (zippedBuffer.valid())
        {
            m_stream << zippedBuffer;
        }

        zippedBuffer = m_zippedBufferPool->tryGet();
    }
}

void Unzipper::unzip(const ZippedBuffer &zippedBuffer)
{
    QFileInfo       fileinfo(m_destFolder + currentDir.relativeFilePath(zippedBuffer.filepath()));

    if ( ! QDir(fileinfo.path()).exists())
        QDir().mkpath(fileinfo.path());

    QFile           file(fileinfo.filePath());
    file.open(QIODevice::WriteOnly);

    file.write(qUncompress(zippedBuffer.data()));

    file.close();
}
