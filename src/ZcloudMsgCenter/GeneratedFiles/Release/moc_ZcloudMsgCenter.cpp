/****************************************************************************
** Meta object code from reading C++ file 'ZcloudMsgCenter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/ZcloudMsgCenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZcloudMsgCenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZcloudMsgCenter_t {
    QByteArrayData data[6];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZcloudMsgCenter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZcloudMsgCenter_t qt_meta_stringdata_ZcloudMsgCenter = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ZcloudMsgCenter"
QT_MOC_LITERAL(1, 16, 18), // "changeUnreadMsgNum"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "checkTokenFailed"
QT_MOC_LITERAL(4, 53, 18), // "sigReduceUnreadNum"
QT_MOC_LITERAL(5, 72, 21) // "sigSendMessageRespone"

    },
    "ZcloudMsgCenter\0changeUnreadMsgNum\0\0"
    "checkTokenFailed\0sigReduceUnreadNum\0"
    "sigSendMessageRespone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZcloudMsgCenter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       3,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    1,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void ZcloudMsgCenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZcloudMsgCenter *_t = static_cast<ZcloudMsgCenter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeUnreadMsgNum((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->checkTokenFailed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigReduceUnreadNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sigSendMessageRespone((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ZcloudMsgCenter::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudMsgCenter::changeUnreadMsgNum)) {
                *result = 0;
            }
        }
        {
            typedef void (ZcloudMsgCenter::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudMsgCenter::checkTokenFailed)) {
                *result = 1;
            }
        }
        {
            typedef void (ZcloudMsgCenter::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudMsgCenter::sigReduceUnreadNum)) {
                *result = 2;
            }
        }
        {
            typedef void (ZcloudMsgCenter::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudMsgCenter::sigSendMessageRespone)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ZcloudMsgCenter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ZcloudMsgCenter.data,
      qt_meta_data_ZcloudMsgCenter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZcloudMsgCenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZcloudMsgCenter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZcloudMsgCenter.stringdata0))
        return static_cast<void*>(const_cast< ZcloudMsgCenter*>(this));
    return QObject::qt_metacast(_clname);
}

int ZcloudMsgCenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ZcloudMsgCenter::changeUnreadMsgNum(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZcloudMsgCenter::checkTokenFailed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ZcloudMsgCenter::sigReduceUnreadNum(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ZcloudMsgCenter::sigSendMessageRespone(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
