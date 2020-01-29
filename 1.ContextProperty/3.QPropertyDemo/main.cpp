#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "movie.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Movie movie;
    movie.settitle("Titanic");
    movie.setMainCharacter("Leonardo D");

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("Movie", &movie);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
