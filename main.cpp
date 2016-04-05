#include <QCoreApplication>

#include "EpsiFileCompressor.hh"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    EpsiFileCompressor  fileCompressor;

    fileCompressor.compress("test/", "compressed.ecf");

    return a.exec();
}
