#include <QCoreApplication>
# include "ZippedBuffer.hh"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ZippedBuffer    zippedBuffer;
    QByteArray      formatedData;
    QDataStream     stream(&formatedData, QIODevice::ReadWrite);
    QString         filepath("test_dir/file.c");
    QByteArray      data;
    data.append("I'm the data bitch");
    stream << filepath << data;

    stream >> zippedBuffer;

    qDebug() << zippedBuffer.filepath () << zippedBuffer.data ();

    return a.exec();
}
