#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "propertywrapper.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    QString lastName = "Doe";
//    QString firstName = "John";
    PropertyWrapper propWrapper;
    propWrapper.setFirstName("first1");
    propWrapper.setLastName("last1");

    QQmlApplicationEngine engine;

//    engine.rootContext()->setContextProperty("mLastName", QVariant::fromValue(lastName));
//    engine.rootContext()->setContextProperty("mFirstName", QVariant::fromValue(firstName));
    engine.rootContext()->setContextObject(&propWrapper);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
