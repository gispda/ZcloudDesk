/****************************************************************************
** Meta object code from reading C++ file 'EntComWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EntComWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EntComWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EntComWidget_t {
    QByteArrayData data[12];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EntComWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EntComWidget_t qt_meta_stringdata_EntComWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EntComWidget"
QT_MOC_LITERAL(1, 13, 22), // "sigSignCompeteSucessed"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "sigAccountSetSucessed"
QT_MOC_LITERAL(4, 59, 7), // "strName"
QT_MOC_LITERAL(5, 67, 6), // "strJob"
QT_MOC_LITERAL(6, 74, 22), // "sigSignCompanySucessed"
QT_MOC_LITERAL(7, 97, 23), // "sigSignBindingSucceeded"
QT_MOC_LITERAL(8, 121, 18), // "sendVipListSignals"
QT_MOC_LITERAL(9, 140, 11), // "closeWindow"
QT_MOC_LITERAL(10, 152, 14), // "onLoadFinished"
QT_MOC_LITERAL(11, 167, 12) // "onGetVipList"

    },
    "EntComWidget\0sigSignCompeteSucessed\0"
    "\0sigAccountSetSucessed\0strName\0strJob\0"
    "sigSignCompanySucessed\0sigSignBindingSucceeded\0"
    "sendVipListSignals\0closeWindow\0"
    "onLoadFinished\0onGetVipList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EntComWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       3,    2,   59,    2, 0x06 /* Public */,
       6,    2,   64,    2, 0x06 /* Public */,
       7,    1,   69,    2, 0x06 /* Public */,
       8,    3,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   79,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void EntComWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EntComWidget *_t = static_cast<EntComWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSignCompeteSucessed((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sigAccountSetSucessed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->sigSignCompanySucessed((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->sigSignBindingSucceeded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->sendVipListSignals((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 5: _t->closeWindow(); break;
        case 6: _t->onLoadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->onGetVipList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EntComWidget::*_t)(bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntComWidget::sigSignCompeteSucessed)) {
                *result = 0;
            }
        }
        {
            typedef void (EntComWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntComWidget::sigAccountSetSucessed)) {
                *result = 1;
            }
        }
        {
            typedef void (EntComWidget::*_t)(bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntComWidget::sigSignCompanySucessed)) {
                *result = 2;
            }
        }
        {
            typedef void (EntComWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntComWidget::sigSignBindingSucceeded)) {
                *result = 3;
            }
        }
        {
            typedef void (EntComWidget::*_t)(QStringList , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntComWidget::sendVipListSignals)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject EntComWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EntComWidget.data,
      qt_meta_data_EntComWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EntComWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EntComWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EntComWidget.stringdata0))
        return static_cast<void*>(const_cast< EntComWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int EntComWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void EntComWidget::sigSignCompeteSucessed(bool _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EntComWidget::sigAccountSetSucessed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EntComWidget::sigSignCompanySucessed(bool _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EntComWidget::sigSignBindingSucceeded(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EntComWidget::sendVipListSignals(QStringList _t1, QStringList _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
