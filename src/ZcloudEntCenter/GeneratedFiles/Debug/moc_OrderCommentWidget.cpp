/****************************************************************************
** Meta object code from reading C++ file 'OrderCommentWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OrderCommentWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OrderCommentWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OrderCommentWidget_t {
    QByteArrayData data[9];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrderCommentWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrderCommentWidget_t qt_meta_stringdata_OrderCommentWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "OrderCommentWidget"
QT_MOC_LITERAL(1, 19, 9), // "sigDetial"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "sigEvaluate"
QT_MOC_LITERAL(4, 42, 5), // "push1"
QT_MOC_LITERAL(5, 48, 5), // "push2"
QT_MOC_LITERAL(6, 54, 5), // "push3"
QT_MOC_LITERAL(7, 60, 5), // "push4"
QT_MOC_LITERAL(8, 66, 5) // "push5"

    },
    "OrderCommentWidget\0sigDetial\0\0sigEvaluate\0"
    "push1\0push2\0push3\0push4\0push5"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderCommentWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    3,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   59,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OrderCommentWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OrderCommentWidget *_t = static_cast<OrderCommentWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDetial((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigEvaluate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->push1(); break;
        case 3: _t->push2(); break;
        case 4: _t->push3(); break;
        case 5: _t->push4(); break;
        case 6: _t->push5(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OrderCommentWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OrderCommentWidget::sigDetial)) {
                *result = 0;
            }
        }
        {
            typedef void (OrderCommentWidget::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OrderCommentWidget::sigEvaluate)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject OrderCommentWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OrderCommentWidget.data,
      qt_meta_data_OrderCommentWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OrderCommentWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderCommentWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OrderCommentWidget.stringdata0))
        return static_cast<void*>(const_cast< OrderCommentWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int OrderCommentWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void OrderCommentWidget::sigDetial(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OrderCommentWidget::sigEvaluate(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
