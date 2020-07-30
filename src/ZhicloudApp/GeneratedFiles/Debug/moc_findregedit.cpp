/****************************************************************************
** Meta object code from reading C++ file 'findregedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AppCenter/findregedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findregedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FindRegedit_t {
    QByteArrayData data[5];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FindRegedit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FindRegedit_t qt_meta_stringdata_FindRegedit = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FindRegedit"
QT_MOC_LITERAL(1, 12, 26), // "installationCompleteSiganl"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 12), // "AppDataInfo*"
QT_MOC_LITERAL(4, 53, 28) // "uninstallationCompleteSiganl"

    },
    "FindRegedit\0installationCompleteSiganl\0"
    "\0AppDataInfo*\0uninstallationCompleteSiganl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FindRegedit[] = {

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
       4,    1,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void FindRegedit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FindRegedit *_t = static_cast<FindRegedit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->installationCompleteSiganl((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< AppDataInfo*(*)>(_a[2]))); break;
        case 1: _t->uninstallationCompleteSiganl((*reinterpret_cast< AppDataInfo*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FindRegedit::*_t)(QString , AppDataInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FindRegedit::installationCompleteSiganl)) {
                *result = 0;
            }
        }
        {
            typedef void (FindRegedit::*_t)(AppDataInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FindRegedit::uninstallationCompleteSiganl)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject FindRegedit::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_FindRegedit.data,
      qt_meta_data_FindRegedit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FindRegedit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FindRegedit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FindRegedit.stringdata0))
        return static_cast<void*>(const_cast< FindRegedit*>(this));
    return QThread::qt_metacast(_clname);
}

int FindRegedit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FindRegedit::installationCompleteSiganl(QString _t1, AppDataInfo * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FindRegedit::uninstallationCompleteSiganl(AppDataInfo * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_UnInstallThread_t {
    QByteArrayData data[5];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UnInstallThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UnInstallThread_t qt_meta_stringdata_UnInstallThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "UnInstallThread"
QT_MOC_LITERAL(1, 16, 28), // "uninstallationCompleteSiganl"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 11), // "AppDataInfo"
QT_MOC_LITERAL(4, 58, 21) // "removeUninstallThread"

    },
    "UnInstallThread\0uninstallationCompleteSiganl\0"
    "\0AppDataInfo\0removeUninstallThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnInstallThread[] = {

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
       4,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,    2,
    QMetaType::Void,

       0        // eod
};

void UnInstallThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UnInstallThread *_t = static_cast<UnInstallThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->uninstallationCompleteSiganl((*reinterpret_cast< AppDataInfo(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->removeUninstallThread(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UnInstallThread::*_t)(AppDataInfo , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UnInstallThread::uninstallationCompleteSiganl)) {
                *result = 0;
            }
        }
        {
            typedef void (UnInstallThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UnInstallThread::removeUninstallThread)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject UnInstallThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_UnInstallThread.data,
      qt_meta_data_UnInstallThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UnInstallThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnInstallThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UnInstallThread.stringdata0))
        return static_cast<void*>(const_cast< UnInstallThread*>(this));
    return QThread::qt_metacast(_clname);
}

int UnInstallThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void UnInstallThread::uninstallationCompleteSiganl(AppDataInfo _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UnInstallThread::removeUninstallThread()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
struct qt_meta_stringdata_FindAppPath_t {
    QByteArrayData data[3];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FindAppPath_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FindAppPath_t qt_meta_stringdata_FindAppPath = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FindAppPath"
QT_MOC_LITERAL(1, 12, 23), // "filishFindAppPathSignal"
QT_MOC_LITERAL(2, 36, 0) // ""

    },
    "FindAppPath\0filishFindAppPathSignal\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FindAppPath[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void FindAppPath::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FindAppPath *_t = static_cast<FindAppPath *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filishFindAppPathSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FindAppPath::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FindAppPath::filishFindAppPathSignal)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FindAppPath::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_FindAppPath.data,
      qt_meta_data_FindAppPath,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FindAppPath::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FindAppPath::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FindAppPath.stringdata0))
        return static_cast<void*>(const_cast< FindAppPath*>(this));
    return QThread::qt_metacast(_clname);
}

int FindAppPath::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void FindAppPath::filishFindAppPathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
