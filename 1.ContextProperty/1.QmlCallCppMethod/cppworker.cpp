#include "cppworker.h"

CppWorker::CppWorker(QObject *parent) : QObject(parent)
{

}

void CppWorker::regularMethod()
{
    qDebug() << "C++的regularMdthod被调用了";
}

QString CppWorker::regularMethodWithReturn(QString name, int age)
{
    return QString(name + ": " + QString::number(age) + " years old");
}

void CppWorker::cppSlot()
{
    qDebug() << "C++的cppSlot被调用了";
}
