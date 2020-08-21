/****************************************************************************
** Meta object code from reading C++ file 'SwitchAccNewWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SwitchAccNewWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SwitchAccNewWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SwitchAccNewWidget_t {
    QByteArrayData data[13];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SwitchAccNewWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SwitchAccNewWidget_t qt_meta_stringdata_SwitchAccNewWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SwitchAccNewWidget"
QT_MOC_LITERAL(1, 19, 12), // "sigSwitchAcc"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "sigJoinEnt"
QT_MOC_LITERAL(4, 44, 11), // "m_strTaxNum"
QT_MOC_LITERAL(5, 56, 13), // "onTextChanged"
QT_MOC_LITERAL(6, 70, 7), // "strText"
QT_MOC_LITERAL(7, 78, 11), // "onSwitchAcc"
QT_MOC_LITERAL(8, 90, 11), // "nLoginByTax"
QT_MOC_LITERAL(9, 102, 6), // "bOther"
QT_MOC_LITERAL(10, 109, 17), // "strTaxNo_userName"
QT_MOC_LITERAL(11, 127, 6), // "strPwd"
QT_MOC_LITERAL(12, 134, 9) // "onJoinEnt"

    },
    "SwitchAccNewWidget\0sigSwitchAcc\0\0"
    "sigJoinEnt\0m_strTaxNum\0onTextChanged\0"
    "strText\0onSwitchAcc\0nLoginByTax\0bOther\0"
    "strTaxNo_userName\0strPwd\0onJoinEnt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SwitchAccNewWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       3,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   51,    2, 0x08 /* Private */,
       7,    4,   54,    2, 0x08 /* Private */,
      12,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void SwitchAccNewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SwitchAccNewWidget *_t = static_cast<SwitchAccNewWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSwitchAcc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->sigJoinEnt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onSwitchAcc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: _t->onJoinEnt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SwitchAccNewWidget::*_t)(int , bool , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SwitchAccNewWidget::sigSwitchAcc)) {
                *result = 0;
            }
        }
        {
            typedef void (SwitchAccNewWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SwitchAccNewWidget::sigJoinEnt)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject SwitchAccNewWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SwitchAccNewWidget.data,
      qt_meta_data_SwitchAccNewWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SwitchAccNewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SwitchAccNewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SwitchAccNewWidget.stringdata0))
        return static_cast<void*>(const_cast< SwitchAccNewWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SwitchAccNewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SwitchAccNewWidget::sigSwitchAcc(int _t1, bool _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SwitchAccNewWidget::sigJoinEnt(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
