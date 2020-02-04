#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)

private:
    QString m_name;
    int m_age;

public:
    explicit Person(QObject *parent = nullptr);

    QString name() const;
    int age() const;
    void setName(QString name); // Q_PROPERTY中定义的槽函数可以放在普通函数区
    void setAge(int age);
signals:
    void nameChanged(QString name);
    void ageChanged(int age);

public slots:

};

#endif // PERSON_H
