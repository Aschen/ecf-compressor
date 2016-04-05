#include "ZippedBuffer.hh"

ZippedBuffer::ZippedBuffer()
    : m_valid(false)
{
}

ZippedBuffer::ZippedBuffer(const QString &filepath, const QByteArray &data)
    : m_filepath(filepath),
      m_data(data),
      m_valid(true)
{
}

void ZippedBuffer::read(QDataStream &stream)
{
    stream >> m_filepath >> m_data;
    m_valid = true;
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

bool ZippedBuffer::valid() const
{
    return m_valid;
}

void ZippedBuffer::valid(bool isValid)
{
    m_valid = isValid;
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
    zippedBuffer.valid(true);

    return in;
}
