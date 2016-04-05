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

