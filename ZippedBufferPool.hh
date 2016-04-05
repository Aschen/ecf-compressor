#ifndef ZIPPEDBUFFERPOOL_HH
# define ZIPPEDBUFFERPOOL_HH

# include <QPair>
# include <QQueue>
# include <QMutex>
# include <QWaitCondition>

class ZippedBuffer;

class ZippedBufferPool
{
private:
    QQueue<ZippedBuffer>        m_zippedBuffers;
    QMutex                      m_mutex;
    QWaitCondition*             m_waitCondition;

public:
    ZippedBufferPool(QWaitCondition* waitCondition);

    void                        put(const ZippedBuffer &zippedBuffer);
    ZippedBuffer                tryGet();
    void                        done();

    quint32                     count();
};

#endif // ZIPPEDBUFFERPOOL_HH
