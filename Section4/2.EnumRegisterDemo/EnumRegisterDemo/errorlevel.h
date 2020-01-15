#ifndef ERRORLEVEL_H
#define ERRORLEVEL_H

#include <QObject>

//class ErrorLevel : public QObject
class ErrorLevel
{
    //Q_OBJECT
    Q_GADGET    // 更轻量化
public:
    // explicit ErrorLevel(QObject *parent = nullptr);
    explicit ErrorLevel();

    enum ErrorValue{
        INFORMATION,
        WARNIG,
        DEBUG,
        MESSAGE
    };

    Q_ENUM(ErrorValue)

//signals:

//public slots:
};

#endif // ERRORLEVEL_H
