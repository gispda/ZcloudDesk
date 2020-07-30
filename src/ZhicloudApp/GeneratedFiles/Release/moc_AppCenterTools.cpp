/****************************************************************************
** Meta object code from reading C++ file 'AppCenterTools.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AppCenter/AppCenterTools.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppCenterTools.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AppCenterTools_t {
    QByteArrayData data[19];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppCenterTools_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppCenterTools_t qt_meta_stringdata_AppCenterTools = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AppCenterTools"
QT_MOC_LITERAL(1, 15, 21), // "addDownloadItemSignal"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 16), // "AppDownLoadItem*"
QT_MOC_LITERAL(4, 55, 18), // "toolsStatusChanged"
QT_MOC_LITERAL(5, 74, 9), // "APPSTATUS"
QT_MOC_LITERAL(6, 84, 22), // "startDownloadAppSignal"
QT_MOC_LITERAL(7, 107, 5), // "appId"
QT_MOC_LITERAL(8, 113, 15), // "updateUninstall"
QT_MOC_LITERAL(9, 129, 20), // "clickedStautusButton"
QT_MOC_LITERAL(10, 150, 13), // "onRecommended"
QT_MOC_LITERAL(11, 164, 12), // "unstallFlish"
QT_MOC_LITERAL(12, 177, 11), // "AppDataInfo"
QT_MOC_LITERAL(13, 189, 4), // "flag"
QT_MOC_LITERAL(14, 194, 20), // "startDownloadAppSlot"
QT_MOC_LITERAL(15, 215, 16), // "unInstallSucceed"
QT_MOC_LITERAL(16, 232, 23), // "onDownloadStatusChanged"
QT_MOC_LITERAL(17, 256, 16), // "APPDOWNLOADETYPE"
QT_MOC_LITERAL(18, 273, 4) // "type"

    },
    "AppCenterTools\0addDownloadItemSignal\0"
    "\0AppDownLoadItem*\0toolsStatusChanged\0"
    "APPSTATUS\0startDownloadAppSignal\0appId\0"
    "updateUninstall\0clickedStautusButton\0"
    "onRecommended\0unstallFlish\0AppDataInfo\0"
    "flag\0startDownloadAppSlot\0unInstallSucceed\0"
    "onDownloadStatusChanged\0APPDOWNLOADETYPE\0"
    "type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppCenterTools[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    2,   76,    2, 0x08 /* Private */,
      14,    1,   81,    2, 0x08 /* Private */,
      15,    2,   84,    2, 0x08 /* Private */,
      16,    1,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Bool,    2,   13,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Bool,    2,   13,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void AppCenterTools::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppCenterTools *_t = static_cast<AppCenterTools *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addDownloadItemSignal((*reinterpret_cast< AppDownLoadItem*(*)>(_a[1]))); break;
        case 1: _t->toolsStatusChanged((*reinterpret_cast< APPSTATUS(*)>(_a[1]))); break;
        case 2: _t->startDownloadAppSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updateUninstall(); break;
        case 4: _t->clickedStautusButton(); break;
        case 5: _t->onRecommended(); break;
        case 6: _t->unstallFlish((*reinterpret_cast< AppDataInfo(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->startDownloadAppSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->unInstallSucceed((*reinterpret_cast< AppDataInfo(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->onDownloadStatusChanged((*reinterpret_cast< APPDOWNLOADETYPE(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AppDownLoadItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AppCenterTools::*_t)(AppDownLoadItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppCenterTools::addDownloadItemSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (AppCenterTools::*_t)(APPSTATUS );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppCenterTools::toolsStatusChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (AppCenterTools::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppCenterTools::startDownloadAppSignal)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject AppCenterTools::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_AppCenterTools.data,
      qt_meta_data_AppCenterTools,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AppCenterTools::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppCenterTools::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AppCenterTools.stringdata0))
        return static_cast<void*>(const_cast< AppCenterTools*>(this));
    return QPushButton::qt_metacast(_clname);
}

int AppCenterTools::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void AppCenterTools::addDownloadItemSignal(AppDownLoadItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppCenterTools::toolsStatusChanged(APPSTATUS _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AppCenterTools::startDownloadAppSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
