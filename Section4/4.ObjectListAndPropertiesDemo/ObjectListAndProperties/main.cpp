#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "player.h"
#include "FootballTeam.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Player>("com.dyliuti.Football", 1, 0, "Player");
    qmlRegisterType<FootballTeam>("com.dyliuti.Football", 1, 0, "FootballTeam");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
