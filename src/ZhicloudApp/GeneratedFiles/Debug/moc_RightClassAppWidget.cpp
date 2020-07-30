/****************************************************************************
** Meta object code from reading C++ file 'RightClassAppWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RightClassAppWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RightClassAppWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ReturnThread_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReturnThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReturnThread_t qt_meta_stringdata_ReturnThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ReturnThread"
QT_MOC_LITERAL(1, 13, 12), // "threadReturn"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "ReturnThread\0threadReturn\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReturnThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void ReturnThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReturnThread *_t = static_cast<ReturnThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->threadReturn((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ReturnThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ReturnThread::threadReturn)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ReturnThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ReturnThread.data,
      qt_meta_data_ReturnThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ReturnThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReturnThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ReturnThread.stringdata0))
        return static_cast<void*>(const_cast< ReturnThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ReturnThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ReturnThread::threadReturn(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_RightAppsWidget_t {
    QByteArrayData data[4];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RightAppsWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RightAppsWidget_t qt_meta_stringdata_RightAppsWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "RightAppsWidget"
QT_MOC_LITERAL(1, 16, 16), // "drawShowAppsSlot"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16) // "drawHideAppsSlot"

    },
    "RightAppsWidget\0drawShowAppsSlot\0\0"
    "drawHideAppsSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RightAppsWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RightAppsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RightAppsWidget *_t = static_cast<RightAppsWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawShowAppsSlot(); break;
        case 1: _t->drawHideAppsSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RightAppsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RightAppsWidget.data,
      qt_meta_data_RightAppsWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RightAppsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RightAppsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RightAppsWidget.stringdata0))
        return static_cast<void*>(const_cast< RightAppsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int RightAppsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_RightClassAppWidget_t {
    QByteArrayData data[21];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RightClassAppWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RightClassAppWidget_t qt_meta_stringdata_RightClassAppWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "RightClassAppWidget"
QT_MOC_LITERAL(1, 20, 16), // "changeTaxSignals"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "strTaxNo"
QT_MOC_LITERAL(4, 47, 10), // "strMachine"
QT_MOC_LITERAL(5, 58, 19), // "bindingPhoneSignals"
QT_MOC_LITERAL(6, 78, 17), // "buyVipListSignals"
QT_MOC_LITERAL(7, 96, 7), // "openApp"
QT_MOC_LITERAL(8, 104, 11), // "AppDataInfo"
QT_MOC_LITERAL(9, 116, 5), // "pData"
QT_MOC_LITERAL(10, 122, 10), // "Operand_id"
QT_MOC_LITERAL(11, 133, 11), // "flushButton"
QT_MOC_LITERAL(12, 145, 7), // "classId"
QT_MOC_LITERAL(13, 153, 9), // "flushFlag"
QT_MOC_LITERAL(14, 163, 23), // "installUnnstallSucessed"
QT_MOC_LITERAL(15, 187, 8), // "drawShow"
QT_MOC_LITERAL(16, 196, 8), // "drawHide"
QT_MOC_LITERAL(17, 205, 10), // "clickBtnOp"
QT_MOC_LITERAL(18, 216, 9), // "initClass"
QT_MOC_LITERAL(19, 226, 8), // "clickbtn"
QT_MOC_LITERAL(20, 235, 14) // "resetInterface"

    },
    "RightClassAppWidget\0changeTaxSignals\0"
    "\0strTaxNo\0strMachine\0bindingPhoneSignals\0"
    "buyVipListSignals\0openApp\0AppDataInfo\0"
    "pData\0Operand_id\0flushButton\0classId\0"
    "flushFlag\0installUnnstallSucessed\0"
    "drawShow\0drawHide\0clickBtnOp\0initClass\0"
    "clickbtn\0resetInterface"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RightClassAppWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       5,    0,   94,    2, 0x06 /* Public */,
       6,    3,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,  102,    2, 0x0a /* Public */,
       7,    1,  107,    2, 0x2a /* Public | MethodCloned */,
      11,    2,  110,    2, 0x0a /* Public */,
      11,    1,  115,    2, 0x2a /* Public | MethodCloned */,
      11,    0,  118,    2, 0x2a /* Public | MethodCloned */,
      14,    1,  119,    2, 0x0a /* Public */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    1,  124,    2, 0x08 /* Private */,
      18,    0,  127,    2, 0x08 /* Private */,
      19,    0,  128,    2, 0x08 /* Private */,
      20,    0,  129,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,    2,    2,    2,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 8, QMetaType::QString,    9,   10,
    QMetaType::Bool, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   12,   13,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RightClassAppWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RightClassAppWidget *_t = static_cast<RightClassAppWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeTaxSignals((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->bindingPhoneSignals(); break;
        case 2: _t->buyVipListSignals((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 3: { bool _r = _t->openApp((*reinterpret_cast< AppDataInfo(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->openApp((*reinterpret_cast< AppDataInfo(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->flushButton((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->flushButton((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->flushButton(); break;
        case 8: _t->installUnnstallSucessed((*reinterpret_cast< AppDataInfo(*)>(_a[1]))); break;
        case 9: _t->drawShow(); break;
        case 10: _t->drawHide(); break;
        case 11: _t->clickBtnOp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->initClass(); break;
        case 13: _t->clickbtn(); break;
        case 14: _t->resetInterface(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RightClassAppWidget::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RightClassAppWidget::changeTaxSignals)) {
                *result = 0;
            }
        }
        {
            typedef void (RightClassAppWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RightClassAppWidget::bindingPhoneSignals)) {
                *result = 1;
            }
        }
        {
            typedef void (RightClassAppWidget::*_t)(QStringList , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RightClassAppWidget::buyVipListSignals)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject RightClassAppWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RightClassAppWidget.data,
      qt_meta_data_RightClassAppWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RightClassAppWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RightClassAppWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RightClassAppWidget.stringdata0))
        return static_cast<void*>(const_cast< RightClassAppWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int RightClassAppWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void RightClassAppWidget::changeTaxSignals(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RightClassAppWidget::bindingPhoneSignals()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void RightClassAppWidget::buyVipListSignals(QStringList _t1, QStringList _t2, QStringList _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
