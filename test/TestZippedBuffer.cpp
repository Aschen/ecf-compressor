#include "TestZippedBuffer.hh"

#include "../ZippedBuffer.hh"


TestZippedBuffer::TestZippedBuffer()
{

}

void TestZippedBuffer::read()
{
    ZippedBuffer    zippedBuffer;
    QByteArray      formatedData;
    QByteArray      data;
    QString         filepath("test_dir/file.c");
    QDataStream     stream(&formatedData, QIODevice::ReadWrite);

    data.append("I'm the data bitch");
    stream << filepath << data;

    stream >> zippedBuffer;

    qDebug() << zippedBuffer.filepath () << zippedBuffer.data ();
    QVERIFY2(zippedBuffer.filepath() == filepath, "Error when reading filepath from stream");
    QVERIFY2(zippedBuffer.data() == data, "Error when reading data from stream");
}

void TestZippedBuffer::write()
{
    QByteArray      data;
    QByteArray      data_out;
    QDataStream     stream(&data_out, QIODevice::ReadWrite);

    data.append("Hello");

    stream << data;

    QDataStream     stream2(data_out);

    stream2 >> data_out;
    qDebug() << data.toHex () << data_out.toHex ();
}

