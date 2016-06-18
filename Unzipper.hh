#ifndef UNZIPPER_HH
# define UNZIPPER_HH

# include <QThread>
# include <QMutex>
# include <QWaitCondition>

#include "ZippedBuffer.hh"
#include "ZippedBufferPool.hh"

class Unzipper : public QThread
{
private:
    const QString       m_destFolder;
    ZippedBufferPool*   m_zippedBufferPool;
    QWaitCondition*     m_waitCondition;
    QMutex              m_mutex;

public:
    Unzipper(const QString &destFolder, ZippedBufferPool *zippedBufferPool, QWaitCondition *waitCondition);

    void                unzip(const ZippedBuffer &zippedBuffer);

    // QThread interface
protected:
    void                run() Q_DECL_OVERRIDE;
};

#endif // UNZIPPER_HH
