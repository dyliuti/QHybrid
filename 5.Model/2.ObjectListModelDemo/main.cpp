#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QList<QObject *> personList;
    personList.append(new Person("John Doe C++","green",32,&engine));
    personList.append(new Person("Mary Green","blue",23,&engine));
    personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    personList.append(new Person("Daniel Sten","red",67,&engine));
    personList.append(new Person("John Doe C++","green",32,&engine));
    personList.append(new Person("Mary Green","blue",23,&engine));
    personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    personList.append(new Person("Daniel Sten","red",67,&engine));
    personList.append(new Person("John Doe C++","green",32,&engine));
    personList.append(new Person("Mary Green","blue",23,&engine));
    personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    personList.append(new Person("Daniel Sten","red",67,&engine));
    personList.append(new Person("John Doe C++","green",32,&engine));
    personList.append(new Person("Mary Green","blue",23,&engine));
    personList.append(new Person("Mitch Nathson","dodgerblue",30,&engine));
    personList.append(new Person("Daniel Sten","red",67,&engine));

    // personList中的所有属性注册到了QML，这些属性可当全局变量使用。
    // QList不是继承与QObject的，不能使用&personList 转换为QObject* 需要用以下重载方法。QList是内置的注册类型，可转换为QVariant
    engine.rootContext()->setContextProperty("personModel", QVariant::fromValue(personList));


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
