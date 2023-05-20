#ifndef CPPREGISTER_H
#define CPPREGISTER_H

#include <QObject>
#include <QQuickItem>

class CPPRegister : public QQuickItem
{
    Q_OBJECT
public:
    CPPRegister();

    Q_PROPERTY(QString stringType READ stringType WRITE setStringType NOTIFY stringTypeChanged)

    void setStringType(const QString &str);
    const QString &stringType() const { return m_string; }

signals:
    void stringTypeChanged();

private:
    QString     m_string;
};

#endif // CPPREGISTER_H
