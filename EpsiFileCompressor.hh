#ifndef EPSIFILECOMPRESSOR_HH
# define EPSIFILECOMPRESSOR_HH

# include <QMutex>
# include <QWaitCondition>

class FilePool;
class Zipper;
class ZippedBufferPool;
class Writter;

class EpsiFileCompressor
{
public:
    EpsiFileCompressor();

    void                compress(const QString& folder, const QString& ecfFilename);
};

#endif // EPSIFILECOMPRESSOR_HH
