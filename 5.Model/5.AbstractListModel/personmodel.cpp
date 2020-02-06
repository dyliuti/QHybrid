
#include <QDebug>
#include "personmodel.h"

PersonModel::PersonModel(QObject *parent) : QAbstractListModel(parent)
{
    addPerson(new Person("Jamie Lannister","red",33));
    addPerson(new Person("Marry Lane","cyan",26));
    addPerson(new Person("Steve Moors","yellow",44));
    addPerson(new Person("Victor Trunk","dodgerblue",30));
    addPerson(new Person("Ariel Geeny","blue",33));
    addPerson(new Person("Knut Vikran","lightblue",26));
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mPersons.size();
}

/* 展示数据，框架调用的函数，需实现 */
QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    // 同 !index.isValid()
    if (index.row() < 0 || index.row() >= mPersons.count())
        return QVariant();
    //The index is valid
    Person * person = mPersons[index.row()];
    if( role == NamesRole)
        return person->names();
    if( role == FavoriteColorRole)
        return person->favoriteColor();
    if( role == AgeRole)
        return person->age();
     return QVariant();
}

/*  修改数据，类同在QML中改变了属性，触发set属性名函数，role起中介、路由作用，不同role不同处理。
    若果数据修改了，dataChanged()必须发送，这样QML中的属性值才会更新 */
// This function can be invoked via the meta-object system and from QML. See Q_INVOKABLE.
bool PersonModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Person * person = mPersons[index.row()];
    bool somethingChanged = false;

    switch (role) {
    case NamesRole:
    {
        if( person->names()!= value.toString()){
            qDebug() << "Changing names for " << person->names();
            person->setNames(value.toString());
            somethingChanged = true;
        }
    }
        break;
    case FavoriteColorRole:
    {
        if( person->favoriteColor()!= value.toString()){
            qDebug() << "Changing color for " << person->names();
            person->setFavoriteColor(value.toString());
            somethingChanged = true;
        }
    }
        break;
    case AgeRole:
    {
        if( person->age()!= value.toInt()){
            qDebug() << "Changing age for " << person->names();
            person->setAge(value.toInt());
            somethingChanged = true;
        }
    }
    }

    if( somethingChanged){
        /* 可选角色参数可用于指定实际修改了哪些数据角色。
         * roles参数中的空向量意味着应该考虑修改所有的角色。roles参数中元素的顺序没有任何相关性。 */
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags PersonModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEditable;
}

// 与QML交互
// 使roles中的值可以在QML中使用，如names_, favoriteColor
QHash<int, QByteArray> PersonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NamesRole] = "names_";
    roles[FavoriteColorRole] = "favoriteColor";
    roles[AgeRole] = "age";
    return roles;
}

void PersonModel::addPerson(Person *person)
{
    const int index = mPersons.size();
    beginInsertRows(QModelIndex(), index, index);
    mPersons.append(person);
    endInsertRows();
}

void PersonModel::addPerson()
{
    Person *person = new Person("Added Person","yellowgreen",45,this);
    addPerson(person);
}

void PersonModel::addPerson(const QString &names, const int &age)
{
    Person *person=new Person(names,"yellowgreen",age);
    addPerson(person);
}

void PersonModel::removePerson(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    mPersons.removeAt(index);
    endRemoveRows();
}

void PersonModel::removeLastPerson()
{
    removePerson(mPersons.size()-1);
}
