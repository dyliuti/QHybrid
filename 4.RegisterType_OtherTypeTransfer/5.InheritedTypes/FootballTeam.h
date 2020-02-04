#ifndef FOOTBALLTEAM_H
#define FOOTBALLTEAM_H

#include <QObject>
#include <QQmlListProperty>
#include <player.h>
#include <QVector>

class FootballTeam : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString coath READ coath WRITE setCoath NOTIFY coathChanged)
    Q_PROPERTY(Player* captain READ captain WRITE setCaptain NOTIFY captainChanged)
    Q_PROPERTY(QQmlListProperty<Player> players READ players WRITE setPlayers NOTIFY playersChanged)    // 列表属性应该没有set,即使有也置空

private:
    QString m_title;
    QString m_coath;
    Player* m_captain;
    //QQmlListProperty<Player> m_players;
    QVector<Player*> m_players;

private:
    //Callback Methods
    static void appendPlayer(QQmlListProperty<Player>*, Player*);
    static int playerCount(QQmlListProperty<Player>*);
    static Player* player(QQmlListProperty<Player>*, int);
    static void clearPlayers(QQmlListProperty<Player>*);

public:
    // Helper methods
    void appendPlayerCustom(Player*);
    int playCountCustom() const;
    Player *playerCustom(int) const;
    void clearPlayerCustom();

public:
    explicit FootballTeam(QObject *parent = nullptr);

    QString title() const;
    QString coath() const;
    Player* captain() const;
    QQmlListProperty<Player> players(); //不能是 const; 返回值需要修改的

signals:
    void titleChanged(QString title);
    void coathChanged(QString coath);
    void captainChanged(Player* captain);
    void playersChanged(QQmlListProperty<Player> players); // 不需要

public slots:
    void setTitle(QString title);
    void setCoath(QString coath);
    void setCaptain(Player* captain);
    void setPlayers(QQmlListProperty<Player> players);
};

#endif // FOOTBALLTEAM_H
