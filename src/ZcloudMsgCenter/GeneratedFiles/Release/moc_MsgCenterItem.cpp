/****************************************************************************
** Meta object code from reading C++ file 'MsgCenterItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MsgCenterItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MsgCenterItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MsgCenterItem_t {
    QByteArrayData data[10];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MsgCenterItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MsgCenterItem_t qt_meta_stringdata_MsgCenterItem = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MsgCenterItem"
QT_MOC_LITERAL(1, 14, 12), // "sigClickItem"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "stMsgInfo*"
QT_MOC_LITERAL(4, 39, 8), // "pMsgInfo"
QT_MOC_LITERAL(5, 48, 5), // "bRead"
QT_MOC_LITERAL(6, 54, 13), // "sigDeleteItem"
QT_MOC_LITERAL(7, 68, 5), // "strId"
QT_MOC_LITERAL(8, 74, 18), // "sigReduceUnreadNum"
QT_MOC_LITERAL(9, 93, 16) // "onDeleteBtnClick"

    },
    "MsgCenterItem\0sigClickItem\0\0stMsgInfo*\0"
    "pMsgInfo\0bRead\0sigDeleteItem\0strId\0"
    "sigReduceUnreadNum\0onDeleteBtnClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MsgCenterItem[] = {

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
       1,    2,   34,    2, 0x06 /* Public */,
       6,    1,   39,    2, 0x06 /* Public */,
       8,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MsgCenterItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MsgCenterItem *_t = static_cast<MsgCenterItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigClickItem((*reinterpret_cast< stMsgInfo*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->sigDeleteItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sigReduceUnreadNum(); break;
        case 3: _t->onDeleteBtnClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MsgCenterItem::*_t)(stMsgInfo * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MsgCenterItem::sigClickItem)) {
                *result = 0;
            }
        }
        {
            typedef void (MsgCenterItem::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MsgCenterItem::sigDeleteItem)) {
                *result = 1;
            }
        }
        {
            typedef void (MsgCenterItem::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MsgCenterItem::sigReduceUnreadNum)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MsgCenterItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MsgCenterItem.data,
      qt_meta_data_MsgCenterItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MsgCenterItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MsgCenterItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MsgCenterItem.stringdata0))
        return static_cast<void*>(const_cast< MsgCenterItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int MsgCenterItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MsgCenterItem::sigClickItem(stMsgInfo * _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MsgCenterItem::sigDeleteItem(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MsgCenterItem::sigReduceUnreadNum()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
