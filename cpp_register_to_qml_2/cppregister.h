#ifndef CPPREGISTER_H
#define CPPREGISTER_H

#include <QObject>
#include <QVariant>

class CPPRegister : public QObject
{
    Q_OBJECT
public:
    CPPRegister();

    Q_INVOKABLE void setString(const QString &str) { m_string = str; }
    Q_INVOKABLE QVariant getString() const { return m_string; }

signals:
    void tiggerOnce();

private:
    QString m_string;
};

#endif // CPPREGISTER_H
