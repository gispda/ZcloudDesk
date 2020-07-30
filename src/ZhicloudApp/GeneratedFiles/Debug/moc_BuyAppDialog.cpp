/****************************************************************************
** Meta object code from reading C++ file 'BuyAppDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BuyAppDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BuyAppDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BuyAppDialog_t {
    QByteArrayData data[18];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BuyAppDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BuyAppDialog_t qt_meta_stringdata_BuyAppDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BuyAppDialog"
QT_MOC_LITERAL(1, 13, 19), // "buyStatusChangeSlot"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "appId"
QT_MOC_LITERAL(4, 40, 13), // "expireDateInt"
QT_MOC_LITERAL(5, 54, 6), // "status"
QT_MOC_LITERAL(6, 61, 6), // "strMd5"
QT_MOC_LITERAL(7, 68, 10), // "getVipList"
QT_MOC_LITERAL(8, 79, 7), // "strJson"
QT_MOC_LITERAL(9, 87, 12), // "closeBuySlot"
QT_MOC_LITERAL(10, 100, 6), // "notBuy"
QT_MOC_LITERAL(11, 107, 12), // "loadFinished"
QT_MOC_LITERAL(12, 120, 21), // "slotChangeWindowsSize"
QT_MOC_LITERAL(13, 142, 9), // "isMaxSize"
QT_MOC_LITERAL(14, 152, 18), // "slotOpenDefaultWeb"
QT_MOC_LITERAL(15, 171, 6), // "strUrl"
QT_MOC_LITERAL(16, 178, 16), // "slotBindingPhone"
QT_MOC_LITERAL(17, 195, 17) // "getNewUserIdToken"

    },
    "BuyAppDialog\0buyStatusChangeSlot\0\0"
    "appId\0expireDateInt\0status\0strMd5\0"
    "getVipList\0strJson\0closeBuySlot\0notBuy\0"
    "loadFinished\0slotChangeWindowsSize\0"
    "isMaxSize\0slotOpenDefaultWeb\0strUrl\0"
    "slotBindingPhone\0getNewUserIdToken"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BuyAppDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   59,    2, 0x0a /* Public */,
       7,    1,   68,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,
      12,    1,   74,    2, 0x0a /* Public */,
      14,    1,   77,    2, 0x0a /* Public */,
      16,    0,   80,    2, 0x0a /* Public */,
      17,    2,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

       0        // eod
};

void BuyAppDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BuyAppDialog *_t = static_cast<BuyAppDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buyStatusChangeSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->getVipList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->closeBuySlot(); break;
        case 3: _t->notBuy(); break;
        case 4: _t->loadFinished(); break;
        case 5: _t->slotChangeWindowsSize((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 6: _t->slotOpenDefaultWeb((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->slotBindingPhone(); break;
        case 8: _t->getNewUserIdToken((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject BuyAppDialog::staticMetaObject = {
    { &AppCommDialog::staticMetaObject, qt_meta_stringdata_BuyAppDialog.data,
      qt_meta_data_BuyAppDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BuyAppDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BuyAppDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BuyAppDialog.stringdata0))
        return static_cast<void*>(const_cast< BuyAppDialog*>(this));
    return AppCommDialog::qt_metacast(_clname);
}

int BuyAppDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AppCommDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
