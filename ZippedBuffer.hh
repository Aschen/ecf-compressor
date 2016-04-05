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
    bool                m_valid;

public:
    ZippedBuffer();
    ZippedBuffer(const QString &filepath, const QByteArray &data);

    void                read(QDataStream &stream);
    void                write(QDataStream &stream) const;

    const QString       filepath() const;
    void                filepath(const QString &filepath);
    const QByteArray    data() const;
    void                data(const QByteArray &data);
    bool                valid() const;
    void                valid(bool isValid);

};

QDataStream &operator <<(QDataStream &out, const ZippedBuffer &zippedBuffer);
QDataStream &operator >>(QDataStream &in, ZippedBuffer &zippedBuffer);

#endif // ZIPPEDBUFFER_HH
