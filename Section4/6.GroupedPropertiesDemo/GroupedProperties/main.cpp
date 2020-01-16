#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "player.h"
#include "FootballTeam.h"
#include "Striker.h"
#include "Defender.h"
#include "PlayDetails.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // 该类在QML中也不能被创建（在C++中创建），且类型不能通过名称来引用时
    qmlRegisterType<PlayDetails>();

    //qmlRegisterType<Player>("com.dyliuti.Football", 1, 0, "Player");
    // Player现在是纯虚函数了，不能实例化该类
    qmlRegisterUncreatableType<Player>("com.dyliuti.Football", 1, 0, "Player",
                                       "Can not create Player in QML. Not allowed");
    qmlRegisterType<Striker>("com.dyliuti.Football", 1, 0, "Striker");
    qmlRegisterType<Defender>("com.dyliuti.Football", 1, 0, "Defender");
    qmlRegisterType<FootballTeam>("com.dyliuti.Football", 1, 0, "FootballTeam");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
