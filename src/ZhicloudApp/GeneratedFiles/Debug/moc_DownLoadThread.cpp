/****************************************************************************
** Meta object code from reading C++ file 'DownLoadThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DownloadFile/DownLoadThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DownLoadThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DownLoadThread_t {
    QByteArrayData data[14];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DownLoadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DownLoadThread_t qt_meta_stringdata_DownLoadThread = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DownLoadThread"
QT_MOC_LITERAL(1, 15, 21), // "signalDownloadProcess"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 19), // "signalReplyFinished"
QT_MOC_LITERAL(4, 58, 19), // "signalDownloadError"
QT_MOC_LITERAL(5, 78, 15), // "installFinished"
QT_MOC_LITERAL(6, 94, 18), // "onDownloadProgress"
QT_MOC_LITERAL(7, 113, 13), // "bytesReceived"
QT_MOC_LITERAL(8, 127, 10), // "bytesTotal"
QT_MOC_LITERAL(9, 138, 11), // "onReadyRead"
QT_MOC_LITERAL(10, 150, 10), // "onFinished"
QT_MOC_LITERAL(11, 161, 7), // "onError"
QT_MOC_LITERAL(12, 169, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(13, 197, 4) // "code"

    },
    "DownLoadThread\0signalDownloadProcess\0"
    "\0signalReplyFinished\0signalDownloadError\0"
    "installFinished\0onDownloadProgress\0"
    "bytesReceived\0bytesTotal\0onReadyRead\0"
    "onFinished\0onError\0QNetworkReply::NetworkError\0"
    "code"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DownLoadThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       3,    2,   59,    2, 0x06 /* Public */,
       4,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   70,    2, 0x08 /* Private */,
       9,    0,   75,    2, 0x08 /* Private */,
      10,    0,   76,    2, 0x08 /* Private */,
      11,    1,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void DownLoadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DownLoadThread *_t = static_cast<DownLoadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalDownloadProcess((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->signalReplyFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->signalDownloadError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->installFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 5: _t->onReadyRead(); break;
        case 6: _t->onFinished(); break;
        case 7: _t->onError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DownLoadThread::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownLoadThread::signalDownloadProcess)) {
                *result = 0;
            }
        }
        {
            typedef void (DownLoadThread::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownLoadThread::signalReplyFinished)) {
                *result = 1;
            }
        }
        {
            typedef void (DownLoadThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownLoadThread::signalDownloadError)) {
                *result = 2;
            }
        }
        {
            typedef void (DownLoadThread::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownLoadThread::installFinished)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject DownLoadThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DownLoadThread.data,
      qt_meta_data_DownLoadThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DownLoadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DownLoadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DownLoadThread.stringdata0))
        return static_cast<void*>(const_cast< DownLoadThread*>(this));
    return QThread::qt_metacast(_clname);
}

int DownLoadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DownLoadThread::signalDownloadProcess(qint64 _t1, qint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DownLoadThread::signalReplyFinished(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DownLoadThread::signalDownloadError(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DownLoadThread::installFinished(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
