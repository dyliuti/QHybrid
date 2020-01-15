/****************************************************************************
** Meta object code from reading C++ file 'errorlevel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EnumRegisterDemo/errorlevel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'errorlevel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ErrorLevel_t {
    QByteArrayData data[6];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ErrorLevel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ErrorLevel_t qt_meta_stringdata_ErrorLevel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ErrorLevel"
QT_MOC_LITERAL(1, 11, 10), // "ErrorValue"
QT_MOC_LITERAL(2, 22, 11), // "INFORMATION"
QT_MOC_LITERAL(3, 34, 6), // "WARNIG"
QT_MOC_LITERAL(4, 41, 5), // "DEBUG"
QT_MOC_LITERAL(5, 47, 7) // "MESSAGE"

    },
    "ErrorLevel\0ErrorValue\0INFORMATION\0"
    "WARNIG\0DEBUG\0MESSAGE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ErrorLevel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    4,   18,

 // enum data: key, value
       2, uint(ErrorLevel::INFORMATION),
       3, uint(ErrorLevel::WARNIG),
       4, uint(ErrorLevel::DEBUG),
       5, uint(ErrorLevel::MESSAGE),

       0        // eod
};

QT_INIT_METAOBJECT const QMetaObject ErrorLevel::staticMetaObject = {
    { nullptr, qt_meta_stringdata_ErrorLevel.data,
      qt_meta_data_ErrorLevel,  nullptr, nullptr, nullptr}
};

QT_WARNING_POP
QT_END_MOC_NAMESPACE
