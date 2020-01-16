#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <QObject>
#include <QQmlPropertyValueSource>
#include <QQmlProperty>
#include <QTimer>
#include <qqml.h>

class RandomNumber : public QObject, public QQmlPropertyValueSource
{
    Q_OBJECT
    Q_PROPERTY(int maxValue READ maxValue WRITE setMaxValue NOTIFY maxValueChanged)
    // 这个宏告诉qt实现了哪些接口
    Q_INTERFACES(QQmlPropertyValueSource)

private:
    QQmlProperty m_targetProperty;
    int m_maxValue;
    QTimer* m_timer;
public:
    explicit RandomNumber(QObject *parent = nullptr);

    virtual void setTarget(const QQmlProperty & prop);
    int maxValue() const;

signals:
    void maxValueChanged(int maxValue);

public slots:
    void updateProperty();
    void setMaxValue(int maxValue);
};

#endif // RANDOMNUMBER_H
