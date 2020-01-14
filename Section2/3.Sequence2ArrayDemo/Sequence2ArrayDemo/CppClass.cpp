#include "CppClass.h"
#include <QDebug>

CppClass::CppClass(QObject *parent) : QObject(parent)
{
    mVector.append("ONe");
    mVector.append("two");
    mVector.append("Three");
}

void CppClass::qmlArrayToCPP(QVector<QString> vector)
{
    foreach(QString string, vector){
        qDebug() << string;
    }
}

QVector<QString> CppClass::retrieveStrings()
{
    return mVector;
}
