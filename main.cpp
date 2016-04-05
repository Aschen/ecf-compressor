#include <QCoreApplication>
#include <QDebug>

#include "EpsiFileCompressor.hh"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    EpsiFileCompressor  fileCompressor;

//    fileCompressor.compress("test/", "compressed.ecf");

    qDebug() << "Compress files done.";

    fileCompressor.uncompress("compressed.ecf", "test2/");

    qDebug() << "Uncompress files done.";

    return a.exec();
}
