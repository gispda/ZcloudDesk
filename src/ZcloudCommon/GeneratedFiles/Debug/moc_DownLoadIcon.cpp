/****************************************************************************
** Meta object code from reading C++ file 'DownLoadIcon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DownLoadIcon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DownLoadIcon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DownLoadIcon_t {
    QByteArrayData data[9];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DownLoadIcon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DownLoadIcon_t qt_meta_stringdata_DownLoadIcon = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DownLoadIcon"
QT_MOC_LITERAL(1, 13, 12), // "readProgress"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "totalBytes"
QT_MOC_LITERAL(4, 38, 9), // "bytesRead"
QT_MOC_LITERAL(5, 48, 15), // "finished_signal"
QT_MOC_LITERAL(6, 64, 14), // "requestTimeout"
QT_MOC_LITERAL(7, 79, 15), // "requestFinished"
QT_MOC_LITERAL(8, 95, 13) // "httpReadyRead"

    },
    "DownLoadIcon\0readProgress\0\0totalBytes\0"
    "bytesRead\0finished_signal\0requestTimeout\0"
    "requestFinished\0httpReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DownLoadIcon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DownLoadIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DownLoadIcon *_t = static_cast<DownLoadIcon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->finished_signal(); break;
        case 2: _t->requestTimeout(); break;
        case 3: _t->requestFinished(); break;
        case 4: _t->httpReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DownLoadIcon::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownLoadIcon::readProgress)) {
                *result = 0;
            }
        }
        {
            typedef void (DownLoadIcon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownLoadIcon::finished_signal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DownLoadIcon::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DownLoadIcon.data,
      qt_meta_data_DownLoadIcon,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DownLoadIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DownLoadIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DownLoadIcon.stringdata0))
        return static_cast<void*>(const_cast< DownLoadIcon*>(this));
    return QThread::qt_metacast(_clname);
}

int DownLoadIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DownLoadIcon::readProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DownLoadIcon::finished_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
