/****************************************************************************
** Meta object code from reading C++ file 'AccSettingWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AccSettingWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AccSettingWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AccSettingWidget_t {
    QByteArrayData data[18];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccSettingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccSettingWidget_t qt_meta_stringdata_AccSettingWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AccSettingWidget"
QT_MOC_LITERAL(1, 17, 13), // "sigChangeCoin"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "sigEditUserInfoSucessed"
QT_MOC_LITERAL(4, 56, 21), // "sigBindMobileSucessed"
QT_MOC_LITERAL(5, 78, 24), // "onModifyUserInfoSucessed"
QT_MOC_LITERAL(6, 103, 5), // "nCoin"
QT_MOC_LITERAL(7, 109, 8), // "bPerfect"
QT_MOC_LITERAL(8, 118, 20), // "onBindMobileSucessed"
QT_MOC_LITERAL(9, 139, 19), // "onBindEmailSucessed"
QT_MOC_LITERAL(10, 159, 8), // "strEmail"
QT_MOC_LITERAL(11, 168, 20), // "onUpdateAddrSucessed"
QT_MOC_LITERAL(12, 189, 11), // "AddressInfo"
QT_MOC_LITERAL(13, 201, 8), // "addrInfo"
QT_MOC_LITERAL(14, 210, 18), // "onResetPwdSucessed"
QT_MOC_LITERAL(15, 229, 16), // "onSetPwdSucessed"
QT_MOC_LITERAL(16, 246, 11), // "onForgetPwd"
QT_MOC_LITERAL(17, 258, 24) // "onCheckForgetPwdSucessed"

    },
    "AccSettingWidget\0sigChangeCoin\0\0"
    "sigEditUserInfoSucessed\0sigBindMobileSucessed\0"
    "onModifyUserInfoSucessed\0nCoin\0bPerfect\0"
    "onBindMobileSucessed\0onBindEmailSucessed\0"
    "strEmail\0onUpdateAddrSucessed\0AddressInfo\0"
    "addrInfo\0onResetPwdSucessed\0"
    "onSetPwdSucessed\0onForgetPwd\0"
    "onCheckForgetPwdSucessed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccSettingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    2,   72,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   80,    2, 0x08 /* Private */,
       8,    2,   85,    2, 0x08 /* Private */,
       9,    3,   90,    2, 0x08 /* Private */,
      11,    3,   97,    2, 0x08 /* Private */,
      14,    2,  104,    2, 0x08 /* Private */,
      15,    2,  109,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool,   10,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, 0x80000000 | 12,    6,    7,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AccSettingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AccSettingWidget *_t = static_cast<AccSettingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigChangeCoin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sigEditUserInfoSucessed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->sigBindMobileSucessed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onModifyUserInfoSucessed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->onBindMobileSucessed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->onBindEmailSucessed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->onUpdateAddrSucessed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< AddressInfo(*)>(_a[3]))); break;
        case 7: _t->onResetPwdSucessed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->onSetPwdSucessed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->onForgetPwd(); break;
        case 10: _t->onCheckForgetPwdSucessed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AccSettingWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccSettingWidget::sigChangeCoin)) {
                *result = 0;
            }
        }
        {
            typedef void (AccSettingWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccSettingWidget::sigEditUserInfoSucessed)) {
                *result = 1;
            }
        }
        {
            typedef void (AccSettingWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AccSettingWidget::sigBindMobileSucessed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject AccSettingWidget::staticMetaObject = {
    { &ZcloudCommonWidget::staticMetaObject, qt_meta_stringdata_AccSettingWidget.data,
      qt_meta_data_AccSettingWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AccSettingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccSettingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AccSettingWidget.stringdata0))
        return static_cast<void*>(const_cast< AccSettingWidget*>(this));
    return ZcloudCommonWidget::qt_metacast(_clname);
}

int AccSettingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ZcloudCommonWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void AccSettingWidget::sigChangeCoin(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AccSettingWidget::sigEditUserInfoSucessed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AccSettingWidget::sigBindMobileSucessed(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
