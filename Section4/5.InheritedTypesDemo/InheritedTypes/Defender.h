#ifndef DEFENDER_H
#define DEFENDER_H

#include <QObject>
#include "Player.h"

class Defender : public Player
{
    Q_OBJECT
public:
    explicit Defender(QObject *parent = nullptr);

    // 实现纯虚函数
    void play();
    void defend();
signals:

public slots:
};

#endif // DEFENDER_H
