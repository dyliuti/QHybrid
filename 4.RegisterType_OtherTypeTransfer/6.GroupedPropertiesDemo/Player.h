#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "PlayDetails.h"

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool playing READ playing WRITE setPlaying NOTIFY playingChanged)
    Q_PROPERTY(QString position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(PlayDetails* details READ details WRITE setDetails NOTIFY detailsChanged)
private:
    QString m_name;
    bool m_playing;
    QString m_position;

    // PlayDetails* m_details
    PlayDetails m_details;

public:
    explicit Player(QObject *parent = nullptr);

    QString name() const;
    bool playing() const;
    QString position() const;

    Q_INVOKABLE virtual void play() = 0; // 纯虚函数类，不能直接创建实例
    //PlayerDetails* details(); // const; 可修改
    PlayDetails* details(); // const;

signals:
    void nameChanged(QString name);
    void playingChanged(bool playing);
    void positionChanged(QString position);

    //void detailsChanged(PlayerDetails* details);
    void detailsChanged();

public slots:
    void setName(QString name);
    void setPlaying(bool playing);
    void setPosition(QString position);
    //void setDetails(PlayDetails* details);
    void setDetails(PlayDetails* details);
};

#endif // PLAYER_H
