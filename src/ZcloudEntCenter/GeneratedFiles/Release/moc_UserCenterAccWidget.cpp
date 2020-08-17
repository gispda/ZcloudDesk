/****************************************************************************
** Meta object code from reading C++ file 'UserCenterAccWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UserCenterAccWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserCenterAccWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserCenterAccWidget_t {
    QByteArrayData data[11];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserCenterAccWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserCenterAccWidget_t qt_meta_stringdata_UserCenterAccWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "UserCenterAccWidget"
QT_MOC_LITERAL(1, 20, 13), // "sigChangeCoin"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 23), // "sigEditUserInfoSucessed"
QT_MOC_LITERAL(4, 59, 21), // "sigBindMobileSucessed"
QT_MOC_LITERAL(5, 81, 19), // "bingdingPhoneSignal"
QT_MOC_LITERAL(6, 101, 23), // "sigSignBindingSucceeded"
QT_MOC_LITERAL(7, 125, 9), // "strMobile"
QT_MOC_LITERAL(8, 135, 16), // "openSignInWidget"
QT_MOC_LITERAL(9, 152, 8), // "QWidget*"
QT_MOC_LITERAL(10, 161, 17) // "onEntInfoBtnClick"

    },
    "UserCenterAccWidget\0sigChangeCoin\0\0"
    "sigEditUserInfoSucessed\0sigBindMobileSucessed\0"
    "bingdingPhoneSignal\0sigSignBindingSucceeded\0"
    "strMobile\0openSignInWidget\0QWidget*\0"
    "onEntInfoBtnClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserCenterAccWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    2,   52,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    0,   60,    2, 0x06 /* Public */,
       6,    1,   61,    2, 0x06 /* Public */,
       8,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void UserCenterAccWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserCenterAccWidget *_t = static_cast<UserCenterAccWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigChangeCoin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sigEditUserInfoSucessed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->sigBindMobileSucessed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->bingdingPhoneSignal(); break;
        case 4: _t->sigSignBindingSucceeded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->openSignInWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 6: _t->onEntInfoBtnClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
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
            typedef void (UserCenterAccWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::sigChangeCoin)) {
                *result = 0;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::sigEditUserInfoSucessed)) {
                *result = 1;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::sigBindMobileSucessed)) {
                *result = 2;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::bingdingPhoneSignal)) {
                *result = 3;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::sigSignBindingSucceeded)) {
                *result = 4;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)(QWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::openSignInWidget)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject UserCenterAccWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserCenterAccWidget.data,
      qt_meta_data_UserCenterAccWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UserCenterAccWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserCenterAccWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UserCenterAccWidget.stringdata0))
        return static_cast<void*>(const_cast< UserCenterAccWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserCenterAccWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void UserCenterAccWidget::sigChangeCoin(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserCenterAccWidget::sigEditUserInfoSucessed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UserCenterAccWidget::sigBindMobileSucessed(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UserCenterAccWidget::bingdingPhoneSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void UserCenterAccWidget::sigSignBindingSucceeded(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void UserCenterAccWidget::openSignInWidget(QWidget * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
