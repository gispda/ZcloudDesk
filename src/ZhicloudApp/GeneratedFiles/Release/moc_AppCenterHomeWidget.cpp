/****************************************************************************
** Meta object code from reading C++ file 'AppCenterHomeWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AppCenter/AppCenterHomeWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppCenterHomeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AppCenterHomeWidget_t {
    QByteArrayData data[6];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppCenterHomeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppCenterHomeWidget_t qt_meta_stringdata_AppCenterHomeWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "AppCenterHomeWidget"
QT_MOC_LITERAL(1, 20, 17), // "clickedButtonSLot"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16), // "set_circleButton"
QT_MOC_LITERAL(4, 56, 12), // "circleNumber"
QT_MOC_LITERAL(5, 69, 21) // "clickedNameButtonSlot"

    },
    "AppCenterHomeWidget\0clickedButtonSLot\0"
    "\0set_circleButton\0circleNumber\0"
    "clickedNameButtonSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppCenterHomeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       3,    1,   32,    2, 0x08 /* Private */,
       5,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void AppCenterHomeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppCenterHomeWidget *_t = static_cast<AppCenterHomeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clickedButtonSLot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->set_circleButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->clickedNameButtonSlot(); break;
        default: ;
        }
    }
}

const QMetaObject AppCenterHomeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AppCenterHomeWidget.data,
      qt_meta_data_AppCenterHomeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AppCenterHomeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppCenterHomeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AppCenterHomeWidget.stringdata0))
        return static_cast<void*>(const_cast< AppCenterHomeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AppCenterHomeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
