/****************************************************************************
** Meta object code from reading C++ file 'footballteam.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../2.ParsingCustomCppTypesDemo/footballteam.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'footballteam.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FootBallTeam_t {
    QByteArrayData data[12];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FootBallTeam_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FootBallTeam_t qt_meta_stringdata_FootBallTeam = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FootBallTeam"
QT_MOC_LITERAL(1, 13, 12), // "titleChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "title"
QT_MOC_LITERAL(4, 33, 13), // "coatchChanged"
QT_MOC_LITERAL(5, 47, 6), // "coatch"
QT_MOC_LITERAL(6, 54, 14), // "captainChanged"
QT_MOC_LITERAL(7, 69, 7), // "Player*"
QT_MOC_LITERAL(8, 77, 7), // "captain"
QT_MOC_LITERAL(9, 85, 14), // "playersChanged"
QT_MOC_LITERAL(10, 100, 7), // "players"
QT_MOC_LITERAL(11, 108, 24) // "QQmlListProperty<Player>"

    },
    "FootBallTeam\0titleChanged\0\0title\0"
    "coatchChanged\0coatch\0captainChanged\0"
    "Player*\0captain\0playersChanged\0players\0"
    "QQmlListProperty<Player>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FootBallTeam[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       9,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       8, 0x80000000 | 7, 0x0049510b,
      10, 0x80000000 | 11, 0x00495009,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void FootBallTeam::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FootBallTeam *_t = static_cast<FootBallTeam *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->titleChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->coatchChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->captainChanged((*reinterpret_cast< Player*(*)>(_a[1]))); break;
        case 3: _t->playersChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Player* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FootBallTeam::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FootBallTeam::titleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FootBallTeam::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FootBallTeam::coatchChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FootBallTeam::*)(Player * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FootBallTeam::captainChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FootBallTeam::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FootBallTeam::playersChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Player* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        FootBallTeam *_t = static_cast<FootBallTeam *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->title(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->coatch(); break;
        case 2: *reinterpret_cast< Player**>(_v) = _t->captain(); break;
        case 3: *reinterpret_cast< QQmlListProperty<Player>*>(_v) = _t->players(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        FootBallTeam *_t = static_cast<FootBallTeam *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setCoatch(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setCaptain(*reinterpret_cast< Player**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject FootBallTeam::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FootBallTeam.data,
      qt_meta_data_FootBallTeam,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FootBallTeam::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FootBallTeam::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FootBallTeam.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FootBallTeam::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FootBallTeam::titleChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FootBallTeam::coatchChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FootBallTeam::captainChanged(Player * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FootBallTeam::playersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
