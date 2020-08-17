/****************************************************************************
** Meta object code from reading C++ file 'EntAppealDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EntAppealDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EntAppealDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EntAppealDlg_t {
    QByteArrayData data[5];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EntAppealDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EntAppealDlg_t qt_meta_stringdata_EntAppealDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EntAppealDlg"
QT_MOC_LITERAL(1, 13, 17), // "sigUpdateSucessed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 10), // "onOpenFile"
QT_MOC_LITERAL(4, 43, 6) // "upload"

    },
    "EntAppealDlg\0sigUpdateSucessed\0\0"
    "onOpenFile\0upload"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EntAppealDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void EntAppealDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EntAppealDlg *_t = static_cast<EntAppealDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateSucessed(); break;
        case 1: { bool _r = _t->onOpenFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->upload(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EntAppealDlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntAppealDlg::sigUpdateSucessed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject EntAppealDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EntAppealDlg.data,
      qt_meta_data_EntAppealDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EntAppealDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EntAppealDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EntAppealDlg.stringdata0))
        return static_cast<void*>(const_cast< EntAppealDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int EntAppealDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void EntAppealDlg::sigUpdateSucessed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
