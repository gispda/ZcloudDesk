/****************************************************************************
** Meta object code from reading C++ file 'InfoCenterWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../InfoCenterWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InfoCenterWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InfoCenterWidget_t {
    QByteArrayData data[12];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InfoCenterWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InfoCenterWidget_t qt_meta_stringdata_InfoCenterWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "InfoCenterWidget"
QT_MOC_LITERAL(1, 17, 12), // "sigNeedLogin"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "sigSwitchAcc"
QT_MOC_LITERAL(4, 44, 9), // "needLogin"
QT_MOC_LITERAL(5, 54, 13), // "showEntCenter"
QT_MOC_LITERAL(6, 68, 14), // "showUserCenter"
QT_MOC_LITERAL(7, 83, 11), // "onSwitchAcc"
QT_MOC_LITERAL(8, 95, 11), // "bLoginByTax"
QT_MOC_LITERAL(9, 107, 6), // "bOther"
QT_MOC_LITERAL(10, 114, 17), // "strTaxNo_userName"
QT_MOC_LITERAL(11, 132, 6) // "strPwd"

    },
    "InfoCenterWidget\0sigNeedLogin\0\0"
    "sigSwitchAcc\0needLogin\0showEntCenter\0"
    "showUserCenter\0onSwitchAcc\0bLoginByTax\0"
    "bOther\0strTaxNo_userName\0strPwd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InfoCenterWidget[] = {

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
       1,    0,   44,    2, 0x06 /* Public */,
       3,    4,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   54,    2, 0x08 /* Private */,
       5,    0,   55,    2, 0x08 /* Private */,
       6,    0,   56,    2, 0x08 /* Private */,
       7,    4,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,

       0        // eod
};

void InfoCenterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InfoCenterWidget *_t = static_cast<InfoCenterWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigNeedLogin(); break;
        case 1: _t->sigSwitchAcc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->needLogin(); break;
        case 3: _t->showEntCenter(); break;
        case 4: _t->showUserCenter(); break;
        case 5: _t->onSwitchAcc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (InfoCenterWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InfoCenterWidget::sigNeedLogin)) {
                *result = 0;
            }
        }
        {
            typedef void (InfoCenterWidget::*_t)(int , bool , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InfoCenterWidget::sigSwitchAcc)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject InfoCenterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InfoCenterWidget.data,
      qt_meta_data_InfoCenterWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InfoCenterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InfoCenterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InfoCenterWidget.stringdata0))
        return static_cast<void*>(const_cast< InfoCenterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int InfoCenterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void InfoCenterWidget::sigNeedLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void InfoCenterWidget::sigSwitchAcc(int _t1, bool _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
