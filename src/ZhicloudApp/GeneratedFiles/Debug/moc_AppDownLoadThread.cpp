/****************************************************************************
** Meta object code from reading C++ file 'AppDownLoadThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DownloadFile/AppDownLoadThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppDownLoadThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AppDownLoadThread_t {
    QByteArrayData data[21];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppDownLoadThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppDownLoadThread_t qt_meta_stringdata_AppDownLoadThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AppDownLoadThread"
QT_MOC_LITERAL(1, 18, 21), // "signalDownloadProcess"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 19), // "signalStatusChanged"
QT_MOC_LITERAL(4, 61, 16), // "APPDOWNLOADETYPE"
QT_MOC_LITERAL(5, 78, 16), // "installFinishAdd"
QT_MOC_LITERAL(6, 95, 11), // "AppDataInfo"
QT_MOC_LITERAL(7, 107, 18), // "closeDowloadSignal"
QT_MOC_LITERAL(8, 126, 7), // "classId"
QT_MOC_LITERAL(9, 134, 18), // "onDownloadProgress"
QT_MOC_LITERAL(10, 153, 13), // "bytesReceived"
QT_MOC_LITERAL(11, 167, 10), // "bytesTotal"
QT_MOC_LITERAL(12, 178, 11), // "onReadyRead"
QT_MOC_LITERAL(13, 190, 10), // "onFinished"
QT_MOC_LITERAL(14, 201, 7), // "onError"
QT_MOC_LITERAL(15, 209, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(16, 237, 4), // "code"
QT_MOC_LITERAL(17, 242, 12), // "stopDownload"
QT_MOC_LITERAL(18, 255, 13), // "closeDownload"
QT_MOC_LITERAL(19, 269, 16), // "continueDownload"
QT_MOC_LITERAL(20, 286, 10) // "reDownload"

    },
    "AppDownLoadThread\0signalDownloadProcess\0"
    "\0signalStatusChanged\0APPDOWNLOADETYPE\0"
    "installFinishAdd\0AppDataInfo\0"
    "closeDowloadSignal\0classId\0"
    "onDownloadProgress\0bytesReceived\0"
    "bytesTotal\0onReadyRead\0onFinished\0"
    "onError\0QNetworkReply::NetworkError\0"
    "code\0stopDownload\0closeDownload\0"
    "continueDownload\0reDownload"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppDownLoadThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       3,    1,   79,    2, 0x06 /* Public */,
       5,    1,   82,    2, 0x06 /* Public */,
       7,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   88,    2, 0x08 /* Private */,
      12,    0,   93,    2, 0x08 /* Private */,
      13,    0,   94,    2, 0x08 /* Private */,
      14,    1,   95,    2, 0x08 /* Private */,
      17,    0,   98,    2, 0x0a /* Public */,
      18,    0,   99,    2, 0x0a /* Public */,
      19,    0,  100,    2, 0x0a /* Public */,
      20,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AppDownLoadThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppDownLoadThread *_t = static_cast<AppDownLoadThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalDownloadProcess((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->signalStatusChanged((*reinterpret_cast< APPDOWNLOADETYPE(*)>(_a[1]))); break;
        case 2: _t->installFinishAdd((*reinterpret_cast< AppDataInfo(*)>(_a[1]))); break;
        case 3: _t->closeDowloadSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 5: _t->onReadyRead(); break;
        case 6: _t->onFinished(); break;
        case 7: _t->onError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 8: _t->stopDownload(); break;
        case 9: _t->closeDownload(); break;
        case 10: _t->continueDownload(); break;
        case 11: _t->reDownload(); break;
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
            typedef void (AppDownLoadThread::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppDownLoadThread::signalDownloadProcess)) {
                *result = 0;
            }
        }
        {
            typedef void (AppDownLoadThread::*_t)(APPDOWNLOADETYPE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppDownLoadThread::signalStatusChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (AppDownLoadThread::*_t)(AppDataInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppDownLoadThread::installFinishAdd)) {
                *result = 2;
            }
        }
        {
            typedef void (AppDownLoadThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppDownLoadThread::closeDowloadSignal)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject AppDownLoadThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_AppDownLoadThread.data,
      qt_meta_data_AppDownLoadThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AppDownLoadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppDownLoadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AppDownLoadThread.stringdata0))
        return static_cast<void*>(const_cast< AppDownLoadThread*>(this));
    return QThread::qt_metacast(_clname);
}

int AppDownLoadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void AppDownLoadThread::signalDownloadProcess(qint64 _t1, qint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppDownLoadThread::signalStatusChanged(APPDOWNLOADETYPE _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AppDownLoadThread::installFinishAdd(AppDataInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AppDownLoadThread::closeDowloadSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
