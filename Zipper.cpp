#include "Zipper.hh"

#include "FilePool.hh"
#include "ZippedBuffer.hh"
#include "ZippedBufferPool.hh"

Zipper::Zipper(FilePool* filepool, ZippedBufferPool* zippedBufferPool)
    : m_filePool(filepool),
      m_zippedBufferPool(zippedBufferPool)
{
}

void Zipper::run()
{
    QString         filepath = m_filePool->tryGetFile();
    ZippedBuffer    zippedBuffer;

    while (filepath != "")
    {
        if (createZippedBuffer(filepath, zippedBuffer))
        {
            m_zippedBufferPool->put(zippedBuffer);
        }
        filepath = m_filePool->tryGetFile();
    }
}

bool Zipper::createZippedBuffer(const QString &filepath, ZippedBuffer &zippedBuffer) const
{
    QByteArray      formatedData;
    QDataStream     streamIn(&formatedData, QIODevice::ReadWrite);
    QByteArray      compressedData;
    QFile           file(filepath);

    // Assert this ?
    if ( ! file.open(QIODevice::ReadOnly))
        return false;

    compressedData = qCompress(file.readAll());
    file.close();

    streamIn << filepath << compressedData;
    QDataStream     streamOut(formatedData);
    streamOut >> zippedBuffer;


    return true;
}
