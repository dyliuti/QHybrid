#ifndef CPPCLASS_H
#define CPPCLASS_H

#include <QObject>
#include <QUrl>
#include <QRect>
#include <QDate>
#include <QPoint>
#include <QSize>
#include <QColor>
#include <QFont>

class CppClass : public QObject
{
    Q_OBJECT
public:
    explicit CppClass(QObject *parent = nullptr);

signals:
    void sendInt(int param);
    void sendDouble(double param);
    void sendBoolRealFloat(bool bParam, qreal realParam, float floatParam);

    void sendStringUrl(QString stringParm, QUrl urlParam);
    void sendColorFont(QColor colorParm, QFont fontParam);
    void sendDate(QDate dateParam);
    void sendPoint(QPoint pointParam, QPointF pointfParam);
    void sendSize(QSize sizeParam, QSizeF sizefParam);
    void sendRect(QRect rectParam, QRectF rectfParam);
public slots:
    void cppSlot();
    void receivePoint(QPoint point);
    void receiveRect(QRect rect);
};

#endif // CPPCLASS_H
