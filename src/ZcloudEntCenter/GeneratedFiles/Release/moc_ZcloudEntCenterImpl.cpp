/****************************************************************************
** Meta object code from reading C++ file 'ZcloudEntCenterImpl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ZcloudEntCenterImpl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZcloudEntCenterImpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZcloudEntCenterImpl_t {
    QByteArrayData data[10];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZcloudEntCenterImpl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZcloudEntCenterImpl_t qt_meta_stringdata_ZcloudEntCenterImpl = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ZcloudEntCenterImpl"
QT_MOC_LITERAL(1, 20, 12), // "sigNeedLogin"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "sigSwitchAcc"
QT_MOC_LITERAL(4, 47, 9), // "needLogin"
QT_MOC_LITERAL(5, 57, 11), // "onSwitchAcc"
QT_MOC_LITERAL(6, 69, 11), // "bLoginByTax"
QT_MOC_LITERAL(7, 81, 6), // "bOther"
QT_MOC_LITERAL(8, 88, 17), // "strTaxNo_userName"
QT_MOC_LITERAL(9, 106, 6) // "strPwd"

    },
    "ZcloudEntCenterImpl\0sigNeedLogin\0\0"
    "sigSwitchAcc\0needLogin\0onSwitchAcc\0"
    "bLoginByTax\0bOther\0strTaxNo_userName\0"
    "strPwd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZcloudEntCenterImpl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    4,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   44,    2, 0x0a /* Public */,
       5,    4,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,

       0        // eod
};

void ZcloudEntCenterImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZcloudEntCenterImpl *_t = static_cast<ZcloudEntCenterImpl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigNeedLogin(); break;
        case 1: _t->sigSwitchAcc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->needLogin(); break;
        case 3: _t->onSwitchAcc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ZcloudEntCenterImpl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudEntCenterImpl::sigNeedLogin)) {
                *result = 0;
            }
        }
        {
            typedef void (ZcloudEntCenterImpl::*_t)(int , bool , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudEntCenterImpl::sigSwitchAcc)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ZcloudEntCenterImpl::staticMetaObject = {
    { &ZcloudEntCenter::staticMetaObject, qt_meta_stringdata_ZcloudEntCenterImpl.data,
      qt_meta_data_ZcloudEntCenterImpl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZcloudEntCenterImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZcloudEntCenterImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZcloudEntCenterImpl.stringdata0))
        return static_cast<void*>(const_cast< ZcloudEntCenterImpl*>(this));
    return ZcloudEntCenter::qt_metacast(_clname);
}

int ZcloudEntCenterImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ZcloudEntCenter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ZcloudEntCenterImpl::sigNeedLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ZcloudEntCenterImpl::sigSwitchAcc(int _t1, bool _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
