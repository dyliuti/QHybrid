#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cppclass.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    CppClass cppClass;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("CppClass", &cppClass);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
