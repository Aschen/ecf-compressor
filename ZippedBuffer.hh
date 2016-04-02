#ifndef ZIPPEDBUFFER_HH
# define ZIPPEDBUFFER_HH

# include <QString>
# include <QByteArray>
# include <QDataStream>
# include <QDebug>

class ZippedBuffer
{
private:
    QString             m_filepath;
    QByteArray          m_data;

public:
    ZippedBuffer();

    void                read(QDataStream &stream);
    void                write(QDataStream &stream) const;

    const QString       filepath() const;
    void                filepath(const QString &filepath);
    const QByteArray    data() const;
    void                data(const QByteArray &data);

};

QDataStream &operator <<(QDataStream &out, const ZippedBuffer &zippedBuffer);
QDataStream &operator >>(QDataStream &in, ZippedBuffer &zippedBuffer);

#endif // ZIPPEDBUFFER_HH
