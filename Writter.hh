#ifndef WRITTER_HH
# define WRITTER_HH

# include <QThread>
# include <QMutex>
# include <QWaitCondition>
# include <QFile>
# include <QDataStream>

class ZippedBuffer;
class ZippedBufferPool;

class Writter : public QThread
{
    Q_OBJECT
private:
    const QString           m_ecfFilename;
    ZippedBufferPool*       m_zippedBufferPool;
    QFile                   m_file;
    QDataStream             m_stream;
    QMutex                  m_mutex;
    QWaitCondition          m_waitCondition;

public:
    Writter(const QString& ecfFilename);
    Writter(const QString& ecfFilename, ZippedBufferPool* zippedBufferPool);
    ~Writter();

    // Public method so I can test it
    void                    writeZippedBuffer(ZippedBuffer& zippedBuffer);

    // QThread interface
protected:
    void                    run() Q_DECL_OVERRIDE;

private:
    void                    init();
};

#endif // WRITTER_HH
