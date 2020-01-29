#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QNetworkRequest>
#include <QNetworkProxy>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class AppWrapper : public QObject
{
    Q_OBJECT

public:
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

    void dataReadyRead();
    void dataReadFinished();
};

#endif // APPWRAPPER_H
