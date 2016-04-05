#ifndef ZIPPER_HH
# define ZIPPER_HH

# include <QThread>

class FilePool;
class ZippedBuffer;
class ZippedBufferPool;

class Zipper : public QThread
{
    Q_OBJECT

private:
    FilePool*            m_filePool;
    ZippedBufferPool*    m_zippedBufferPool;

public:
    Zipper(FilePool *filepool, ZippedBufferPool *zippedBufferPool);

    // Public method so i can test it..
    bool                createZippedBuffer(const QString& filepath,
                                           ZippedBuffer& zippedBuffer) const;

    // QThread interface
protected:
    void                run() Q_DECL_OVERRIDE;

};

#endif // ZIPPER_HH
