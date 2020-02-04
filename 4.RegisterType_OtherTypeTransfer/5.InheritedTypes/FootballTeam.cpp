#include "FootballTeam.h"
#include <QDebug>

FootballTeam::FootballTeam(QObject *parent) : QObject(parent)
{

}

// QML engine只有当append(),getCount(),getitemAt(i),clearitems()时才会调用下面这些回调函数
QQmlListProperty<Player> FootballTeam::players() //const
{
    //return m_players;
    return QQmlListProperty<Player>(this, this, &FootballTeam::appendPlayer, // QQmlListProperty::AppendFunction
                                    &FootballTeam::playerCount, // QQmlListProperty::CountFunction
                                    &FootballTeam::player,      // QQmlListProperty::AtFunction
                                    &FootballTeam::clearPlayers); // QQmlListProperty::ClearFunction)
}

void FootballTeam::appendPlayerCustom(Player * player)
{
    qDebug() << "Adding player to vector. " << player->name();
    m_players.append(player);
}

int FootballTeam::playCountCustom() const
{
    qDebug() << "player count. " << m_players.count();
    return m_players.count();
}

Player *FootballTeam::playerCustom(int index) const
{
    qDebug() << "player at. " << index;
    return m_players.at(index);
}

void FootballTeam::clearPlayerCustom()
{
    qDebug() << "player clear. ";
    m_players.clear();
}

// 实现回调函数
void FootballTeam::appendPlayer(QQmlListProperty<Player> * list, Player * player)
{
    // 将QQmlListProperty中的第二个参数进行强制转换
    reinterpret_cast<FootballTeam*>(list->data)->appendPlayerCustom(player);
}

int FootballTeam::playerCount(QQmlListProperty<Player> * list)
{
    return reinterpret_cast<FootballTeam*>(list->data)->playCountCustom();
}

Player *FootballTeam::player(QQmlListProperty<Player> * list, int index)
{
    return reinterpret_cast<FootballTeam*>(list->data)->playerCustom(index);
}

void FootballTeam::clearPlayers(QQmlListProperty<Player> * list)
{
    return reinterpret_cast<FootballTeam*>(list->data)->clearPlayerCustom();
}


QString FootballTeam::title() const
{
    return m_title;
}

QString FootballTeam::coath() const
{
    return m_coath;
}

Player *FootballTeam::captain() const
{
    return m_captain;
}


void FootballTeam::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}

void FootballTeam::setCoath(QString coath)
{
    if (m_coath == coath)
        return;

    m_coath = coath;
    emit coathChanged(m_coath);
}

void FootballTeam::setCaptain(Player *captain)
{
    if (m_captain == captain)
        return;

    m_captain = captain;
    emit captainChanged(m_captain);
}

// 列表属性应该没有set,即使有也置空
void FootballTeam::setPlayers(QQmlListProperty<Player> players)
{
//    if (m_players == players)
//        return;

//    m_players = players;
//    emit playersChanged(m_players);
}
