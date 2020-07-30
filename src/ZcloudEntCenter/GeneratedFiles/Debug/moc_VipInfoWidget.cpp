/****************************************************************************
** Meta object code from reading C++ file 'VipInfoWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VipInfoWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VipInfoWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VipInfoWidget_t {
    QByteArrayData data[12];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VipInfoWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VipInfoWidget_t qt_meta_stringdata_VipInfoWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "VipInfoWidget"
QT_MOC_LITERAL(1, 14, 18), // "sendVipListSignals"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "vipNameList"
QT_MOC_LITERAL(4, 46, 9), // "vipIdList"
QT_MOC_LITERAL(5, 56, 11), // "vipTimeList"
QT_MOC_LITERAL(6, 68, 19), // "bingdingPhoneSignal"
QT_MOC_LITERAL(7, 88, 14), // "onLoadFinished"
QT_MOC_LITERAL(8, 103, 22), // "vipWidgetBingdingPhone"
QT_MOC_LITERAL(9, 126, 12), // "onGetVipList"
QT_MOC_LITERAL(10, 139, 7), // "strJson"
QT_MOC_LITERAL(11, 147, 17) // "getNewUserIdToken"

    },
    "VipInfoWidget\0sendVipListSignals\0\0"
    "vipNameList\0vipIdList\0vipTimeList\0"
    "bingdingPhoneSignal\0onLoadFinished\0"
    "vipWidgetBingdingPhone\0onGetVipList\0"
    "strJson\0getNewUserIdToken"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VipInfoWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       6,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   52,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    1,   56,    2, 0x08 /* Private */,
      11,    2,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,    3,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

       0        // eod
};

void VipInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VipInfoWidget *_t = static_cast<VipInfoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendVipListSignals((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 1: _t->bingdingPhoneSignal(); break;
        case 2: _t->onLoadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->vipWidgetBingdingPhone(); break;
        case 4: _t->onGetVipList((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->getNewUserIdToken((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VipInfoWidget::*_t)(QStringList , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VipInfoWidget::sendVipListSignals)) {
                *result = 0;
            }
        }
        {
            typedef void (VipInfoWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VipInfoWidget::bingdingPhoneSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject VipInfoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VipInfoWidget.data,
      qt_meta_data_VipInfoWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VipInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VipInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VipInfoWidget.stringdata0))
        return static_cast<void*>(const_cast< VipInfoWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int VipInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void VipInfoWidget::sendVipListSignals(QStringList _t1, QStringList _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VipInfoWidget::bingdingPhoneSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
