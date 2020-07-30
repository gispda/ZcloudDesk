/****************************************************************************
** Meta object code from reading C++ file 'BindMobileWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BindMobileWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BindMobileWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BindMobileWidget_t {
    QByteArrayData data[8];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BindMobileWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BindMobileWidget_t qt_meta_stringdata_BindMobileWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "BindMobileWidget"
QT_MOC_LITERAL(1, 17, 21), // "sigBindMobileSucessed"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 25), // "sigCheckForgetPwdSucessed"
QT_MOC_LITERAL(4, 66, 22), // "onBindMobileOkBtnClick"
QT_MOC_LITERAL(5, 89, 23), // "onMobileEditingFinished"
QT_MOC_LITERAL(6, 113, 18), // "onSendCodeBtnClick"
QT_MOC_LITERAL(7, 132, 27) // "onMobileCodeEditingFinished"

    },
    "BindMobileWidget\0sigBindMobileSucessed\0"
    "\0sigCheckForgetPwdSucessed\0"
    "onBindMobileOkBtnClick\0onMobileEditingFinished\0"
    "onSendCodeBtnClick\0onMobileCodeEditingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BindMobileWidget[] = {

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

void BindMobileWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BindMobileWidget *_t = static_cast<BindMobileWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigBindMobileSucessed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->sigCheckForgetPwdSucessed(); break;
        case 2: _t->onBindMobileOkBtnClick(); break;
        case 3: _t->onMobileEditingFinished(); break;
        case 4: _t->onSendCodeBtnClick(); break;
        case 5: _t->onMobileCodeEditingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BindMobileWidget::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BindMobileWidget::sigBindMobileSucessed)) {
                *result = 0;
            }
        }
        {
            typedef void (BindMobileWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BindMobileWidget::sigCheckForgetPwdSucessed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject BindMobileWidget::staticMetaObject = {
    { &ZcloudCommonWidget::staticMetaObject, qt_meta_stringdata_BindMobileWidget.data,
      qt_meta_data_BindMobileWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BindMobileWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BindMobileWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BindMobileWidget.stringdata0))
        return static_cast<void*>(const_cast< BindMobileWidget*>(this));
    return ZcloudCommonWidget::qt_metacast(_clname);
}

int BindMobileWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void BindMobileWidget::sigBindMobileSucessed(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BindMobileWidget::sigCheckForgetPwdSucessed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
