#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
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

    CPPRegister *cppRegister = new CPPRegister();

    // 名字可以随便设置, 但是需要注意不要在同一个QQmlEngine下重名
    qmlEngine.rootContext()->setContextProperty("CPP_Register", cppRegister);

    // 在创建qml之前注册类型, 否则报错未定义类型, 导致创建失败
    QQmlComponent* pComponent = new QQmlComponent(&qmlEngine, "qrc:/main.qml");
    QObject* pMainObj = pComponent->create();
    qDebug() << pComponent->errorString();

    QQuickWindow* pQuickWindow = dynamic_cast<QQuickWindow *>(pMainObj);

    emit cppRegister->tiggerOnce();
    pQuickWindow->show();
    return app.exec();
}
