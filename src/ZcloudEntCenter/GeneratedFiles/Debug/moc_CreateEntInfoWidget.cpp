/****************************************************************************
** Meta object code from reading C++ file 'CreateEntInfoWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CreateEntInfoWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreateEntInfoWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateEntInfoWidget_t {
    QByteArrayData data[12];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateEntInfoWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateEntInfoWidget_t qt_meta_stringdata_CreateEntInfoWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CreateEntInfoWidget"
QT_MOC_LITERAL(1, 20, 17), // "sigUpdateSucessed"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 17), // "onProIndexChanged"
QT_MOC_LITERAL(4, 57, 5), // "index"
QT_MOC_LITERAL(5, 63, 18), // "onCityIndexChanged"
QT_MOC_LITERAL(6, 82, 18), // "onAreaIndexChanged"
QT_MOC_LITERAL(7, 101, 24), // "onAddressEditingFinished"
QT_MOC_LITERAL(8, 126, 28), // "onLegalPeasonEditingFinished"
QT_MOC_LITERAL(9, 155, 22), // "onPhoneEditingFinished"
QT_MOC_LITERAL(10, 178, 16), // "onEditOkBtnClick"
QT_MOC_LITERAL(11, 195, 17) // "onSearchkBtnClick"

    },
    "CreateEntInfoWidget\0sigUpdateSucessed\0"
    "\0onProIndexChanged\0index\0onCityIndexChanged\0"
    "onAreaIndexChanged\0onAddressEditingFinished\0"
    "onLegalPeasonEditingFinished\0"
    "onPhoneEditingFinished\0onEditOkBtnClick\0"
    "onSearchkBtnClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateEntInfoWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   60,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       6,    1,   66,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateEntInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateEntInfoWidget *_t = static_cast<CreateEntInfoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateSucessed(); break;
        case 1: _t->onProIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onCityIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onAreaIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onAddressEditingFinished(); break;
        case 5: _t->onLegalPeasonEditingFinished(); break;
        case 6: _t->onPhoneEditingFinished(); break;
        case 7: _t->onEditOkBtnClick(); break;
        case 8: _t->onSearchkBtnClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateEntInfoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateEntInfoWidget::sigUpdateSucessed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CreateEntInfoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CreateEntInfoWidget.data,
      qt_meta_data_CreateEntInfoWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateEntInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateEntInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateEntInfoWidget.stringdata0))
        return static_cast<void*>(const_cast< CreateEntInfoWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CreateEntInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CreateEntInfoWidget::sigUpdateSucessed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
