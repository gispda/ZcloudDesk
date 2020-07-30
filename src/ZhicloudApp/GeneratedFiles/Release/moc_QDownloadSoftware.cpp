/****************************************************************************
** Meta object code from reading C++ file 'QDownloadSoftware.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DownloadFile/QDownloadSoftware.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDownloadSoftware.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QDownloadSoftware_t {
    QByteArrayData data[14];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDownloadSoftware_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDownloadSoftware_t qt_meta_stringdata_QDownloadSoftware = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QDownloadSoftware"
QT_MOC_LITERAL(1, 18, 19), // "sigInstallFinlished"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 15), // "switchEinSignal"
QT_MOC_LITERAL(4, 55, 9), // "downClose"
QT_MOC_LITERAL(5, 65, 17), // "onDownloadProcess"
QT_MOC_LITERAL(6, 83, 13), // "bytesReceived"
QT_MOC_LITERAL(7, 97, 10), // "bytesTotal"
QT_MOC_LITERAL(8, 108, 15), // "resetPushButton"
QT_MOC_LITERAL(9, 124, 14), // "downloadFinish"
QT_MOC_LITERAL(10, 139, 8), // "filePath"
QT_MOC_LITERAL(11, 148, 13), // "downloadError"
QT_MOC_LITERAL(12, 162, 13), // "installFilish"
QT_MOC_LITERAL(13, 176, 11) // "installFlag"

    },
    "QDownloadSoftware\0sigInstallFinlished\0"
    "\0switchEinSignal\0downClose\0onDownloadProcess\0"
    "bytesReceived\0bytesTotal\0resetPushButton\0"
    "downloadFinish\0filePath\0downloadError\0"
    "installFilish\0installFlag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDownloadSoftware[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       3,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   64,    2, 0x08 /* Private */,
       5,    2,   65,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    2,   71,    2, 0x08 /* Private */,
      11,    1,   76,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,   10,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,   13,

       0        // eod
};

void QDownloadSoftware::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDownloadSoftware *_t = static_cast<QDownloadSoftware *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigInstallFinlished((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->switchEinSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->downClose(); break;
        case 3: _t->onDownloadProcess((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 4: _t->resetPushButton(); break;
        case 5: _t->downloadFinish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->downloadError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->installFilish((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QDownloadSoftware::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDownloadSoftware::sigInstallFinlished)) {
                *result = 0;
            }
        }
        {
            typedef void (QDownloadSoftware::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QDownloadSoftware::switchEinSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject QDownloadSoftware::staticMetaObject = {
    { &AppCommDialog::staticMetaObject, qt_meta_stringdata_QDownloadSoftware.data,
      qt_meta_data_QDownloadSoftware,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QDownloadSoftware::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDownloadSoftware::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QDownloadSoftware.stringdata0))
        return static_cast<void*>(const_cast< QDownloadSoftware*>(this));
    return AppCommDialog::qt_metacast(_clname);
}

int QDownloadSoftware::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AppCommDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QDownloadSoftware::sigInstallFinlished(QString _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QDownloadSoftware::switchEinSignal(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
