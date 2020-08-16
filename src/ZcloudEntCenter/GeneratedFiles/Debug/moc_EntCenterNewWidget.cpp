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
    QByteArrayData data[21];
    char stringdata0[274];
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
QT_MOC_LITERAL(4, 44, 15), // "JoinEntMoreStep"
QT_MOC_LITERAL(5, 60, 11), // "DoAppealEnt"
QT_MOC_LITERAL(6, 72, 25), // "JoinStep2AppealGetEntInfo"
QT_MOC_LITERAL(7, 98, 22), // "JoinStep2FinishEntinfo"
QT_MOC_LITERAL(8, 121, 14), // "DoapplyJoinEnt"
QT_MOC_LITERAL(9, 136, 4), // "int&"
QT_MOC_LITERAL(10, 141, 6), // "stcode"
QT_MOC_LITERAL(11, 148, 13), // "decideJoinEnt"
QT_MOC_LITERAL(12, 162, 12), // "onShowMember"
QT_MOC_LITERAL(13, 175, 10), // "onShowMain"
QT_MOC_LITERAL(14, 186, 14), // "onCopyBtnClick"
QT_MOC_LITERAL(15, 201, 16), // "onSwitchBtnClick"
QT_MOC_LITERAL(16, 218, 11), // "onSwitchAcc"
QT_MOC_LITERAL(17, 230, 11), // "bLoginByTax"
QT_MOC_LITERAL(18, 242, 6), // "bOther"
QT_MOC_LITERAL(19, 249, 17), // "strTaxNo_userName"
QT_MOC_LITERAL(20, 267, 6) // "strPwd"

    },
    "EntCenterNewWidget\0sigSwitchAcc\0\0"
    "onShowInfo\0JoinEntMoreStep\0DoAppealEnt\0"
    "JoinStep2AppealGetEntInfo\0"
    "JoinStep2FinishEntinfo\0DoapplyJoinEnt\0"
    "int&\0stcode\0decideJoinEnt\0onShowMember\0"
    "onShowMain\0onCopyBtnClick\0onSwitchBtnClick\0"
    "onSwitchAcc\0bLoginByTax\0bOther\0"
    "strTaxNo_userName\0strPwd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EntCenterNewWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   88,    2, 0x08 /* Private */,
       4,    0,   89,    2, 0x08 /* Private */,
       5,    0,   90,    2, 0x08 /* Private */,
       6,    0,   91,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    1,   93,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    4,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool, 0x80000000 | 9,   10,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,   17,   18,   19,   20,

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
        case 2: _t->JoinEntMoreStep(); break;
        case 3: _t->DoAppealEnt(); break;
        case 4: { bool _r = _t->JoinStep2AppealGetEntInfo();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->JoinStep2FinishEntinfo();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->DoapplyJoinEnt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->decideJoinEnt();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->onShowMember(); break;
        case 9: _t->onShowMain(); break;
        case 10: _t->onCopyBtnClick(); break;
        case 11: _t->onSwitchBtnClick(); break;
        case 12: _t->onSwitchAcc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
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
