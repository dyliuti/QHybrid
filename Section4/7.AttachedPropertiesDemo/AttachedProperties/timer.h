#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include "TimerAttached.h"
#include <qqml.h>  // QML_DECLARE_TYPEINFO

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);

    //命名是有规范的，一定要和下面的QML_HAS_ATTACHED_PROPERTIES对应
    static TimerAttached* qmlAttachedProperties(QObject* object);
signals:

public slots:
};
//
QML_DECLARE_TYPEINFO(Timer, QML_HAS_ATTACHED_PROPERTIES)

#endif // TIMER_H
