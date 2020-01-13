/****************************************************************************
** Meta object code from reading C++ file 'cppclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BasicDataTypesConversion/cppclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cppclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CppClass_t {
    QByteArrayData data[31];
    char stringdata0[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CppClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CppClass_t qt_meta_stringdata_CppClass = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CppClass"
QT_MOC_LITERAL(1, 9, 7), // "sendInt"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 5), // "param"
QT_MOC_LITERAL(4, 24, 10), // "sendDouble"
QT_MOC_LITERAL(5, 35, 17), // "sendBoolRealFloat"
QT_MOC_LITERAL(6, 53, 6), // "bParam"
QT_MOC_LITERAL(7, 60, 9), // "realParam"
QT_MOC_LITERAL(8, 70, 10), // "floatParam"
QT_MOC_LITERAL(9, 81, 13), // "sendStringUrl"
QT_MOC_LITERAL(10, 95, 10), // "stringParm"
QT_MOC_LITERAL(11, 106, 8), // "urlParam"
QT_MOC_LITERAL(12, 115, 13), // "sendColorFont"
QT_MOC_LITERAL(13, 129, 9), // "colorParm"
QT_MOC_LITERAL(14, 139, 9), // "fontParam"
QT_MOC_LITERAL(15, 149, 8), // "sendDate"
QT_MOC_LITERAL(16, 158, 9), // "dateParam"
QT_MOC_LITERAL(17, 168, 9), // "sendPoint"
QT_MOC_LITERAL(18, 178, 10), // "pointParam"
QT_MOC_LITERAL(19, 189, 11), // "pointfParam"
QT_MOC_LITERAL(20, 201, 8), // "sendSize"
QT_MOC_LITERAL(21, 210, 9), // "sizeParam"
QT_MOC_LITERAL(22, 220, 10), // "sizefParam"
QT_MOC_LITERAL(23, 231, 8), // "sendRect"
QT_MOC_LITERAL(24, 240, 9), // "rectParam"
QT_MOC_LITERAL(25, 250, 10), // "rectfParam"
QT_MOC_LITERAL(26, 261, 7), // "cppSlot"
QT_MOC_LITERAL(27, 269, 12), // "receivePoint"
QT_MOC_LITERAL(28, 282, 5), // "point"
QT_MOC_LITERAL(29, 288, 11), // "receiveRect"
QT_MOC_LITERAL(30, 300, 4) // "rect"

    },
    "CppClass\0sendInt\0\0param\0sendDouble\0"
    "sendBoolRealFloat\0bParam\0realParam\0"
    "floatParam\0sendStringUrl\0stringParm\0"
    "urlParam\0sendColorFont\0colorParm\0"
    "fontParam\0sendDate\0dateParam\0sendPoint\0"
    "pointParam\0pointfParam\0sendSize\0"
    "sizeParam\0sizefParam\0sendRect\0rectParam\0"
    "rectfParam\0cppSlot\0receivePoint\0point\0"
    "receiveRect\0rect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CppClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       5,    3,   80,    2, 0x06 /* Public */,
       9,    2,   87,    2, 0x06 /* Public */,
      12,    2,   92,    2, 0x06 /* Public */,
      15,    1,   97,    2, 0x06 /* Public */,
      17,    2,  100,    2, 0x06 /* Public */,
      20,    2,  105,    2, 0x06 /* Public */,
      23,    2,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      26,    0,  115,    2, 0x0a /* Public */,
      27,    1,  116,    2, 0x0a /* Public */,
      29,    1,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Bool, QMetaType::QReal, QMetaType::Float,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QUrl,   10,   11,
    QMetaType::Void, QMetaType::QColor, QMetaType::QFont,   13,   14,
    QMetaType::Void, QMetaType::QDate,   16,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPointF,   18,   19,
    QMetaType::Void, QMetaType::QSize, QMetaType::QSizeF,   21,   22,
    QMetaType::Void, QMetaType::QRect, QMetaType::QRectF,   24,   25,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   28,
    QMetaType::Void, QMetaType::QRect,   30,

       0        // eod
};

void CppClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CppClass *_t = static_cast<CppClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendInt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendDouble((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->sendBoolRealFloat((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 3: _t->sendStringUrl((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QUrl(*)>(_a[2]))); break;
        case 4: _t->sendColorFont((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< QFont(*)>(_a[2]))); break;
        case 5: _t->sendDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 6: _t->sendPoint((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 7: _t->sendSize((*reinterpret_cast< QSize(*)>(_a[1])),(*reinterpret_cast< QSizeF(*)>(_a[2]))); break;
        case 8: _t->sendRect((*reinterpret_cast< QRect(*)>(_a[1])),(*reinterpret_cast< QRectF(*)>(_a[2]))); break;
        case 9: _t->cppSlot(); break;
        case 10: _t->receivePoint((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 11: _t->receiveRect((*reinterpret_cast< QRect(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CppClass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CppClass::sendInt)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CppClass::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CppClass::sendDouble)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CppClass::*)(bool , qreal , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CppClass::sendBoolRealFloat)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CppClass::*)(QString , QUrl );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CppClass::sendStringUrl)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CppClass::*)(QColor , QFont );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CppClass::sendColorFont)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CppClass::*)(QDate );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CppClass::sendDate)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CppClass::*)(QPoint , QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CppClass::sendPoint)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CppClass::*)(QSize , QSizeF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CppClass::sendSize)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CppClass::*)(QRect , QRectF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CppClass::sendRect)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CppClass::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CppClass.data,
      qt_meta_data_CppClass,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CppClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CppClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CppClass.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CppClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CppClass::sendInt(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CppClass::sendDouble(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CppClass::sendBoolRealFloat(bool _t1, qreal _t2, float _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CppClass::sendStringUrl(QString _t1, QUrl _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CppClass::sendColorFont(QColor _t1, QFont _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CppClass::sendDate(QDate _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CppClass::sendPoint(QPoint _t1, QPointF _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CppClass::sendSize(QSize _t1, QSizeF _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CppClass::sendRect(QRect _t1, QRectF _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
