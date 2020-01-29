#include "cppclass.h"
#include <QDebug>

CppClass::CppClass(QObject *parent) : QObject(parent)
{

}

void CppClass::cppSlot()
{
    qDebug() << "cppSlot called";
    emit sendInt(12);
    emit sendDouble(12.34);
    emit sendBoolRealFloat(true, 3.44, 4.2);

    emit sendStringUrl("nihao", QUrl("www.baidu.com"));
    emit sendColorFont(QColor(122, 22, 122), QFont("italy"));
    emit sendDate(QDate(2, 3, 4));
    emit sendPoint(QPoint(1, 1), QPointF(1.1, 2.2));
    emit sendSize(QSize(1, 1), QSizeF(1.1, 2.2));
    emit sendRect(QRect(QPoint(1, 1), QPoint(2, 2)), QRectF(QPointF(1.1, 2.2), QPointF(3.3, 4.4)));
}

void CppClass::receivePoint(QPoint point)
{
    qDebug() << "receive QML point: " << point;
}

void CppClass::receiveRect(QRect rect)
{
    qDebug() << "receive QML rect: " << rect;
}
