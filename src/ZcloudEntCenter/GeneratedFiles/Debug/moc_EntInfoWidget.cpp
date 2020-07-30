/****************************************************************************
** Meta object code from reading C++ file 'EntInfoWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EntInfoWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EntInfoWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EntInfoWidget_t {
    QByteArrayData data[6];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EntInfoWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EntInfoWidget_t qt_meta_stringdata_EntInfoWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "EntInfoWidget"
QT_MOC_LITERAL(1, 14, 17), // "onEntEditBtnClick"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 21), // "onInvoiceEditBtnClick"
QT_MOC_LITERAL(4, 55, 23), // "onUpdateinvoiceSucessed"
QT_MOC_LITERAL(5, 79, 19) // "onUpdateEntSucessed"

    },
    "EntInfoWidget\0onEntEditBtnClick\0\0"
    "onInvoiceEditBtnClick\0onUpdateinvoiceSucessed\0"
    "onUpdateEntSucessed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EntInfoWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EntInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EntInfoWidget *_t = static_cast<EntInfoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onEntEditBtnClick(); break;
        case 1: _t->onInvoiceEditBtnClick(); break;
        case 2: _t->onUpdateinvoiceSucessed(); break;
        case 3: _t->onUpdateEntSucessed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EntInfoWidget::staticMetaObject = {
    { &ZcloudCommonWidget::staticMetaObject, qt_meta_stringdata_EntInfoWidget.data,
      qt_meta_data_EntInfoWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EntInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EntInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EntInfoWidget.stringdata0))
        return static_cast<void*>(const_cast< EntInfoWidget*>(this));
    return ZcloudCommonWidget::qt_metacast(_clname);
}

int EntInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ZcloudCommonWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
