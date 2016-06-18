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
    bool                        m_done;

public:
    ZippedBufferPool(QWaitCondition* waitCondition);

    void                        put(const ZippedBuffer &zippedBuffer);
    ZippedBuffer                tryGet();

    void                        done(bool end);
    bool                        done();
    quint32                     count();
};

#endif // ZIPPEDBUFFERPOOL_HH
