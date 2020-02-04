#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QTimer>

class Counter : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(bool up READ up WRITE setUp NOTIFY upChanged)

private:
    int m_count;
    bool m_up;
    QTimer* m_timer;

public:
    explicit Counter(QObject *parent = nullptr);

    int count() const;
    bool up() const;

    // 额外方法
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();
signals:
    void countChanged(int count);
    void upChanged(bool up);

public slots:
    void setCount(int count);
    void setUp(bool up);
};

#endif // COUNTER_H
