/****************************************************************************
** Meta object code from reading C++ file 'EditInvoiceInfoWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EditInvoiceInfoWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditInvoiceInfoWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EditInvoiceInfoWidget_t {
    QByteArrayData data[8];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditInvoiceInfoWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditInvoiceInfoWidget_t qt_meta_stringdata_EditInvoiceInfoWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "EditInvoiceInfoWidget"
QT_MOC_LITERAL(1, 22, 17), // "sigUpdateSucessed"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 17), // "onAccEditBtnClick"
QT_MOC_LITERAL(4, 59, 18), // "onBankEditBtnClick"
QT_MOC_LITERAL(5, 78, 19), // "onTelNoEditBtnClick"
QT_MOC_LITERAL(6, 98, 18), // "onAddrEditBtnClick"
QT_MOC_LITERAL(7, 117, 16) // "onEditOkBtnClick"

    },
    "EditInvoiceInfoWidget\0sigUpdateSucessed\0"
    "\0onAccEditBtnClick\0onBankEditBtnClick\0"
    "onTelNoEditBtnClick\0onAddrEditBtnClick\0"
    "onEditOkBtnClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditInvoiceInfoWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditInvoiceInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditInvoiceInfoWidget *_t = static_cast<EditInvoiceInfoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateSucessed(); break;
        case 1: _t->onAccEditBtnClick(); break;
        case 2: _t->onBankEditBtnClick(); break;
        case 3: _t->onTelNoEditBtnClick(); break;
        case 4: _t->onAddrEditBtnClick(); break;
        case 5: _t->onEditOkBtnClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EditInvoiceInfoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditInvoiceInfoWidget::sigUpdateSucessed)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EditInvoiceInfoWidget::staticMetaObject = {
    { &ZcloudCommonWidget::staticMetaObject, qt_meta_stringdata_EditInvoiceInfoWidget.data,
      qt_meta_data_EditInvoiceInfoWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EditInvoiceInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditInvoiceInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EditInvoiceInfoWidget.stringdata0))
        return static_cast<void*>(const_cast< EditInvoiceInfoWidget*>(this));
    return ZcloudCommonWidget::qt_metacast(_clname);
}

int EditInvoiceInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ZcloudCommonWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void EditInvoiceInfoWidget::sigUpdateSucessed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
