#ifndef CPPCLASS_H
#define CPPCLASS_H

#include <QObject>
#include <QVector>

class CppClass : public QObject
{
    Q_OBJECT
private:
    QVector<QString> mVector;
public:
    explicit CppClass(QObject *parent = nullptr);

    Q_INVOKABLE void qmlArrayToCPP(QVector<QString> vector);

    Q_INVOKABLE QVector<QString> retrieveStrings();
signals:

public slots:
};

#endif // CPPCLASS_H
