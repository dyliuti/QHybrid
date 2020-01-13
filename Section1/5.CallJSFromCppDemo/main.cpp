#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlCOntext>
#include "qmljscaller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QmlJsCaller jsCaller;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("QmlJsCaller", &jsCaller);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }
    else{
        // 要确认这个已经设置了
        jsCaller.setQmlRootObject(engine.rootObjects().first());  // .first换成[0]也可以
    }

    return app.exec();
}
