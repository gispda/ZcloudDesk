/****************************************************************************
** Meta object code from reading C++ file 'UserCenterMainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UserCenterMainWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserCenterMainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserCenterMainWidget_t {
    QByteArrayData data[11];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserCenterMainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserCenterMainWidget_t qt_meta_stringdata_UserCenterMainWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "UserCenterMainWidget"
QT_MOC_LITERAL(1, 21, 12), // "sigNeedLogin"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "openSignInWidget"
QT_MOC_LITERAL(4, 52, 8), // "QWidget*"
QT_MOC_LITERAL(5, 61, 23), // "sigSignBindingSucceeded"
QT_MOC_LITERAL(6, 85, 9), // "strMobile"
QT_MOC_LITERAL(7, 95, 16), // "onSignInBtnClick"
QT_MOC_LITERAL(8, 112, 12), // "onChangeCoin"
QT_MOC_LITERAL(9, 125, 5), // "nCoin"
QT_MOC_LITERAL(10, 131, 21) // "onCompeteDataBtnClick"

    },
    "UserCenterMainWidget\0sigNeedLogin\0\0"
    "openSignInWidget\0QWidget*\0"
    "sigSignBindingSucceeded\0strMobile\0"
    "onSignInBtnClick\0onChangeCoin\0nCoin\0"
    "onCompeteDataBtnClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserCenterMainWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   51,    2, 0x08 /* Private */,
       8,    1,   52,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void UserCenterMainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserCenterMainWidget *_t = static_cast<UserCenterMainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigNeedLogin(); break;
        case 1: _t->openSignInWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->sigSignBindingSucceeded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onSignInBtnClick(); break;
        case 4: _t->onChangeCoin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onCompeteDataBtnClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UserCenterMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterMainWidget::sigNeedLogin)) {
                *result = 0;
            }
        }
        {
            typedef void (UserCenterMainWidget::*_t)(QWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterMainWidget::openSignInWidget)) {
                *result = 1;
            }
        }
        {
            typedef void (UserCenterMainWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterMainWidget::sigSignBindingSucceeded)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject UserCenterMainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserCenterMainWidget.data,
      qt_meta_data_UserCenterMainWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserCenterMainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserCenterMainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserCenterMainWidget.stringdata0))
        return static_cast<void*>(const_cast< UserCenterMainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserCenterMainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UserCenterMainWidget::sigNeedLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void UserCenterMainWidget::openSignInWidget(QWidget * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UserCenterMainWidget::sigSignBindingSucceeded(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
