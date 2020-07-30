/****************************************************************************
** Meta object code from reading C++ file 'ZcloudMsgCenterImpl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ZcloudMsgCenterImpl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZcloudMsgCenterImpl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZcloudMsgCenterImpl_t {
    QByteArrayData data[6];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZcloudMsgCenterImpl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZcloudMsgCenterImpl_t qt_meta_stringdata_ZcloudMsgCenterImpl = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ZcloudMsgCenterImpl"
QT_MOC_LITERAL(1, 20, 13), // "reviceMsgInfo"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 12), // "strParamList"
QT_MOC_LITERAL(4, 48, 6), // "nCount"
QT_MOC_LITERAL(5, 55, 18) // "reviceActivityInfo"

    },
    "ZcloudMsgCenterImpl\0reviceMsgInfo\0\0"
    "strParamList\0nCount\0reviceActivityInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZcloudMsgCenterImpl[] = {

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
       1,    2,   24,    2, 0x08 /* Private */,
       5,    1,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QStringList,    3,

       0        // eod
};

void ZcloudMsgCenterImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZcloudMsgCenterImpl *_t = static_cast<ZcloudMsgCenterImpl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reviceMsgInfo((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->reviceActivityInfo((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ZcloudMsgCenterImpl::staticMetaObject = {
    { &ZcloudMsgCenter::staticMetaObject, qt_meta_stringdata_ZcloudMsgCenterImpl.data,
      qt_meta_data_ZcloudMsgCenterImpl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZcloudMsgCenterImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZcloudMsgCenterImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZcloudMsgCenterImpl.stringdata0))
        return static_cast<void*>(const_cast< ZcloudMsgCenterImpl*>(this));
    return ZcloudMsgCenter::qt_metacast(_clname);
}

int ZcloudMsgCenterImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ZcloudMsgCenter::qt_metacall(_c, _id, _a);
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
