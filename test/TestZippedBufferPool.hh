#ifndef TESTZIPPEDBUFFERPOOL_HH
# define TESTZIPPEDBUFFERPOOL_HH

# include <QTest>
# include <QDebug>

class TestZippedBufferPool : public QObject
{
    Q_OBJECT

public:
    TestZippedBufferPool();

private slots:
    void        put();
    void        tryGet();
};

#endif // TESTZIPPEDBUFFERPOOL_HH
