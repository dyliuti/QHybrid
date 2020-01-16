#ifndef PLAYDETAILS_H
#define PLAYDETAILS_H

#include <QObject>

class PlayDetails : public QObject
{
    Q_OBJECT

private:
    qreal m_height;
    qreal m_weight;
    qreal m_speed;

public:
    explicit PlayDetails(QObject *parent = nullptr);

    Q_PROPERTY(qreal height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(qreal weight READ weight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(qreal speed READ speed WRITE setSpeed NOTIFY speedChanged)

    qreal height() const;
    qreal weight() const;
    qreal speed() const;

signals:
    void heightChanged(qreal height);
    void weightChanged(qreal weight);
    void speedChanged(qreal speed);

public slots:
    void setHeight(qreal height);
    void setWeight(qreal weight);
    void setSpeed(qreal speed);

};

#endif // PLAYDETAILS_H
