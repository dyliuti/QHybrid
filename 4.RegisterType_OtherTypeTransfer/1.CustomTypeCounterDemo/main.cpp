#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Counter.h"
#include "Counting.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Counter>("com.dyliuti.counter", 1, 0, "Counter");
    qmlRegisterUncreatableType<Counting>("com.dyliuti.counter", 1, 0, "Counting",
                                               "Can not instantiate Counting from QML. Not Allowed.");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
