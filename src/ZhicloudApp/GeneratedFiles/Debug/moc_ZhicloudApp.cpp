/****************************************************************************
** Meta object code from reading C++ file 'ZhicloudApp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/ZhicloudApp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZhicloudApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZhicloudApp_t {
    QByteArrayData data[7];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZhicloudApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZhicloudApp_t qt_meta_stringdata_ZhicloudApp = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ZhicloudApp"
QT_MOC_LITERAL(1, 12, 16), // "changeTaxSignals"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "strTaxNo"
QT_MOC_LITERAL(4, 39, 10), // "strMachine"
QT_MOC_LITERAL(5, 50, 19), // "bindingPhoneSignals"
QT_MOC_LITERAL(6, 70, 17) // "buyVipListSignals"

    },
    "ZhicloudApp\0changeTaxSignals\0\0strTaxNo\0"
    "strMachine\0bindingPhoneSignals\0"
    "buyVipListSignals"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZhicloudApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    0,   34,    2, 0x06 /* Public */,
       6,    3,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,    2,    2,    2,

       0        // eod
};

void ZhicloudApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZhicloudApp *_t = static_cast<ZhicloudApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeTaxSignals((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->bindingPhoneSignals(); break;
        case 2: _t->buyVipListSignals((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ZhicloudApp::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZhicloudApp::changeTaxSignals)) {
                *result = 0;
            }
        }
        {
            typedef void (ZhicloudApp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZhicloudApp::bindingPhoneSignals)) {
                *result = 1;
            }
        }
        {
            typedef void (ZhicloudApp::*_t)(QStringList , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZhicloudApp::buyVipListSignals)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ZhicloudApp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ZhicloudApp.data,
      qt_meta_data_ZhicloudApp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZhicloudApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZhicloudApp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZhicloudApp.stringdata0))
        return static_cast<void*>(const_cast< ZhicloudApp*>(this));
    return QObject::qt_metacast(_clname);
}

int ZhicloudApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ZhicloudApp::changeTaxSignals(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZhicloudApp::bindingPhoneSignals()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ZhicloudApp::buyVipListSignals(QStringList _t1, QStringList _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
