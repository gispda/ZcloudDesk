/****************************************************************************
** Meta object code from reading C++ file 'AppParticularsDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AppCenter/AppParticularsDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppParticularsDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AppParticularsDialog_t {
    QByteArrayData data[10];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppParticularsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppParticularsDialog_t qt_meta_stringdata_AppParticularsDialog = {
    {
QT_MOC_LITERAL(0, 0, 20), // "AppParticularsDialog"
QT_MOC_LITERAL(1, 21, 13), // "statusChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 9), // "APPSTATUS"
QT_MOC_LITERAL(4, 46, 4), // "flag"
QT_MOC_LITERAL(5, 51, 15), // "clostClickeSlot"
QT_MOC_LITERAL(6, 67, 23), // "onDownloadStatusChanged"
QT_MOC_LITERAL(7, 91, 16), // "APPDOWNLOADETYPE"
QT_MOC_LITERAL(8, 108, 4), // "type"
QT_MOC_LITERAL(9, 113, 20) // "clickedStautusButton"

    },
    "AppParticularsDialog\0statusChanged\0\0"
    "APPSTATUS\0flag\0clostClickeSlot\0"
    "onDownloadStatusChanged\0APPDOWNLOADETYPE\0"
    "type\0clickedStautusButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppParticularsDialog[] = {

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
       1,    1,   34,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,
       6,    1,   38,    2, 0x0a /* Public */,
       9,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void AppParticularsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppParticularsDialog *_t = static_cast<AppParticularsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< APPSTATUS(*)>(_a[1]))); break;
        case 1: _t->clostClickeSlot(); break;
        case 2: _t->onDownloadStatusChanged((*reinterpret_cast< APPDOWNLOADETYPE(*)>(_a[1]))); break;
        case 3: _t->clickedStautusButton(); break;
        default: ;
        }
    }
}

const QMetaObject AppParticularsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AppParticularsDialog.data,
      qt_meta_data_AppParticularsDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AppParticularsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppParticularsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AppParticularsDialog.stringdata0))
        return static_cast<void*>(const_cast< AppParticularsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AppParticularsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
