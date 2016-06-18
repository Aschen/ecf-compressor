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
//    m_waitCondition->wait(&m_mutex);

    ZippedBuffer    zippedBuffer = m_zippedBufferPool->tryGet();

    while (m_zippedBufferPool->count () != 0)
    {
        if (zippedBuffer.valid())
        {
            unzip(zippedBuffer);
        }

        zippedBuffer = m_zippedBufferPool->tryGet();
    }

//    m_mutex.unlock();
    qDebug() << "QUIT";
}

void Unzipper::unzip(const ZippedBuffer &zippedBuffer)
{
    QDir            currentDir(".");
    QFileInfo       fileinfo(m_destFolder + currentDir.relativeFilePath(zippedBuffer.filepath()));

    if ( ! QDir(fileinfo.path()).exists())
        QDir().mkpath(fileinfo.path());

    QFile           file(fileinfo.filePath());
    qDebug() << "Unzip " << fileinfo.filePath();

    file.open(QIODevice::WriteOnly);
    file.write(qUncompress(zippedBuffer.data()));
    file.close();
}
