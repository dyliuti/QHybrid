#include "movie.h"
#include "qdebug.h"

Movie::Movie(QObject *parent) : QObject(parent),
  m_title("Movie Title"),
  m_mainCharacter("Main Character")
{

}

QString Movie::mainCharacter() const
{
    qDebug() << "Getting the mainCharacter";
    return m_mainCharacter;
}

QString Movie::title() const
{
    qDebug() << "Getting the title";
    return m_title;
}

void Movie::setMainCharacter(QString mainCharacter)
{
    qDebug() << "setting the setMainCharacter";
    if (m_mainCharacter == mainCharacter)
        return;

    m_mainCharacter = mainCharacter;
    // 一定得发射， 不然Movie.mainCharacter = mainCharTextFieldId.text还是之前的值
    // text: Movie.mainCharacter 发射后，这个TextField中的text才会更新
    emit mainCharacterChanged(m_mainCharacter);
}

void Movie::settitle(QString title)
{
    qDebug() << "setting the settitle";
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged(m_title);
}
