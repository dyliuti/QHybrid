#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "AppWrapper.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    AppWrapper appWrapper;
    if(!appWrapper.initialize())
        return -1;
//    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("Wrapper", &appWrapper);

//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    return app.exec();
}
