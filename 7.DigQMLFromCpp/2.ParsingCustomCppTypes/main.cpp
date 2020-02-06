#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QDebug>
#include <player.h>
#include <footballteam.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Register Types
    qmlRegisterType<Player>("com.dyliuti.Football", 1,0, "Player");
    qmlRegisterType<FootBallTeam>("com.dyliuti.Football", 1,0, "FootballTeam");

    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl("qrc:/main.qml"));

    FootBallTeam * team = qobject_cast<FootBallTeam* > (component.create());

    if(team && team->captain()){
        qDebug() << "Team : " << team->title() << " , captain is : " << team->captain()->name();
        qDebug() << "The players are : ";

        // 成员函数
        for ( int i = 1; i < team->playerCountCustom() ; i++){
            qDebug() << " " << team->playerCustom(i)->name();
        }
    }

    return a.exec();
}
