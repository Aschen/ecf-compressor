#ifndef TESTWRITTER_HH
# define TESTWRITTER_HH

# include <QTest>
# include <QDebug>
# include <QDir>
# include <QStringList>

class TestWritter : public QObject
{
    Q_OBJECT

private:
    QStringList         m_directories;
    QStringList         m_files;

public:
    TestWritter();

private slots:
    void        initTestCase();

    void        writeZippedBuffer();

    void        cleanupTestCase();

private:
    // Helper to create the file via Writter (need file to be closed before re-opening it)
    void        writeZippedBufferHelper(const QString &filepath, const QByteArray &data, const QString& ecfFilepath);
};

#endif // TESTWRITTER_HH
