/****************************************************************************
** Meta object code from reading C++ file 'ZcloudMsgThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ZcloudMsgThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZcloudMsgThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZcloudMsgThread_t {
    QByteArrayData data[7];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZcloudMsgThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZcloudMsgThread_t qt_meta_stringdata_ZcloudMsgThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ZcloudMsgThread"
QT_MOC_LITERAL(1, 16, 11), // "sendMsgInfo"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "strParam"
QT_MOC_LITERAL(4, 38, 6), // "nCount"
QT_MOC_LITERAL(5, 45, 16), // "sendActivityInfo"
QT_MOC_LITERAL(6, 62, 16) // "checkTokenFailed"

    },
    "ZcloudMsgThread\0sendMsgInfo\0\0strParam\0"
    "nCount\0sendActivityInfo\0checkTokenFailed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZcloudMsgThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    1,   34,    2, 0x06 /* Public */,
       6,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void ZcloudMsgThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZcloudMsgThread *_t = static_cast<ZcloudMsgThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMsgInfo((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sendActivityInfo((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->checkTokenFailed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ZcloudMsgThread::*_t)(QStringList , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudMsgThread::sendMsgInfo)) {
                *result = 0;
            }
        }
        {
            typedef void (ZcloudMsgThread::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudMsgThread::sendActivityInfo)) {
                *result = 1;
            }
        }
        {
            typedef void (ZcloudMsgThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudMsgThread::checkTokenFailed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ZcloudMsgThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ZcloudMsgThread.data,
      qt_meta_data_ZcloudMsgThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZcloudMsgThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZcloudMsgThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZcloudMsgThread.stringdata0))
        return static_cast<void*>(const_cast< ZcloudMsgThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ZcloudMsgThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ZcloudMsgThread::sendMsgInfo(QStringList _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZcloudMsgThread::sendActivityInfo(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ZcloudMsgThread::checkTokenFailed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
