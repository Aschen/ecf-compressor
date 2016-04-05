#ifndef EPSIFILECOMPRESSOR_HH
# define EPSIFILECOMPRESSOR_HH

# include <QMutex>
# include <QWaitCondition>
# include <QDir>

class FilePool;
class Zipper;
class ZippedBufferPool;
class Writter;

class EpsiFileCompressor
{
public:
    EpsiFileCompressor();

    void                compress(const QString &folder, const QString &ecfFilename);
    void                uncompress(const QString &ecfFilename, const QString &folder);
};

#endif // EPSIFILECOMPRESSOR_HH
