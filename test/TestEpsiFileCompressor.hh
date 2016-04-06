#ifndef TESTEPSIFILECOMPRESSOR_HH
# define TESTEPSIFILECOMPRESSOR_HH

# include <QTest>
# include <QStringList>
# include <QDir>
# include <QDebug>

class TestEpsiFileCompressor : public QObject
{
    Q_OBJECT

private:
    QStringList         m_directories;
    QStringList         m_files;

public:
    TestEpsiFileCompressor();

private slots:
    void    initTestCase();

    void    compressAndUncompress();

    void    cleanupTestCase();
};

#endif // TESTEPSIFILECOMPRESSOR_HH
