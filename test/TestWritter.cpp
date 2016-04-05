#include "TestWritter.hh"

#include "../Writter.hh"
#include "../ZippedBuffer.hh"
#include "../ZippedBufferPool.hh"

TestWritter::TestWritter()
{
}

void TestWritter::initTestCase()
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
            file.close();
        }
    }
}

void TestWritter::writeZippedBuffer()
{
    QString         ecfFilepath("compressed.ecf");
    QString         filepath("file1.c");
    QByteArray      data(QString("I'm the data bitch").toLocal8Bit());
    QByteArray      fileContent;

    writeZippedBufferHelper(filepath, data, ecfFilepath);

    QFile           file(ecfFilepath);
    file.open(QIODevice::ReadOnly);
    fileContent = file.readAll();
    file.close();
    QDataStream     stream(fileContent);
    ZippedBuffer    zippedBufferWitness;
    stream >> zippedBufferWitness;
    QDir().remove(ecfFilepath);

    QVERIFY2(zippedBufferWitness.filepath () == filepath, "Filepath from file should match original filepath");
    QVERIFY2(zippedBufferWitness.data() == data, "Data from file should match original data");
}

void TestWritter::cleanupTestCase()
{
    // Delete directories
    for (const QString &dirname : m_directories)
    {
        QDir    dir(dirname);

        dir.removeRecursively();
    }
}

void TestWritter::writeZippedBufferHelper(const QString& filepath, const QByteArray& data, const QString &ecfFilepath)
{
    Writter         writter(ecfFilepath);
    ZippedBuffer    zippedBuffer(filepath, data);

    writter.writeZippedBuffer(zippedBuffer);
}

