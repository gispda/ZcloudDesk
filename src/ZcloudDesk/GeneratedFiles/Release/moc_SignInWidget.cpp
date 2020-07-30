/****************************************************************************
** Meta object code from reading C++ file 'SignInWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SignInWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SignInWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SignInTipWidget_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SignInTipWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SignInTipWidget_t qt_meta_stringdata_SignInTipWidget = {
    {
QT_MOC_LITERAL(0, 0, 15) // "SignInTipWidget"

    },
    "SignInTipWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SignInTipWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SignInTipWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SignInTipWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SignInTipWidget.data,
      qt_meta_data_SignInTipWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SignInTipWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignInTipWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SignInTipWidget.stringdata0))
        return static_cast<void*>(const_cast< SignInTipWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int SignInTipWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_SignInWidget_t {
    QByteArrayData data[9];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SignInWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SignInWidget_t qt_meta_stringdata_SignInWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SignInWidget"
QT_MOC_LITERAL(1, 13, 13), // "showAdvertPic"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "sigAdvertisingClick"
QT_MOC_LITERAL(4, 48, 15), // "modifyCoinCount"
QT_MOC_LITERAL(5, 64, 14), // "signInBtnClick"
QT_MOC_LITERAL(6, 79, 13), // "loadAdvertPic"
QT_MOC_LITERAL(7, 93, 10), // "strPicPath"
QT_MOC_LITERAL(8, 104, 15) // "onShowAdvertPic"

    },
    "SignInWidget\0showAdvertPic\0\0"
    "sigAdvertisingClick\0modifyCoinCount\0"
    "signInBtnClick\0loadAdvertPic\0strPicPath\0"
    "onShowAdvertPic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SignInWidget[] = {

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
       1,    1,   44,    2, 0x06 /* Public */,
       3,    2,   47,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   55,    2, 0x08 /* Private */,
       6,    1,   56,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void SignInWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SignInWidget *_t = static_cast<SignInWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showAdvertPic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigAdvertisingClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->modifyCoinCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signInBtnClick(); break;
        case 4: _t->loadAdvertPic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->onShowAdvertPic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SignInWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignInWidget::showAdvertPic)) {
                *result = 0;
            }
        }
        {
            typedef void (SignInWidget::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignInWidget::sigAdvertisingClick)) {
                *result = 1;
            }
        }
        {
            typedef void (SignInWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignInWidget::modifyCoinCount)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject SignInWidget::staticMetaObject = {
    { &ZcloudCommonWidget::staticMetaObject, qt_meta_stringdata_SignInWidget.data,
      qt_meta_data_SignInWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SignInWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignInWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SignInWidget.stringdata0))
        return static_cast<void*>(const_cast< SignInWidget*>(this));
    return ZcloudCommonWidget::qt_metacast(_clname);
}

int SignInWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SignInWidget::showAdvertPic(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SignInWidget::sigAdvertisingClick(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SignInWidget::modifyCoinCount(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
