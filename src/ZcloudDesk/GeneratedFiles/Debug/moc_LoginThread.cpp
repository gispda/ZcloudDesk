/****************************************************************************
** Meta object code from reading C++ file 'LoginThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LoginThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoginThread_t {
    QByteArrayData data[6];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginThread_t qt_meta_stringdata_LoginThread = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LoginThread"
QT_MOC_LITERAL(1, 12, 12), // "loginSignals"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "status"
QT_MOC_LITERAL(4, 33, 14), // "UserInfoStruct"
QT_MOC_LITERAL(5, 48, 16) // "getFilishSignals"

    },
    "LoginThread\0loginSignals\0\0status\0"
    "UserInfoStruct\0getFilishSignals"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    1,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    2,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void LoginThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginThread *_t = static_cast<LoginThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginSignals((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< UserInfoStruct(*)>(_a[2]))); break;
        case 1: _t->getFilishSignals((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginThread::*_t)(int , UserInfoStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginThread::loginSignals)) {
                *result = 0;
            }
        }
        {
            typedef void (LoginThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginThread::getFilishSignals)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject LoginThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_LoginThread.data,
      qt_meta_data_LoginThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoginThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoginThread.stringdata0))
        return static_cast<void*>(const_cast< LoginThread*>(this));
    return QThread::qt_metacast(_clname);
}

int LoginThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void LoginThread::loginSignals(int _t1, UserInfoStruct _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginThread::getFilishSignals(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
