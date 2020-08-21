/****************************************************************************
** Meta object code from reading C++ file 'ZcloudEntCenter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/ZcloudEntCenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZcloudEntCenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZcloudEntCenter_t {
    QByteArrayData data[13];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZcloudEntCenter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZcloudEntCenter_t qt_meta_stringdata_ZcloudEntCenter = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ZcloudEntCenter"
QT_MOC_LITERAL(1, 16, 16), // "sigNeedLoginMain"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "sigSwitchAcc"
QT_MOC_LITERAL(4, 47, 18), // "sendVipListSignals"
QT_MOC_LITERAL(5, 66, 17), // "trueNameJobChange"
QT_MOC_LITERAL(6, 84, 8), // "trueName"
QT_MOC_LITERAL(7, 93, 6), // "strJob"
QT_MOC_LITERAL(8, 100, 19), // "bingdingPhoneSignal"
QT_MOC_LITERAL(9, 120, 23), // "sigSignBindingSucceeded"
QT_MOC_LITERAL(10, 144, 9), // "strMobile"
QT_MOC_LITERAL(11, 154, 16), // "openSignInWidget"
QT_MOC_LITERAL(12, 171, 8) // "QWidget*"

    },
    "ZcloudEntCenter\0sigNeedLoginMain\0\0"
    "sigSwitchAcc\0sendVipListSignals\0"
    "trueNameJobChange\0trueName\0strJob\0"
    "bingdingPhoneSignal\0sigSignBindingSucceeded\0"
    "strMobile\0openSignInWidget\0QWidget*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZcloudEntCenter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    4,   50,    2, 0x06 /* Public */,
       4,    3,   59,    2, 0x06 /* Public */,
       5,    2,   66,    2, 0x06 /* Public */,
       8,    0,   71,    2, 0x06 /* Public */,
       9,    1,   72,    2, 0x06 /* Public */,
      11,    1,   75,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 12,    2,

       0        // eod
};

void ZcloudEntCenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZcloudEntCenter *_t = static_cast<ZcloudEntCenter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigNeedLoginMain(); break;
        case 1: _t->sigSwitchAcc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->sendVipListSignals((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 3: _t->trueNameJobChange((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->bingdingPhoneSignal(); break;
        case 5: _t->sigSignBindingSucceeded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->openSignInWidget((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ZcloudEntCenter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudEntCenter::sigNeedLoginMain)) {
                *result = 0;
            }
        }
        {
            typedef void (ZcloudEntCenter::*_t)(int , bool , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudEntCenter::sigSwitchAcc)) {
                *result = 1;
            }
        }
        {
            typedef void (ZcloudEntCenter::*_t)(QStringList , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudEntCenter::sendVipListSignals)) {
                *result = 2;
            }
        }
        {
            typedef void (ZcloudEntCenter::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudEntCenter::trueNameJobChange)) {
                *result = 3;
            }
        }
        {
            typedef void (ZcloudEntCenter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudEntCenter::bingdingPhoneSignal)) {
                *result = 4;
            }
        }
        {
            typedef void (ZcloudEntCenter::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudEntCenter::sigSignBindingSucceeded)) {
                *result = 5;
            }
        }
        {
            typedef void (ZcloudEntCenter::*_t)(QWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZcloudEntCenter::openSignInWidget)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject ZcloudEntCenter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ZcloudEntCenter.data,
      qt_meta_data_ZcloudEntCenter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZcloudEntCenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZcloudEntCenter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZcloudEntCenter.stringdata0))
        return static_cast<void*>(const_cast< ZcloudEntCenter*>(this));
    return QObject::qt_metacast(_clname);
}

int ZcloudEntCenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ZcloudEntCenter::sigNeedLoginMain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ZcloudEntCenter::sigSwitchAcc(int _t1, bool _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ZcloudEntCenter::sendVipListSignals(QStringList _t1, QStringList _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ZcloudEntCenter::trueNameJobChange(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ZcloudEntCenter::bingdingPhoneSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void ZcloudEntCenter::sigSignBindingSucceeded(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ZcloudEntCenter::openSignInWidget(QWidget * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
