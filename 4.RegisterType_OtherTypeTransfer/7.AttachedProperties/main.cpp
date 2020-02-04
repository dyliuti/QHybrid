#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "timer.h"
#include "TimerAttached.h"
#include "Person.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<TimerAttached>();
    qmlRegisterType<Timer>("Timing", 1, 0, "Timer");
    qmlRegisterType<Person>("People", 1, 0, "Person");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
