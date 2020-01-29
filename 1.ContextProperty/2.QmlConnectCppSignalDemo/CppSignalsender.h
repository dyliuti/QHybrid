#ifndef CPPSIGNALSENDER_H
#define CPPSIGNALSENDER_H

#include <QObject>
#include <QTimer>

class CppSignalSender : public QObject
{
    Q_OBJECT

private:
    QTimer * mTimer;
    int mValue;
public:
    explicit CppSignalSender(QObject *parent = nullptr);

signals:
    void callQml(QString param);
    void cppTimer(QString value);
public slots:
    void cppSlot();
};

#endif // CPPSIGNALSENDER_H
