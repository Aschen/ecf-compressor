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
    Writter             writter(ecfFilename, &zippedBufferPool, &waitCondition);

    zipper1.start();
    writter.start();

    zipper1.wait();
    writter.wait();
}

void EpsiFileCompressor::uncompress(const QString &ecfFilename, const QString &folder)
{
    QDir        currentDir(".");
    QFile       ecfFile(ecfFilename);
    QByteArray  compressedData;

    if ( ! QDir(folder).exists())
        QDir().mkdir(folder);

    ecfFile.open(QIODevice::ReadOnly);
    compressedData = ecfFile.readAll();

    QDataStream stream(compressedData);

    while ( ! stream.atEnd())
    {
        ZippedBuffer    zippedBuffer;
        stream >> zippedBuffer;

        // Add folder here
        QString         filepath = currentDir.relativeFilePath(zippedBuffer.filepath());
        QFile           file(filepath);
        file.open(QIODevice::WriteOnly);

        QDataStream     fileStream(&file);
        fileStream << qUncompress(zippedBuffer.data());
        file.close();
    }
}

