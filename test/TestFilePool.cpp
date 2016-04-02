#include "TestFilePool.hh"

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

    QVERIFY(filepool.count() == 6);
}

void TestFilePool::tryGetFile()
{
    FilePool    filepool("folder_1/", "h");
    FilePool    emptyFilepool("folder_1/", "o");

    filepool.tryGetFile();

    QVERIFY(filepool.count() == 1);
    QVERIFY(emptyFilepool.tryGetFile() == "");
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

