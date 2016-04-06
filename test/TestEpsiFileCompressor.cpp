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

void TestEpsiFileCompressor::compress()
{
    EpsiFileCompressor      compressor;

    compressor.compress(m_directories.front(), "folder_2/compressed.ecf");
}

void TestEpsiFileCompressor::uncompress()
{
    EpsiFileCompressor      compressor;

    compressor.uncompress("folder_2/compressed.ecf", "folder_3/");
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

