#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QTimer>
#include "Counting.h"

class Counter : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    // Q_PROPERTY(bool up READ up WRITE setUp NOTIFY upChanged)
    Q_PROPERTY(Counting::CountDirection counting READ counting WRITE setCounting NOTIFY countingChanged)
private:
    int m_count;
    QTimer* m_timer;

    Counting::CountDirection m_counting;

public:
    explicit Counter(QObject *parent = nullptr);

    int count() const;
    bool up() const;

    // 额外方法
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();
    Counting::CountDirection counting() const;
    void setCounting(Counting::CountDirection counting); // 槽函数变为普通函数
signals:
    void countChanged(int count);
    void countingChanged(Counting::CountDirection counting);

public slots:
    void setCount(int count);


};

#endif // COUNTER_H
