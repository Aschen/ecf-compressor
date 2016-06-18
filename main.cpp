#include <QCoreApplication>
#include <QDebug>

#include "EpsiFileCompressor.hh"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    EpsiFileCompressor  fileCompressor;

    fileCompressor.compress(".", "/tmp/ecf/compressed.ecf");

    qDebug() << "Compress files done.";

    fileCompressor.uncompress("/tmp/ecf/compressed.ecf", "/tmp/ecf/data/");

    qDebug() << "Uncompress files done.";

    return 0;
}
