#ifndef TESTFILEPOOL_HH
# define TESTFILEPOOL_HH

# include <QTest>
# include <QStringList>
# include <QDir>
# include <QDebug>

# include "../FilePool.hh"

class TestFilePool : public QObject
{
    Q_OBJECT

private:
    QStringList         m_directories;
    QStringList         m_files;


public:
    TestFilePool();

private slots:
    void    initTestCase();

    void    fillPool();
    void    tryGetFile();

    void    cleanupTestCase();
};

#endif // TESTFILEPOOL_HH
