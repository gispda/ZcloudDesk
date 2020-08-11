/****************************************************************************
** Meta object code from reading C++ file 'UserCenterWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UserCenterWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserCenterWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserCenterWidget_t {
    QByteArrayData data[6];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserCenterWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserCenterWidget_t qt_meta_stringdata_UserCenterWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "UserCenterWidget"
QT_MOC_LITERAL(1, 17, 12), // "onChangeCoin"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "nCoin"
QT_MOC_LITERAL(4, 37, 9), // "onShowAcc"
QT_MOC_LITERAL(5, 47, 10) // "onShowMain"

    },
    "UserCenterWidget\0onChangeCoin\0\0nCoin\0"
    "onShowAcc\0onShowMain"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserCenterWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserCenterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserCenterWidget *_t = static_cast<UserCenterWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onChangeCoin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onShowAcc(); break;
        case 2: _t->onShowMain(); break;
        default: ;
        }
    }
}

const QMetaObject UserCenterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserCenterWidget.data,
      qt_meta_data_UserCenterWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserCenterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserCenterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserCenterWidget.stringdata0))
        return static_cast<void*>(const_cast< UserCenterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserCenterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
