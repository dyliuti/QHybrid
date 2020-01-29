#ifndef QMLJSCALLER_H
#define QMLJSCALLER_H

#include <QObject>


class QmlJsCaller : public QObject
{
    Q_OBJECT

private:
    void callJSMethod(QString param);
    QObject * qmlRootObject;
public:
    explicit QmlJsCaller(QObject * parent = nullptr);
    Q_INVOKABLE void cppMethod(QString parameter);

signals:

public slots:

public:
    void setQmlRootObject(QObject *value);
};

#endif // QMLJSCALLER_H
