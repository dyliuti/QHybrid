#include "Player.h"

Player::Player(QObject *parent) : QObject(parent)
{

}

QString Player::name() const
{
    return m_name;
}

bool Player::playing() const
{
    return m_playing;
}

QString Player::position() const
{
    return m_position;
}

PlayDetails* Player::details() // const
{
    return &m_details;
}

void Player::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void Player::setPlaying(bool playing)
{
    if (m_playing == playing)
        return;

    m_playing = playing;
    emit playingChanged(m_playing);
}

void Player::setPosition(QString position)
{
    if (m_position == position)
        return;

    m_position = position;
    emit positionChanged(m_position);
}

void Player::setDetails(PlayDetails *details)
{
    //        if (m_details == details)
    //            return;

    //        m_details = details;
    //        emit detailsChanged(m_details);
}


