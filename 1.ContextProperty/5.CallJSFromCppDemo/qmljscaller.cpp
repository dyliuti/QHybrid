#include "qmljscaller.h"
#include "qdebug.h"
#include <qvariant.h>

void QmlJsCaller::callJSMethod(QString param)
{
    // 先定义返回值和参数
    QVariant returnValue;
    QVariant cppParameter = QVariant(param);
    QMetaObject::invokeMethod(qmlRootObject, "qmlJSFunction", Q_RETURN_ARG(QVariant, returnValue), Q_ARG(QVariant, cppParameter));
    qDebug() << "这里是Cpp,调用QML JS函数,返回值是: " << returnValue.toString();
}

QmlJsCaller::QmlJsCaller(QObject *parent) : QObject(parent)
{

}

void QmlJsCaller::setQmlRootObject(QObject *value)
{
    qmlRootObject = value;
}


void QmlJsCaller::cppMethod(QString parameter)
{
    qDebug() << "这里是Cpp，要调用QML JS函数";
    callJSMethod(parameter);    // 有返回值和参数
}
