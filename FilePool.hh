#ifndef FILEPOOL_HH
# define FILEPOOL_HH

# include <QStringList>
# include <QDir>
# include <QMutex>

class FilePool
{
private:
    const QString       m_folder;
    const QString       m_extension;
    QStringList         m_files;
    QMutex              m_mutex;

public:
    FilePool(const QString &folder, const QString &extension);

    quint32             count();
    const QStringList   &files() const;
    QString             tryGetFile();

private:
    void        fillPool(const QString &folder);

};

#endif // FILEPOOL_HH
