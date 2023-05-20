#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickWindow>
#include "cppregister.h"
#include <QDebug>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlEngine qmlEngine;

    // 第一个参数和第四个必须一致才可以, 否则会在创建QML时报错
    // 或许可以有其他方式修改QML引用的名字, 但没必要这么麻烦
    qmlRegisterType<CPPRegister>("CPPRegister", 1, 0, "CPPRegister");

    // 在创建qml之前注册类型, 否则报错未定义类型, 导致创建失败
    QQmlComponent* pComponent = new QQmlComponent(&qmlEngine, "qrc:/main.qml");
    QObject* pMainObj = pComponent->create();
    qDebug() << pComponent->errorString();

    CPPRegister *ptr = pMainObj->findChild<CPPRegister *>("cpp_register");
    Q_ASSERT(ptr != nullptr);

    qDebug() << ptr->stringType();

    QQuickWindow* pQuickWindow = dynamic_cast<QQuickWindow *>(pMainObj);

    pQuickWindow->show();
    return app.exec();
}
