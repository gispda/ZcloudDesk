/****************************************************************************
** Meta object code from reading C++ file 'EditEntInfoWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EditEntInfoWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditEntInfoWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EditEntInfoWidget_t {
    QByteArrayData data[17];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditEntInfoWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditEntInfoWidget_t qt_meta_stringdata_EditEntInfoWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "EditEntInfoWidget"
QT_MOC_LITERAL(1, 18, 17), // "sigUpdateSucessed"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "onProIndexChanged"
QT_MOC_LITERAL(4, 55, 5), // "index"
QT_MOC_LITERAL(5, 61, 18), // "onCityIndexChanged"
QT_MOC_LITERAL(6, 80, 18), // "onAreaIndexChanged"
QT_MOC_LITERAL(7, 99, 23), // "onOfficeProIndexChanged"
QT_MOC_LITERAL(8, 123, 24), // "onOfficeCityIndexChanged"
QT_MOC_LITERAL(9, 148, 24), // "onOfficeAreaIndexChanged"
QT_MOC_LITERAL(10, 173, 19), // "onTradeIndexChanged"
QT_MOC_LITERAL(11, 193, 28), // "onLegalPeasonEditingFinished"
QT_MOC_LITERAL(12, 222, 22), // "onPhoneEditingFinished"
QT_MOC_LITERAL(13, 245, 16), // "onEditOkBtnClick"
QT_MOC_LITERAL(14, 262, 14), // "onNextBtnClick"
QT_MOC_LITERAL(15, 277, 25), // "onRadioBtnAddressRegClick"
QT_MOC_LITERAL(16, 303, 25) // "onRadioBtnAddressNewClick"

    },
    "EditEntInfoWidget\0sigUpdateSucessed\0"
    "\0onProIndexChanged\0index\0onCityIndexChanged\0"
    "onAreaIndexChanged\0onOfficeProIndexChanged\0"
    "onOfficeCityIndexChanged\0"
    "onOfficeAreaIndexChanged\0onTradeIndexChanged\0"
    "onLegalPeasonEditingFinished\0"
    "onPhoneEditingFinished\0onEditOkBtnClick\0"
    "onNextBtnClick\0onRadioBtnAddressRegClick\0"
    "onRadioBtnAddressNewClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditEntInfoWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   85,    2, 0x08 /* Private */,
       5,    1,   88,    2, 0x08 /* Private */,
       6,    1,   91,    2, 0x08 /* Private */,
       7,    1,   94,    2, 0x08 /* Private */,
       8,    1,   97,    2, 0x08 /* Private */,
       9,    1,  100,    2, 0x08 /* Private */,
      10,    1,  103,    2, 0x08 /* Private */,
      11,    0,  106,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditEntInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditEntInfoWidget *_t = static_cast<EditEntInfoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateSucessed(); break;
        case 1: _t->onProIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onCityIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onAreaIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onOfficeProIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onOfficeCityIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onOfficeAreaIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onTradeIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->onLegalPeasonEditingFinished(); break;
        case 9: _t->onPhoneEditingFinished(); break;
        case 10: _t->onEditOkBtnClick(); break;
        case 11: _t->onNextBtnClick(); break;
        case 12: _t->onRadioBtnAddressRegClick(); break;
        case 13: _t->onRadioBtnAddressNewClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EditEntInfoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditEntInfoWidget::sigUpdateSucessed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject EditEntInfoWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditEntInfoWidget.data,
      qt_meta_data_EditEntInfoWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EditEntInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditEntInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EditEntInfoWidget.stringdata0))
        return static_cast<void*>(const_cast< EditEntInfoWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditEntInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void EditEntInfoWidget::sigUpdateSucessed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
