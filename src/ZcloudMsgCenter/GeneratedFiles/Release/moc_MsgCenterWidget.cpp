/****************************************************************************
** Meta object code from reading C++ file 'MsgCenterWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MsgCenterWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MsgCenterWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NoFocusFrameDelegate_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NoFocusFrameDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NoFocusFrameDelegate_t qt_meta_stringdata_NoFocusFrameDelegate = {
    {
QT_MOC_LITERAL(0, 0, 20) // "NoFocusFrameDelegate"

    },
    "NoFocusFrameDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NoFocusFrameDelegate[] = {

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

void NoFocusFrameDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject NoFocusFrameDelegate::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_NoFocusFrameDelegate.data,
      qt_meta_data_NoFocusFrameDelegate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NoFocusFrameDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoFocusFrameDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NoFocusFrameDelegate.stringdata0))
        return static_cast<void*>(const_cast< NoFocusFrameDelegate*>(this));
    return QStyledItemDelegate::qt_metacast(_clname);
}

int NoFocusFrameDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MsgCenterWidget_t {
    QByteArrayData data[23];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MsgCenterWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MsgCenterWidget_t qt_meta_stringdata_MsgCenterWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MsgCenterWidget"
QT_MOC_LITERAL(1, 16, 18), // "sigReduceUnreadNum"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "nNum"
QT_MOC_LITERAL(4, 41, 21), // "sigSendMessageRespone"
QT_MOC_LITERAL(5, 63, 8), // "onMaxBtn"
QT_MOC_LITERAL(6, 72, 11), // "onClickItem"
QT_MOC_LITERAL(7, 84, 10), // "stMsgInfo*"
QT_MOC_LITERAL(8, 95, 8), // "pMsgInfo"
QT_MOC_LITERAL(9, 104, 5), // "bRead"
QT_MOC_LITERAL(10, 110, 13), // "onLinkClicked"
QT_MOC_LITERAL(11, 124, 3), // "url"
QT_MOC_LITERAL(12, 128, 17), // "onCbxIndexChanged"
QT_MOC_LITERAL(13, 146, 5), // "index"
QT_MOC_LITERAL(14, 152, 15), // "onSliderChanged"
QT_MOC_LITERAL(15, 168, 5), // "value"
QT_MOC_LITERAL(16, 174, 12), // "onDeleteItem"
QT_MOC_LITERAL(17, 187, 5), // "strId"
QT_MOC_LITERAL(18, 193, 13), // "onMsgBtnClick"
QT_MOC_LITERAL(19, 207, 17), // "onReduceUnreadNum"
QT_MOC_LITERAL(20, 225, 14), // "onCommitStatue"
QT_MOC_LITERAL(21, 240, 14), // "onMsgFormClose"
QT_MOC_LITERAL(22, 255, 17) // "onScrollRequested"

    },
    "MsgCenterWidget\0sigReduceUnreadNum\0\0"
    "nNum\0sigSendMessageRespone\0onMaxBtn\0"
    "onClickItem\0stMsgInfo*\0pMsgInfo\0bRead\0"
    "onLinkClicked\0url\0onCbxIndexChanged\0"
    "index\0onSliderChanged\0value\0onDeleteItem\0"
    "strId\0onMsgBtnClick\0onReduceUnreadNum\0"
    "onCommitStatue\0onMsgFormClose\0"
    "onScrollRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MsgCenterWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   85,    2, 0x08 /* Private */,
       6,    2,   86,    2, 0x08 /* Private */,
      10,    1,   91,    2, 0x08 /* Private */,
      12,    1,   94,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      16,    1,  100,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,
      19,    0,  104,    2, 0x08 /* Private */,
      20,    0,  105,    2, 0x08 /* Private */,
      21,    0,  106,    2, 0x08 /* Private */,
      22,    3,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Bool,    8,    9,
    QMetaType::Void, QMetaType::QUrl,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QRect,    2,    2,    2,

       0        // eod
};

void MsgCenterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MsgCenterWidget *_t = static_cast<MsgCenterWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReduceUnreadNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sigSendMessageRespone((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onMaxBtn(); break;
        case 3: _t->onClickItem((*reinterpret_cast< stMsgInfo*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->onLinkClicked((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 5: _t->onCbxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onSliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onDeleteItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->onMsgBtnClick(); break;
        case 9: _t->onReduceUnreadNum(); break;
        case 10: _t->onCommitStatue(); break;
        case 11: _t->onMsgFormClose(); break;
        case 12: _t->onScrollRequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QRect(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MsgCenterWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MsgCenterWidget::sigReduceUnreadNum)) {
                *result = 0;
            }
        }
        {
            typedef void (MsgCenterWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MsgCenterWidget::sigSendMessageRespone)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MsgCenterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MsgCenterWidget.data,
      qt_meta_data_MsgCenterWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MsgCenterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MsgCenterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MsgCenterWidget.stringdata0))
        return static_cast<void*>(const_cast< MsgCenterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MsgCenterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MsgCenterWidget::sigReduceUnreadNum(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MsgCenterWidget::sigSendMessageRespone(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
