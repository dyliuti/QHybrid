#include "propertywrapper.h"
#include <stdlib.h>
#include <time.h>

PropertyWrapper::PropertyWrapper(QObject *parent) : QObject(parent),
    m_lastName("last"),
    m_firstName("first"),
    m_timer(new QTimer(this)),
    m_random_number(0)
{
    srand(time(NULL));

    QStringList list;
    list << "小明" << "小红" << "小李" << "小将";

    connect(m_timer, &QTimer::timeout, [=](){
        m_random_number = rand() % (list.size());
        setFirstName(list[m_random_number]);
    });

    m_timer->start(3000);
}

QString PropertyWrapper::lastName() const
{
    return m_lastName;
}

QString PropertyWrapper::firstName() const
{
    return m_firstName;
}


void PropertyWrapper::setLastName(QString lastName)
{
    if (m_lastName == lastName)
        return;

    m_lastName = lastName;
    emit lastNameChanged(m_lastName);
}

void PropertyWrapper::setFirstName(QString firstName)
{
    if (m_firstName == firstName)
        return;

    m_firstName = firstName;
    emit firstNameChanged(m_firstName);
}

