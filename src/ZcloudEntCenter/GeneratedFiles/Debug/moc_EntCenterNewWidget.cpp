/****************************************************************************
** Meta object code from reading C++ file 'EntCenterNewWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EntCenterNewWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EntCenterNewWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EntCenterNewWidget_t {
    QByteArrayData data[16];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EntCenterNewWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EntCenterNewWidget_t qt_meta_stringdata_EntCenterNewWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "EntCenterNewWidget"
QT_MOC_LITERAL(1, 19, 12), // "sigSwitchAcc"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "onShowInfo"
QT_MOC_LITERAL(4, 44, 9), // "JoinStep1"
QT_MOC_LITERAL(5, 54, 22), // "JoinStep2FinishEntinfo"
QT_MOC_LITERAL(6, 77, 14), // "DoapplyJoinEnt"
QT_MOC_LITERAL(7, 92, 12), // "onShowMember"
QT_MOC_LITERAL(8, 105, 10), // "onShowMain"
QT_MOC_LITERAL(9, 116, 14), // "onCopyBtnClick"
QT_MOC_LITERAL(10, 131, 16), // "onSwitchBtnClick"
QT_MOC_LITERAL(11, 148, 11), // "onSwitchAcc"
QT_MOC_LITERAL(12, 160, 11), // "bLoginByTax"
QT_MOC_LITERAL(13, 172, 6), // "bOther"
QT_MOC_LITERAL(14, 179, 17), // "strTaxNo_userName"
QT_MOC_LITERAL(15, 197, 6) // "strPwd"

    },
    "EntCenterNewWidget\0sigSwitchAcc\0\0"
    "onShowInfo\0JoinStep1\0JoinStep2FinishEntinfo\0"
    "DoapplyJoinEnt\0onShowMember\0onShowMain\0"
    "onCopyBtnClick\0onSwitchBtnClick\0"
    "onSwitchAcc\0bLoginByTax\0bOther\0"
    "strTaxNo_userName\0strPwd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EntCenterNewWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   73,    2, 0x08 /* Private */,
       4,    0,   74,    2, 0x08 /* Private */,
       5,    0,   75,    2, 0x08 /* Private */,
       6,    0,   76,    2, 0x08 /* Private */,
       7,    0,   77,    2, 0x08 /* Private */,
       8,    0,   78,    2, 0x08 /* Private */,
       9,    0,   79,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    4,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,   12,   13,   14,   15,

       0        // eod
};

void EntCenterNewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EntCenterNewWidget *_t = static_cast<EntCenterNewWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSwitchAcc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->onShowInfo(); break;
        case 2: _t->JoinStep1(); break;
        case 3: { bool _r = _t->JoinStep2FinishEntinfo();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->DoapplyJoinEnt();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->onShowMember(); break;
        case 6: _t->onShowMain(); break;
        case 7: _t->onCopyBtnClick(); break;
        case 8: _t->onSwitchBtnClick(); break;
        case 9: _t->onSwitchAcc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EntCenterNewWidget::*_t)(int , bool , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntCenterNewWidget::sigSwitchAcc)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject EntCenterNewWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EntCenterNewWidget.data,
      qt_meta_data_EntCenterNewWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EntCenterNewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EntCenterNewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EntCenterNewWidget.stringdata0))
        return static_cast<void*>(const_cast< EntCenterNewWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int EntCenterNewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void EntCenterNewWidget::sigSwitchAcc(int _t1, bool _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
