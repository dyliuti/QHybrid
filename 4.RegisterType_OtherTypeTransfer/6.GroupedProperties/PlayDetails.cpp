#include "PlayDetails.h"

PlayDetails::PlayDetails(QObject *parent) : QObject(parent)
{

}

qreal PlayDetails::height() const
{
    return m_height;
}

qreal PlayDetails::weight() const
{
    return m_weight;
}

qreal PlayDetails::speed() const
{
    return m_speed;
}

void PlayDetails::setHeight(qreal height)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_height, height))
        return;

    m_height = height;
    emit heightChanged(m_height);
}

void PlayDetails::setWeight(qreal weight)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_weight, weight))
        return;

    m_weight = weight;
    emit weightChanged(m_weight);
}

void PlayDetails::setSpeed(qreal speed)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_speed, speed))
        return;

    m_speed = speed;
    emit speedChanged(m_speed);
}
