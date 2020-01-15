#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class AppWrapper : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager* mNetManger;
    QNetworkReply* mNetReply;
    QByteArray* mDataBuffer;
    QStringList mJokes;

    QQmlApplicationEngine mEngine;
    void resetModel();

public:
    explicit AppWrapper(QObject *parent = nullptr);

    Q_INVOKABLE void fetchPost(int number);

    Q_INVOKABLE void removeLast();

    QStringList jokes() const;

    bool initialize();
signals:

public slots:
private slots:
    void dataReadyRead();
    void dataReadFinished();
};

#endif // APPWRAPPER_H
