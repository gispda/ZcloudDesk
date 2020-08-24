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
    QByteArrayData data[8];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserCenterWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserCenterWidget_t qt_meta_stringdata_UserCenterWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "UserCenterWidget"
QT_MOC_LITERAL(1, 17, 12), // "sigNeedLogin"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "needLogin"
QT_MOC_LITERAL(4, 41, 12), // "onChangeCoin"
QT_MOC_LITERAL(5, 54, 5), // "nCoin"
QT_MOC_LITERAL(6, 60, 9), // "onShowAcc"
QT_MOC_LITERAL(7, 70, 10) // "onShowMain"

    },
    "UserCenterWidget\0sigNeedLogin\0\0needLogin\0"
    "onChangeCoin\0nCoin\0onShowAcc\0onShowMain"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserCenterWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
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
        case 0: _t->sigNeedLogin(); break;
        case 1: _t->needLogin(); break;
        case 2: _t->onChangeCoin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onShowAcc(); break;
        case 4: _t->onShowMain(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UserCenterWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterWidget::sigNeedLogin)) {
                *result = 0;
            }
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void UserCenterWidget::sigNeedLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
