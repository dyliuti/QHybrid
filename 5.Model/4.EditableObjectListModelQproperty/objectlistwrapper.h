#ifndef OBJECTLISTWRAPPER_H
#define OBJECTLISTWRAPPER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "person.h"

class ObjectListWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> mypersons READ mypersons WRITE setMypersons NOTIFY mypersonsChanged)

public:
    explicit ObjectListWrapper(QObject *parent = nullptr);
    bool initialize();

    Q_INVOKABLE void setNames(int index, const QString & names);
    Q_INVOKABLE void setAge(int index, const int & age);
    Q_INVOKABLE void setFavoriteColor(int index,const QString & favoriteColor);
    Q_INVOKABLE QList<QObject *> persons() const;
    Q_INVOKABLE void addPerson();

    QList<QObject*> mypersons() const;

    void setMypersons(QList<QObject*> mypersons);

signals:
    void mypersonsChanged(QList<QObject*> mypersons);

private:
    void populateModelWithData();
    void resetModel();
    void printPersons();

    // 这里需要是QObject*, Person*在QML工作不了
    QList<QObject*> mPersons;
    QQmlApplicationEngine mEngine;
    //QList<QObject*> m_mypersons;
};

#endif // OBJECTLISTWRAPPER_H
