/****************************************************************************
** Meta object code from reading C++ file 'ZcloudDeskUpdater.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ZcloudDeskUpdater.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZcloudDeskUpdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZcloudDeskUpdater_t {
    QByteArrayData data[6];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZcloudDeskUpdater_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZcloudDeskUpdater_t qt_meta_stringdata_ZcloudDeskUpdater = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ZcloudDeskUpdater"
QT_MOC_LITERAL(1, 18, 10), // "onTimerOut"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "onDownloadProgress"
QT_MOC_LITERAL(4, 49, 13), // "bytesReceived"
QT_MOC_LITERAL(5, 63, 10) // "bytesTotal"

    },
    "ZcloudDeskUpdater\0onTimerOut\0\0"
    "onDownloadProgress\0bytesReceived\0"
    "bytesTotal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZcloudDeskUpdater[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    2,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    4,    5,

       0        // eod
};

void ZcloudDeskUpdater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZcloudDeskUpdater *_t = static_cast<ZcloudDeskUpdater *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTimerOut(); break;
        case 1: _t->onDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject ZcloudDeskUpdater::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ZcloudDeskUpdater.data,
      qt_meta_data_ZcloudDeskUpdater,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZcloudDeskUpdater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZcloudDeskUpdater::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZcloudDeskUpdater.stringdata0))
        return static_cast<void*>(const_cast< ZcloudDeskUpdater*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ZcloudDeskUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
