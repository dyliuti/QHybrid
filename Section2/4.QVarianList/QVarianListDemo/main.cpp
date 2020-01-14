#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CppClass.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    CppClass cppClass;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("CppClass", &cppClass);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()){
        return -1;
    }
    else{
        cppClass.setQmlRootObject(engine.rootObjects().first());
    }

    return app.exec();
}
