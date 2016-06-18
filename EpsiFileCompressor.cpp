#include "EpsiFileCompressor.hh"

#include "FilePool.hh"
#include "Zipper.hh"
#include "ZippedBuffer.hh"
#include "ZippedBufferPool.hh"
#include "Writter.hh"
#include "Unzipper.hh"

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
    QFile               ecfFile(ecfFilename);
    QByteArray          compressedData;
    QWaitCondition      waitCondition;
    ZippedBufferPool    zippedBufferPool(&waitCondition);
    Unzipper            unzipper1(destFolder, &zippedBufferPool, &waitCondition);
    Unzipper            unzipper2(destFolder, &zippedBufferPool, &waitCondition);

    unzipper1.start();
    unzipper2.start();

    ecfFile.open(QIODevice::ReadOnly);
    compressedData = ecfFile.readAll();

    QDataStream stream(compressedData);

    while ( ! stream.atEnd())
    {
        ZippedBuffer    zippedBuffer;
        stream >> zippedBuffer;
        zippedBufferPool.put(zippedBuffer);
    }

    zippedBufferPool.done(true);

    unzipper1.wait();
    unzipper2.wait();
}

