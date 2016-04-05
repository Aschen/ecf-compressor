#ifndef ZIPPEDBUFFERPOOL_HH
# define ZIPPEDBUFFERPOOL_HH

# include <QPair>
# include <QQueue>
# include <QMutex>

class ZippedBuffer;

class ZippedBufferPool
{
private:
    QQueue<ZippedBuffer>        m_zippedBuffers;
    QMutex                      m_mutex;

public:
    ZippedBufferPool();

    void                        put(const ZippedBuffer &zippedBuffer);
    ZippedBuffer                tryGet();
    void                        done();

    quint32                     count();
};

#endif // ZIPPEDBUFFERPOOL_HH
