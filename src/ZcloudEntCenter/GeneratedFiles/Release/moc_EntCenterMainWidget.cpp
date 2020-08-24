/****************************************************************************
** Meta object code from reading C++ file 'EntCenterMainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EntCenterMainWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EntCenterMainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EntCenterMainWidget_t {
    QByteArrayData data[7];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EntCenterMainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EntCenterMainWidget_t qt_meta_stringdata_EntCenterMainWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "EntCenterMainWidget"
QT_MOC_LITERAL(1, 20, 12), // "sigNeedLogin"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "bingdingPhoneSignal"
QT_MOC_LITERAL(4, 54, 23), // "sigSignBindingSucceeded"
QT_MOC_LITERAL(5, 78, 9), // "strMobile"
QT_MOC_LITERAL(6, 88, 20) // "onServiceFeeBtnClick"

    },
    "EntCenterMainWidget\0sigNeedLogin\0\0"
    "bingdingPhoneSignal\0sigSignBindingSucceeded\0"
    "strMobile\0onServiceFeeBtnClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EntCenterMainWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void EntCenterMainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EntCenterMainWidget *_t = static_cast<EntCenterMainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigNeedLogin(); break;
        case 1: _t->bingdingPhoneSignal(); break;
        case 2: _t->sigSignBindingSucceeded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onServiceFeeBtnClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EntCenterMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntCenterMainWidget::sigNeedLogin)) {
                *result = 0;
            }
        }
        {
            typedef void (EntCenterMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntCenterMainWidget::bingdingPhoneSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (EntCenterMainWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntCenterMainWidget::sigSignBindingSucceeded)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject EntCenterMainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EntCenterMainWidget.data,
      qt_meta_data_EntCenterMainWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EntCenterMainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EntCenterMainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EntCenterMainWidget.stringdata0))
        return static_cast<void*>(const_cast< EntCenterMainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int EntCenterMainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void EntCenterMainWidget::sigNeedLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void EntCenterMainWidget::bingdingPhoneSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void EntCenterMainWidget::sigSignBindingSucceeded(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
