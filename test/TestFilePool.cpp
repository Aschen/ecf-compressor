#include "TestFilePool.hh"

#include "../FilePool.hh"


TestFilePool::TestFilePool()
{

}

void TestFilePool::initTestCase()
{
    m_directories.append("folder_1");
    m_directories.append("folder_1/folder_1_1");

    // Create directories
    for (const QString &dirname : m_directories)
    {
        if ( ! QDir(dirname).exists())
            QDir().mkdir(dirname);
    }

    m_files.append("folder_1/file1.c");
    m_files.append("folder_1/file2.c");
    m_files.append("folder_1/file3.c");
    m_files.append("folder_1/file4.h");

    m_files.append("folder_1/folder_1_1/file11.c");
    m_files.append("folder_1/folder_1_1/file12.c");
    m_files.append("folder_1/folder_1_1/file13.c");
    m_files.append("folder_1/folder_1_1/file14.h");

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

void TestFilePool::fillPool()
{
    FilePool    filepool("folder_1/", "c");

    QVERIFY2(filepool.count() == 6, "Wrong number of files in filepool");
}

void TestFilePool::tryGetFile()
{
    FilePool    filepool("folder_1/", "h");
    FilePool    emptyFilepool("folder_1/", "o");

    filepool.tryGetFile();

    QVERIFY2(filepool.count() == 1, "File not removed from filepool");
    QVERIFY2(emptyFilepool.tryGetFile() == "", "Empty filepool don't return \"\"");
}

void TestFilePool::cleanupTestCase()
{
    // Delete directories
    for (const QString &dirname : m_directories)
    {
        QDir    dir(dirname);

        dir.removeRecursively();
    }
}

