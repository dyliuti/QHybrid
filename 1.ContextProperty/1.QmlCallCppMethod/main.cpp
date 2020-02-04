#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>  // 将C++的强大引用到qml
#include "cppworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // 暴露这个类给QML
    CppWorker mWorker;
    engine.rootContext()->setContextProperty("BWorker", &mWorker);  // 前面时qml用的类，可任意写。后者时C++的实例

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}


