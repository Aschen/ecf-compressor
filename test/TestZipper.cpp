#include "TestZipper.hh"

#include "../Zipper.hh"
#include "../ZippedBuffer.hh"
#include "../ZippedBufferPool.hh"
#include "../FilePool.hh"

TestZipper::TestZipper()
{   
}

void TestZipper::initTestCase()
{
    m_directories.append("folder_1/");

    // Create directories
    for (const QString &dirname : m_directories)
    {
        if ( ! QDir(dirname).exists())
            QDir().mkdir(dirname);
    }

    m_files.append("folder_1/file1.c");
    m_files.append("folder_1/file2.c");
    m_files.append("folder_1/file3.c");

    for (const QString &filename : m_files)
    {
        QFile   file(filename);

        if (file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&file);

            stream << filename << filename << filename;
        }
    }
}

void TestZipper::run()
{
    FilePool            filepool("folder_1/");
    ZippedBufferPool    zippedBufferPool;
    Zipper              zipper(&filepool, &zippedBufferPool);

    zipper.start();
    zipper.wait();

    QVERIFY2(filepool.count() == 0, "Zipper should consume all file in FilePool");
    QVERIFY2(zippedBufferPool.count() == 3, "Zipper should fill the ZippedBufferPool");
}

void TestZipper::createZippedBuffer()
{
    ZippedBuffer    zippedBuffer;
    Zipper          zipper;
    QString         filepath = m_files.front();
    QFile           file(filepath);
    bool            ret;

    file.open(QIODevice::ReadOnly);
    ret = zipper.createZippedBuffer(filepath, zippedBuffer);

    QVERIFY2(ret == true, "Error when openning file");
    QVERIFY2(zippedBuffer.filepath () == filepath, "Filepath should match");
    QVERIFY2(zippedBuffer.data() == qCompress(file.readAll()), "Compressed data should match");
}

void TestZipper::cleanupTestCase()
{
    // Delete directories
    for (const QString &dirname : m_directories)
    {
        QDir    dir(dirname);

        dir.removeRecursively();
    }
}

