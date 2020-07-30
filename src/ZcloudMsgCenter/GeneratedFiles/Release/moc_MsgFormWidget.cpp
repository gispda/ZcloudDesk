/****************************************************************************
** Meta object code from reading C++ file 'MsgFormWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MsgFormWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MsgFormWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MsgFormWidget_t {
    QByteArrayData data[6];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MsgFormWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MsgFormWidget_t qt_meta_stringdata_MsgFormWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MsgFormWidget"
QT_MOC_LITERAL(1, 14, 15), // "sigCommitStatue"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "sigMsgFormClose"
QT_MOC_LITERAL(4, 47, 14), // "onLoadFinished"
QT_MOC_LITERAL(5, 62, 14) // "onCommitStatue"

    },
    "MsgFormWidget\0sigCommitStatue\0\0"
    "sigMsgFormClose\0onLoadFinished\0"
    "onCommitStatue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MsgFormWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   36,    2, 0x08 /* Private */,
       5,    1,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MsgFormWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MsgFormWidget *_t = static_cast<MsgFormWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigCommitStatue(); break;
        case 1: _t->sigMsgFormClose(); break;
        case 2: _t->onLoadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onCommitStatue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MsgFormWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MsgFormWidget::sigCommitStatue)) {
                *result = 0;
            }
        }
        {
            typedef void (MsgFormWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MsgFormWidget::sigMsgFormClose)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MsgFormWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MsgFormWidget.data,
      qt_meta_data_MsgFormWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MsgFormWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MsgFormWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MsgFormWidget.stringdata0))
        return static_cast<void*>(const_cast< MsgFormWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MsgFormWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MsgFormWidget::sigCommitStatue()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MsgFormWidget::sigMsgFormClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
