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
    QByteArrayData data[12];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserCenterAccWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserCenterAccWidget_t qt_meta_stringdata_UserCenterAccWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "UserCenterAccWidget"
QT_MOC_LITERAL(1, 20, 12), // "sigNeedLogin"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "sigChangeCoin"
QT_MOC_LITERAL(4, 48, 23), // "sigEditUserInfoSucessed"
QT_MOC_LITERAL(5, 72, 21), // "sigBindMobileSucessed"
QT_MOC_LITERAL(6, 94, 19), // "bingdingPhoneSignal"
QT_MOC_LITERAL(7, 114, 23), // "sigSignBindingSucceeded"
QT_MOC_LITERAL(8, 138, 9), // "strMobile"
QT_MOC_LITERAL(9, 148, 16), // "openSignInWidget"
QT_MOC_LITERAL(10, 165, 8), // "QWidget*"
QT_MOC_LITERAL(11, 174, 17) // "onEntInfoBtnClick"

    },
    "UserCenterAccWidget\0sigNeedLogin\0\0"
    "sigChangeCoin\0sigEditUserInfoSucessed\0"
    "sigBindMobileSucessed\0bingdingPhoneSignal\0"
    "sigSignBindingSucceeded\0strMobile\0"
    "openSignInWidget\0QWidget*\0onEntInfoBtnClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserCenterAccWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       4,    2,   58,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,
       6,    0,   66,    2, 0x06 /* Public */,
       7,    1,   67,    2, 0x06 /* Public */,
       9,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, 0x80000000 | 10,    2,

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
        case 0: _t->sigNeedLogin(); break;
        case 1: _t->sigChangeCoin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigEditUserInfoSucessed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->sigBindMobileSucessed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->bingdingPhoneSignal(); break;
        case 5: _t->sigSignBindingSucceeded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->openSignInWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 7: _t->onEntInfoBtnClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
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
            typedef void (UserCenterAccWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::sigNeedLogin)) {
                *result = 0;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::sigChangeCoin)) {
                *result = 1;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::sigEditUserInfoSucessed)) {
                *result = 2;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::sigBindMobileSucessed)) {
                *result = 3;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::bingdingPhoneSignal)) {
                *result = 4;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::sigSignBindingSucceeded)) {
                *result = 5;
            }
        }
        {
            typedef void (UserCenterAccWidget::*_t)(QWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserCenterAccWidget::openSignInWidget)) {
                *result = 6;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void UserCenterAccWidget::sigNeedLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void UserCenterAccWidget::sigChangeCoin(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UserCenterAccWidget::sigEditUserInfoSucessed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UserCenterAccWidget::sigBindMobileSucessed(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void UserCenterAccWidget::bingdingPhoneSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void UserCenterAccWidget::sigSignBindingSucceeded(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void UserCenterAccWidget::openSignInWidget(QWidget * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
