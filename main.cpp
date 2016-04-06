#include <QCoreApplication>
#include <QDebug>

#include "EpsiFileCompressor.hh"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    EpsiFileCompressor  fileCompressor;

    fileCompressor.compress("tmp/", "compressed.ecf");

    qDebug() << "Compress files done.";

    fileCompressor.uncompress("compressed.ecf", "tmp_dest/");

    qDebug() << "Uncompress files done.";

    return 0;
}
