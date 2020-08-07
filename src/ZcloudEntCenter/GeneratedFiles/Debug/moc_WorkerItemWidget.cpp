/****************************************************************************
** Meta object code from reading C++ file 'WorkerItemWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WorkerItemWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WorkerItemWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WorkerItemWidget_t {
    QByteArrayData data[8];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkerItemWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkerItemWidget_t qt_meta_stringdata_WorkerItemWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "WorkerItemWidget"
QT_MOC_LITERAL(1, 17, 9), // "sigDetial"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "strworkerid"
QT_MOC_LITERAL(4, 40, 11), // "sigEvaluate"
QT_MOC_LITERAL(5, 52, 10), // "WorkerInfo"
QT_MOC_LITERAL(6, 63, 6), // "_sinfo"
QT_MOC_LITERAL(7, 70, 4) // "test"

    },
    "WorkerItemWidget\0sigDetial\0\0strworkerid\0"
    "sigEvaluate\0WorkerInfo\0_sinfo\0test"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkerItemWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void WorkerItemWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkerItemWidget *_t = static_cast<WorkerItemWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDetial((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigEvaluate((*reinterpret_cast< WorkerInfo(*)>(_a[1]))); break;
        case 2: _t->test((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WorkerItemWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerItemWidget::sigDetial)) {
                *result = 0;
            }
        }
        {
            typedef void (WorkerItemWidget::*_t)(WorkerInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerItemWidget::sigEvaluate)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject WorkerItemWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WorkerItemWidget.data,
      qt_meta_data_WorkerItemWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WorkerItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkerItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WorkerItemWidget.stringdata0))
        return static_cast<void*>(const_cast< WorkerItemWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int WorkerItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WorkerItemWidget::sigDetial(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WorkerItemWidget::sigEvaluate(WorkerInfo _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
