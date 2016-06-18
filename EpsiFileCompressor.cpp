#include "EpsiFileCompressor.hh"

#include "FilePool.hh"
#include "Zipper.hh"
#include "ZippedBuffer.hh"
#include "ZippedBufferPool.hh"
#include "Writter.hh"

EpsiFileCompressor::EpsiFileCompressor()
{
}

void EpsiFileCompressor::compress(const QString &folder, const QString &ecfFilename)
{
    QWaitCondition      waitCondition;

    FilePool            filepool(folder);
    ZippedBufferPool    zippedBufferPool(&waitCondition);
    Zipper              zipper1(&filepool, &zippedBufferPool);
    Zipper              zipper2(&filepool, &zippedBufferPool);
    Writter             writter(ecfFilename, &zippedBufferPool, &waitCondition);

    zipper1.start();
    zipper2.start();
    writter.start();

    zipper1.wait();
    zipper2.wait();

    zippedBufferPool.done(true);

    writter.wait();
}

void EpsiFileCompressor::uncompress(const QString &ecfFilename, const QString &destFolder)
{
    QDir                currentDir(".");
    QFile               ecfFile(ecfFilename);
    QByteArray          compressedData;
    QWaitCondition      waitCondition;
    ZippedBufferPool    zippedBufferPool(&waitCondition);

    ecfFile.open(QIODevice::ReadOnly);
    compressedData = ecfFile.readAll();

    QDataStream stream(compressedData);

    while ( ! stream.atEnd())
    {
        ZippedBuffer    zippedBuffer;
        stream >> zippedBuffer;
        zippedBufferPool.put(zippedBuffer);
    }
}
