#include "TestZippedBuffer.hh"

#include "../ZippedBuffer.hh"


TestZippedBuffer::TestZippedBuffer()
{

}

void TestZippedBuffer::read()
{
    ZippedBuffer    zippedBuffer;
    QByteArray      formatedData;
    QDataStream     stream(&formatedData, QIODevice::ReadWrite);
    QByteArray      data;
    data.append("I'm the data bitch");
    QString         filepath("test_dir/file.c");
    stream << filepath << data;
    QDataStream     stream2(formatedData);

    zippedBuffer.read(stream2);

    QVERIFY2(zippedBuffer.filepath() == filepath, "Error when reading filepath from stream");
    QVERIFY2(zippedBuffer.data() == data, "Error when reading data from stream");
}

void TestZippedBuffer::write()
{
    QByteArray      formatedData;
    QDataStream     stream(&formatedData, QIODevice::ReadWrite);
    ZippedBuffer    zippedBuffer;
    QByteArray      dataIn;
    dataIn.append("I'm the data bitch");
    QString         filepathIn("test_dir/file.c");
    zippedBuffer.data(dataIn);
    zippedBuffer.filepath(filepathIn);

    zippedBuffer.write(stream);
    QDataStream     stream2(formatedData);
    QByteArray      dataOut;
    QString         filepathOut;
    stream2 >> filepathOut >> dataOut;

    QVERIFY2(dataIn == dataOut, "Error when writting data to QDataStream");
    QVERIFY2(filepathIn == filepathOut, "Error when writting filepath to QDataStream");
}

