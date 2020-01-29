#ifndef MOVIE_H
#define MOVIE_H

#include <QObject>

class Movie : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString mainCharacter READ mainCharacter WRITE setMainCharacter NOTIFY mainCharacterChanged)
    Q_PROPERTY(QString title READ title WRITE settitle NOTIFY titleChanged)

private:
    QString m_mainCharacter;

    QString m_title;

public:
    explicit Movie(QObject *parent = nullptr);

QString mainCharacter() const;

QString title() const;

signals:
    void mainCharacterChanged(QString mainCharacter);
    void titleChanged(QString title);

public slots:
    void setMainCharacter(QString mainCharacter);
    void settitle(QString title);
};

#endif // MOVIE_H
