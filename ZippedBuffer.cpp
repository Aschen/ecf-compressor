#include "ZippedBuffer.hh"

ZippedBuffer::ZippedBuffer()
{

}

ZippedBuffer::ZippedBuffer(const QString &filepath)
    : m_filepath(filepath)
{
}

ZippedBuffer::ZippedBuffer(const QString &filepath, const QByteArray &data)
    : m_filepath(filepath),
      m_data(data)
{
}

void ZippedBuffer::read(QDataStream &stream)
{
    stream >> m_filepath >> m_data;
}

void ZippedBuffer::write(QDataStream &stream) const
{
    stream << m_filepath << m_data;
}

const QString ZippedBuffer::filepath() const
{
    return m_filepath;
}

void ZippedBuffer::filepath(const QString &filepath)
{
    m_filepath = filepath;
}

const QByteArray ZippedBuffer::data() const
{
    return m_data;
}

void ZippedBuffer::data(const QByteArray &data)
{
    m_data = data;
}

QDataStream &operator <<(QDataStream &out, const ZippedBuffer &zippedBuffer)
{
    out << zippedBuffer.filepath() << zippedBuffer.data();

    return out;
}

QDataStream &operator >>(QDataStream &in, ZippedBuffer &zippedBuffer)
{
    QString     filepath;
    QByteArray  data;

    in >> filepath >> data;

    zippedBuffer.filepath(filepath);
    zippedBuffer.data(data);

    return in;
}
