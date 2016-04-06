#include "TestEpsiFileCompressor.hh"

#include "../EpsiFileCompressor.hh"

TestEpsiFileCompressor::TestEpsiFileCompressor()
{
}

void TestEpsiFileCompressor::initTestCase()
{
    m_directories.append("folder_1/");
    m_directories.append("folder_2/");
    m_directories.append("folder_3/");

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
            file.close();
        }
    }
}

void TestEpsiFileCompressor::compressAndUncompress()
{
    EpsiFileCompressor      compressor;

    compressor.compress(m_directories.front(), "folder_2/compressed.ecf");
    compressor.uncompress("folder_2/compressed.ecf", "folder_3/");
    QFile   file11("folder_1/file1.c");
    QFile   file13("folder_1/file3.c");
    QFile   file31("folder_3/file1.c");
    QFile   file33("folder_3/file3.c");
    file11.open (QIODevice::ReadOnly);
    file13.open (QIODevice::ReadOnly);
    file31.open (QIODevice::ReadOnly);
    file33.open (QIODevice::ReadOnly);

//    QVERIFY2(file11.readAll () == file31.readAll (), "File content of first files should match");
//    QVERIFY2(file31.readAll () == file33.readAll (), "File content of last files should match");
}

void TestEpsiFileCompressor::cleanupTestCase()
{
    // Delete directories
    for (const QString &dirname : m_directories)
    {
        QDir    dir(dirname);

        dir.removeRecursively();
    }
}

