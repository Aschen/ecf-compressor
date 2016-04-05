#ifndef TESTZIPPER_HH
# define TESTZIPPER_HH

# include <QTest>
# include <QDebug>
# include <QDir>
# include <QStringList>

class TestZipper : public QObject
{
    Q_OBJECT

private:
    QStringList         m_directories;
    QStringList         m_files;

public:
    TestZipper();

private slots:
    void        initTestCase();

    void        run();
    void        createZippedBuffer();

    void        cleanupTestCase();
};

#endif // TESTZIPPER_HH
