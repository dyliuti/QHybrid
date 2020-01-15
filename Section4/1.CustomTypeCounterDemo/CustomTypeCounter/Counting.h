#ifndef COUNTING_H
#define COUNTING_H

#include <QObject>

class Counting : public QObject
{
    Q_OBJECT
public:
    enum CountDirection{
        UP,
        DOWN
    };

    Q_ENUM(CountDirection)
private:
    explicit Counting(QObject *parent = nullptr);


signals:

public slots:
};

#endif // COUNTING_H
