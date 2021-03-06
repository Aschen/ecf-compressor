#ifndef TESTZIPPEDBUFFER_HH
# define TESTZIPPEDBUFFER_HH

# include <QTest>
# include <QDebug>

class TestZippedBuffer : public QObject
{
    Q_OBJECT

public:
    TestZippedBuffer();

private slots:
    void        read();
    void        rightChevron();
    void        write();
    void        leftChevron();
};

#endif // TESTZIPPEDBUFFER_HH
