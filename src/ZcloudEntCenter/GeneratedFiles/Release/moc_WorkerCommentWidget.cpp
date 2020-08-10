/****************************************************************************
** Meta object code from reading C++ file 'WorkerCommentWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WorkerCommentWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WorkerCommentWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WorkerCommentWidget_t {
    QByteArrayData data[15];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkerCommentWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkerCommentWidget_t qt_meta_stringdata_WorkerCommentWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "WorkerCommentWidget"
QT_MOC_LITERAL(1, 20, 9), // "sigDetial"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "sigEvaluate"
QT_MOC_LITERAL(4, 43, 15), // "onworkerComment"
QT_MOC_LITERAL(5, 59, 10), // "WorkerInfo"
QT_MOC_LITERAL(6, 70, 6), // "_sinfo"
QT_MOC_LITERAL(7, 77, 5), // "push1"
QT_MOC_LITERAL(8, 83, 12), // "setStarlabel"
QT_MOC_LITERAL(9, 96, 10), // "star_level"
QT_MOC_LITERAL(10, 107, 5), // "push2"
QT_MOC_LITERAL(11, 113, 5), // "push3"
QT_MOC_LITERAL(12, 119, 5), // "push4"
QT_MOC_LITERAL(13, 125, 5), // "push5"
QT_MOC_LITERAL(14, 131, 13) // "submitComment"

    },
    "WorkerCommentWidget\0sigDetial\0\0"
    "sigEvaluate\0onworkerComment\0WorkerInfo\0"
    "_sinfo\0push1\0setStarlabel\0star_level\0"
    "push2\0push3\0push4\0push5\0submitComment"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkerCommentWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    3,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   74,    2, 0x0a /* Public */,
       7,    0,   77,    2, 0x08 /* Private */,
       8,    1,   78,    2, 0x08 /* Private */,
      10,    0,   81,    2, 0x08 /* Private */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WorkerCommentWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkerCommentWidget *_t = static_cast<WorkerCommentWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDetial((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigEvaluate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: { bool _r = _t->onworkerComment((*reinterpret_cast< WorkerInfo(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->push1(); break;
        case 4: _t->setStarlabel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->push2(); break;
        case 6: _t->push3(); break;
        case 7: _t->push4(); break;
        case 8: _t->push5(); break;
        case 9: _t->submitComment(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WorkerCommentWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerCommentWidget::sigDetial)) {
                *result = 0;
            }
        }
        {
            typedef void (WorkerCommentWidget::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkerCommentWidget::sigEvaluate)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject WorkerCommentWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WorkerCommentWidget.data,
      qt_meta_data_WorkerCommentWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WorkerCommentWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkerCommentWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WorkerCommentWidget.stringdata0))
        return static_cast<void*>(const_cast< WorkerCommentWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int WorkerCommentWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void WorkerCommentWidget::sigDetial(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WorkerCommentWidget::sigEvaluate(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
