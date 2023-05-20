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

    // 第一个参数是导入时使用的名字
    // 第四个参数是对象名称
    qmlRegisterType<CPPRegister>("QMLApply", 1, 0, "QMLApplyObject");

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
