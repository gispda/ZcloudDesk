/****************************************************************************
** Meta object code from reading C++ file 'ModifyUserInfoWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ModifyUserInfoWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModifyUserInfoWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModifyUserInfoWidget_t {
    QByteArrayData data[6];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModifyUserInfoWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModifyUserInfoWidget_t qt_meta_stringdata_ModifyUserInfoWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ModifyUserInfoWidget"
QT_MOC_LITERAL(1, 21, 17), // "sigModifySucessed"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 18), // "onModifyOkBtnClick"
QT_MOC_LITERAL(4, 59, 21), // "onNameEditingFinished"
QT_MOC_LITERAL(5, 81, 20) // "onJobEditingFinished"

    },
    "ModifyUserInfoWidget\0sigModifySucessed\0"
    "\0onModifyOkBtnClick\0onNameEditingFinished\0"
    "onJobEditingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModifyUserInfoWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   39,    2, 0x08 /* Private */,
       4,    0,   40,    2, 0x08 /* Private */,
       5,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ModifyUserInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModifyUserInfoWidget *_t = static_cast<ModifyUserInfoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigModifySucessed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->onModifyOkBtnClick(); break;
        case 2: _t->onNameEditingFinished(); break;
        case 3: _t->onJobEditingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModifyUserInfoWidget::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModifyUserInfoWidget::sigModifySucessed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ModifyUserInfoWidget::staticMetaObject = {
    { &ZcloudCommonWidget::staticMetaObject, qt_meta_stringdata_ModifyUserInfoWidget.data,
      qt_meta_data_ModifyUserInfoWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ModifyUserInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModifyUserInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ModifyUserInfoWidget.stringdata0))
        return static_cast<void*>(const_cast< ModifyUserInfoWidget*>(this));
    return ZcloudCommonWidget::qt_metacast(_clname);
}

int ModifyUserInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ModifyUserInfoWidget::sigModifySucessed(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
