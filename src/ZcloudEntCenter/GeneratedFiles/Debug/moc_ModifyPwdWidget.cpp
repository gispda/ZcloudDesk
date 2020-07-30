/****************************************************************************
** Meta object code from reading C++ file 'ModifyPwdWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ModifyPwdWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModifyPwdWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModifyPwdWidget_t {
    QByteArrayData data[8];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModifyPwdWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModifyPwdWidget_t qt_meta_stringdata_ModifyPwdWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ModifyPwdWidget"
QT_MOC_LITERAL(1, 16, 19), // "sigResetPwdSucessed"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 12), // "sigForgetPwd"
QT_MOC_LITERAL(4, 50, 18), // "onModifyOkBtnClick"
QT_MOC_LITERAL(5, 69, 20), // "onOldPwdEditBtnClick"
QT_MOC_LITERAL(6, 90, 20), // "onNewPwdEditBtnClick"
QT_MOC_LITERAL(7, 111, 24) // "onComfirmPwdEditBtnClick"

    },
    "ModifyPwdWidget\0sigResetPwdSucessed\0"
    "\0sigForgetPwd\0onModifyOkBtnClick\0"
    "onOldPwdEditBtnClick\0onNewPwdEditBtnClick\0"
    "onComfirmPwdEditBtnClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModifyPwdWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       3,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   50,    2, 0x08 /* Private */,
       5,    0,   51,    2, 0x08 /* Private */,
       6,    0,   52,    2, 0x08 /* Private */,
       7,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ModifyPwdWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModifyPwdWidget *_t = static_cast<ModifyPwdWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigResetPwdSucessed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->sigForgetPwd(); break;
        case 2: _t->onModifyOkBtnClick(); break;
        case 3: _t->onOldPwdEditBtnClick(); break;
        case 4: _t->onNewPwdEditBtnClick(); break;
        case 5: _t->onComfirmPwdEditBtnClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModifyPwdWidget::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModifyPwdWidget::sigResetPwdSucessed)) {
                *result = 0;
            }
        }
        {
            typedef void (ModifyPwdWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModifyPwdWidget::sigForgetPwd)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ModifyPwdWidget::staticMetaObject = {
    { &ZcloudCommonWidget::staticMetaObject, qt_meta_stringdata_ModifyPwdWidget.data,
      qt_meta_data_ModifyPwdWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModifyPwdWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModifyPwdWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModifyPwdWidget.stringdata0))
        return static_cast<void*>(const_cast< ModifyPwdWidget*>(this));
    return ZcloudCommonWidget::qt_metacast(_clname);
}

int ModifyPwdWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ZcloudCommonWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ModifyPwdWidget::sigResetPwdSucessed(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModifyPwdWidget::sigForgetPwd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
