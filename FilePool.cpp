#include "FilePool.hh"

FilePool::FilePool(const QString &folder)
    : m_folder(folder)
{
    fillPool(m_folder);
}

quint32 FilePool::count()
{
    QMutexLocker    locker(&m_mutex);

    return m_files.count();
}

const QStringList &FilePool::files() const
{
    return m_files;
}

QString FilePool::tryGetFile()
{
    QString         file("");
    QMutexLocker    locker(&m_mutex);

    if (m_files.isEmpty() == false)
    {
        file = m_files.front();
        m_files.pop_front();
    }

    return file;
}

void FilePool::fillPool(const QString &folder)
{
    QDir    dir(folder);

    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::NoSymLinks);

    for (const QFileInfo &entry : dir.entryInfoList())
    {
        if (entry.isDir())
        {
            fillPool(entry.filePath());
        }
        else if (entry.isFile())
        {
            m_files.append(entry.filePath());
        }
    }
}
