/****************************************************************************
** Meta object code from reading C++ file 'JsInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/JsInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JsInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_JsInterface_t {
    QByteArrayData data[27];
    char stringdata0[430];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JsInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JsInterface_t qt_meta_stringdata_JsInterface = {
    {
QT_MOC_LITERAL(0, 0, 11), // "JsInterface"
QT_MOC_LITERAL(1, 12, 21), // "sigAccountSetSucessed"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 7), // "strName"
QT_MOC_LITERAL(4, 43, 6), // "strJob"
QT_MOC_LITERAL(5, 50, 13), // "sigGetVipList"
QT_MOC_LITERAL(6, 64, 7), // "strJson"
QT_MOC_LITERAL(7, 72, 18), // "signalBindingPhone"
QT_MOC_LITERAL(8, 91, 17), // "sigSignInSucessed"
QT_MOC_LITERAL(9, 109, 9), // "bSucessed"
QT_MOC_LITERAL(10, 119, 24), // "sigWallpaperDownloadLink"
QT_MOC_LITERAL(11, 144, 16), // "strDwownloadLink"
QT_MOC_LITERAL(12, 161, 22), // "sigSignCompeteSucessed"
QT_MOC_LITERAL(13, 184, 23), // "sigSignBindingSucceeded"
QT_MOC_LITERAL(14, 208, 9), // "strMobile"
QT_MOC_LITERAL(15, 218, 15), // "sigCommitStatue"
QT_MOC_LITERAL(16, 234, 23), // "changeUserIdtokenSignal"
QT_MOC_LITERAL(17, 258, 18), // "accountSetSucessed"
QT_MOC_LITERAL(18, 277, 10), // "getVipList"
QT_MOC_LITERAL(19, 288, 16), // "slotBindingPhone"
QT_MOC_LITERAL(20, 305, 14), // "signInSucessed"
QT_MOC_LITERAL(21, 320, 17), // "wallpaperDownload"
QT_MOC_LITERAL(22, 338, 15), // "strDownloadLink"
QT_MOC_LITERAL(23, 354, 22), // "enterpriseDataSucessed"
QT_MOC_LITERAL(24, 377, 18), // "slotOpenDefaultWeb"
QT_MOC_LITERAL(25, 396, 20), // "slotBindingSucceeded"
QT_MOC_LITERAL(26, 417, 12) // "commitStatue"

    },
    "JsInterface\0sigAccountSetSucessed\0\0"
    "strName\0strJob\0sigGetVipList\0strJson\0"
    "signalBindingPhone\0sigSignInSucessed\0"
    "bSucessed\0sigWallpaperDownloadLink\0"
    "strDwownloadLink\0sigSignCompeteSucessed\0"
    "sigSignBindingSucceeded\0strMobile\0"
    "sigCommitStatue\0changeUserIdtokenSignal\0"
    "accountSetSucessed\0getVipList\0"
    "slotBindingPhone\0signInSucessed\0"
    "wallpaperDownload\0strDownloadLink\0"
    "enterpriseDataSucessed\0slotOpenDefaultWeb\0"
    "slotBindingSucceeded\0commitStatue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JsInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  104,    2, 0x06 /* Public */,
       5,    1,  109,    2, 0x06 /* Public */,
       7,    0,  112,    2, 0x06 /* Public */,
       8,    2,  113,    2, 0x06 /* Public */,
      10,    1,  118,    2, 0x06 /* Public */,
      12,    2,  121,    2, 0x06 /* Public */,
      13,    1,  126,    2, 0x06 /* Public */,
      15,    1,  129,    2, 0x06 /* Public */,
      16,    2,  132,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    2,  137,    2, 0x0a /* Public */,
      18,    1,  142,    2, 0x0a /* Public */,
      19,    0,  145,    2, 0x0a /* Public */,
      20,    2,  146,    2, 0x0a /* Public */,
      21,    1,  151,    2, 0x0a /* Public */,
      23,    2,  154,    2, 0x0a /* Public */,
      24,    1,  159,    2, 0x0a /* Public */,
      25,    1,  162,    2, 0x0a /* Public */,
      26,    1,  165,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    9,    2,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    9,    2,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void JsInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JsInterface *_t = static_cast<JsInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAccountSetSucessed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->sigGetVipList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->signalBindingPhone(); break;
        case 3: _t->sigSignInSucessed((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->sigWallpaperDownloadLink((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->sigSignCompeteSucessed((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->sigSignBindingSucceeded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->sigCommitStatue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->changeUserIdtokenSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->accountSetSucessed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 10: _t->getVipList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->slotBindingPhone(); break;
        case 12: _t->signInSucessed((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->wallpaperDownload((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->enterpriseDataSucessed((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->slotOpenDefaultWeb((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->slotBindingSucceeded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->commitStatue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (JsInterface::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsInterface::sigAccountSetSucessed)) {
                *result = 0;
            }
        }
        {
            typedef void (JsInterface::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsInterface::sigGetVipList)) {
                *result = 1;
            }
        }
        {
            typedef void (JsInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsInterface::signalBindingPhone)) {
                *result = 2;
            }
        }
        {
            typedef void (JsInterface::*_t)(bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsInterface::sigSignInSucessed)) {
                *result = 3;
            }
        }
        {
            typedef void (JsInterface::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsInterface::sigWallpaperDownloadLink)) {
                *result = 4;
            }
        }
        {
            typedef void (JsInterface::*_t)(bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsInterface::sigSignCompeteSucessed)) {
                *result = 5;
            }
        }
        {
            typedef void (JsInterface::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsInterface::sigSignBindingSucceeded)) {
                *result = 6;
            }
        }
        {
            typedef void (JsInterface::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsInterface::sigCommitStatue)) {
                *result = 7;
            }
        }
        {
            typedef void (JsInterface::*_t)(const QString , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&JsInterface::changeUserIdtokenSignal)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject JsInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JsInterface.data,
      qt_meta_data_JsInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *JsInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JsInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_JsInterface.stringdata0))
        return static_cast<void*>(const_cast< JsInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int JsInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void JsInterface::sigAccountSetSucessed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JsInterface::sigGetVipList(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JsInterface::signalBindingPhone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void JsInterface::sigSignInSucessed(bool _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JsInterface::sigWallpaperDownloadLink(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void JsInterface::sigSignCompeteSucessed(bool _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void JsInterface::sigSignBindingSucceeded(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void JsInterface::sigCommitStatue(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void JsInterface::changeUserIdtokenSignal(const QString _t1, const QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
