/****************************************************************************
** Meta object code from reading C++ file 'AppCenterUUWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AppCenter/AppCenterUUWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppCenterUUWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AppCenterUUWidget_t {
    QByteArrayData data[5];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppCenterUUWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppCenterUUWidget_t qt_meta_stringdata_AppCenterUUWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AppCenterUUWidget"
QT_MOC_LITERAL(1, 18, 18), // "onNextPageBtnClick"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "value"
QT_MOC_LITERAL(4, 44, 12) // "UUButtonSlot"

    },
    "AppCenterUUWidget\0onNextPageBtnClick\0"
    "\0value\0UUButtonSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppCenterUUWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void AppCenterUUWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppCenterUUWidget *_t = static_cast<AppCenterUUWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNextPageBtnClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->UUButtonSlot(); break;
        default: ;
        }
    }
}

const QMetaObject AppCenterUUWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AppCenterUUWidget.data,
      qt_meta_data_AppCenterUUWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AppCenterUUWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppCenterUUWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AppCenterUUWidget.stringdata0))
        return static_cast<void*>(const_cast< AppCenterUUWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AppCenterUUWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
