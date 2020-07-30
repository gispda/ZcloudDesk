/****************************************************************************
** Meta object code from reading C++ file 'AddMemberWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AddMemberWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddMemberWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddMemberWidget_t {
    QByteArrayData data[8];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddMemberWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddMemberWidget_t qt_meta_stringdata_AddMemberWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AddMemberWidget"
QT_MOC_LITERAL(1, 16, 12), // "sigAddMember"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "onAddOkBtnClick"
QT_MOC_LITERAL(4, 46, 21), // "onNameEditingFinished"
QT_MOC_LITERAL(5, 68, 20), // "onAccEditingFinished"
QT_MOC_LITERAL(6, 89, 20), // "onPwdEditingFinished"
QT_MOC_LITERAL(7, 110, 20) // "onJobEditingFinished"

    },
    "AddMemberWidget\0sigAddMember\0\0"
    "onAddOkBtnClick\0onNameEditingFinished\0"
    "onAccEditingFinished\0onPwdEditingFinished\0"
    "onJobEditingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddMemberWidget[] = {

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

void AddMemberWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddMemberWidget *_t = static_cast<AddMemberWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAddMember(); break;
        case 1: _t->onAddOkBtnClick(); break;
        case 2: _t->onNameEditingFinished(); break;
        case 3: _t->onAccEditingFinished(); break;
        case 4: _t->onPwdEditingFinished(); break;
        case 5: _t->onJobEditingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddMemberWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddMemberWidget::sigAddMember)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AddMemberWidget::staticMetaObject = {
    { &ZcloudCommonWidget::staticMetaObject, qt_meta_stringdata_AddMemberWidget.data,
      qt_meta_data_AddMemberWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddMemberWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddMemberWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddMemberWidget.stringdata0))
        return static_cast<void*>(const_cast< AddMemberWidget*>(this));
    return ZcloudCommonWidget::qt_metacast(_clname);
}

int AddMemberWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AddMemberWidget::sigAddMember()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
