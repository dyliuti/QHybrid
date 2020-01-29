#include <QDebug>
#include "objectlistwrapper.h"

ObjectListWrapper::ObjectListWrapper(QObject *parent) : QObject(parent)
{
    populateModelWithData();
}

void ObjectListWrapper::populateModelWithData()
{
    mPersons.append(new Person("John Doe","green",32,this));
    mPersons.append(new Person("Mary Green","blue",23,this));
    mPersons.append(new Person("Mitch Nathson","dodgerblue",30,this));
}

bool ObjectListWrapper::initialize()
{
    resetModel();
    mEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (mEngine.rootObjects().isEmpty())
        return false;

    return true;
}

QList<QObject *> ObjectListWrapper::persons() const
{
    return mPersons;
}

void ObjectListWrapper::resetModel()
{
    mEngine.rootContext()->setContextProperty("Wrapper", this);
    //mEngine.rootContext()->setContextProperty("myModel",QVariant::fromValue(persons()));
}

void ObjectListWrapper::setNames(int index, const QString &names)
{
    qDebug() << "Changing names to : " << names;
    if(index >= mPersons.size())
        return;
    Person * person = static_cast<Person *> (mPersons.at(index));
    if( names!= person->names())
    {
        person->setNames(names);
    }
    printPersons();
}

void ObjectListWrapper::setAge(int index, const int &age)
{
    if(index >= mPersons.size())
        return;
    Person * person = static_cast<Person *> (mPersons.at(index));
    if( age!= person->age())
    {
        person->setAge(age);
    }
    printPersons();
}

void ObjectListWrapper::setFavoriteColor(int index, const QString &favoriteColor)
{
    if(index >= mPersons.size())
        return;
    Person * person = static_cast<Person *> (mPersons.at(index));
    if( favoriteColor!= person->favoriteColor())
    {
        person->setFavoriteColor(favoriteColor);
    }
    printPersons();
}

void ObjectListWrapper::addPerson()
{
    mPersons.append(new Person("New Person", "green", 32, this));
    emit mypersonsChanged(mPersons);
}

QList<QObject *> ObjectListWrapper::mypersons() const
{
    return mPersons;
}

void ObjectListWrapper::setMypersons(QList<QObject *> mypersons)
{
    if (mPersons == mypersons)
        return;

    mPersons = mypersons;
    emit mypersonsChanged(mPersons);
}

void ObjectListWrapper::printPersons()
{
    qDebug() << "-------------Persons--------------------";
    foreach (QObject * obj, mPersons) {
        Person * person = static_cast<Person *> (obj);
        qDebug() << person->names() << " " << person->age() << " " << person->favoriteColor();
    }
}
