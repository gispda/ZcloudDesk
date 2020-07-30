/****************************************************************************
** Meta object code from reading C++ file 'LoginWidgets.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LoginWidgets.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginWidgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoginLineEdit_t {
    QByteArrayData data[4];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginLineEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginLineEdit_t qt_meta_stringdata_LoginLineEdit = {
    {
QT_MOC_LITERAL(0, 0, 13), // "LoginLineEdit"
QT_MOC_LITERAL(1, 14, 13), // "focusInSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14) // "focusOutSignal"

    },
    "LoginLineEdit\0focusInSignal\0\0"
    "focusOutSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginLineEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoginLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginLineEdit *_t = static_cast<LoginLineEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->focusInSignal(); break;
        case 1: _t->focusOutSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginLineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginLineEdit::focusInSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (LoginLineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginLineEdit::focusOutSignal)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject LoginLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_LoginLineEdit.data,
      qt_meta_data_LoginLineEdit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoginLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoginLineEdit.stringdata0))
        return static_cast<void*>(const_cast< LoginLineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int LoginLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LoginLineEdit::focusInSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void LoginLineEdit::focusOutSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
struct qt_meta_stringdata_LoginSetWidget_t {
    QByteArrayData data[8];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginSetWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginSetWidget_t qt_meta_stringdata_LoginSetWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "LoginSetWidget"
QT_MOC_LITERAL(1, 15, 19), // "cancelButtonSignals"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 17), // "lodingStartSiganl"
QT_MOC_LITERAL(4, 54, 18), // "lodingFilishSiganl"
QT_MOC_LITERAL(5, 73, 12), // "checkclicked"
QT_MOC_LITERAL(6, 86, 10), // "testClicke"
QT_MOC_LITERAL(7, 97, 25) // "setTypeCurentIndexChanged"

    },
    "LoginSetWidget\0cancelButtonSignals\0\0"
    "lodingStartSiganl\0lodingFilishSiganl\0"
    "checkclicked\0testClicke\0"
    "setTypeCurentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginSetWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void LoginSetWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginSetWidget *_t = static_cast<LoginSetWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cancelButtonSignals(); break;
        case 1: _t->lodingStartSiganl(); break;
        case 2: _t->lodingFilishSiganl(); break;
        case 3: _t->checkclicked(); break;
        case 4: { bool _r = _t->testClicke();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->setTypeCurentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginSetWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginSetWidget::cancelButtonSignals)) {
                *result = 0;
            }
        }
        {
            typedef void (LoginSetWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginSetWidget::lodingStartSiganl)) {
                *result = 1;
            }
        }
        {
            typedef void (LoginSetWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginSetWidget::lodingFilishSiganl)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject LoginSetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginSetWidget.data,
      qt_meta_data_LoginSetWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoginSetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginSetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoginSetWidget.stringdata0))
        return static_cast<void*>(const_cast< LoginSetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoginSetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void LoginSetWidget::cancelButtonSignals()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void LoginSetWidget::lodingStartSiganl()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void LoginSetWidget::lodingFilishSiganl()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
struct qt_meta_stringdata_LoginWidget_t {
    QByteArrayData data[17];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginWidget_t qt_meta_stringdata_LoginWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LoginWidget"
QT_MOC_LITERAL(1, 12, 17), // "lodingStartSiganl"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "lodingFilishSiganl"
QT_MOC_LITERAL(4, 50, 13), // "logingSucceed"
QT_MOC_LITERAL(5, 64, 18), // "qrChartLoginSingal"
QT_MOC_LITERAL(6, 83, 21), // "installSoftwareSignal"
QT_MOC_LITERAL(7, 105, 20), // "onLoginButtonClicked"
QT_MOC_LITERAL(8, 126, 10), // "checkLogin"
QT_MOC_LITERAL(9, 137, 8), // "QString&"
QT_MOC_LITERAL(10, 146, 6), // "tipStr"
QT_MOC_LITERAL(11, 153, 11), // "loginFinish"
QT_MOC_LITERAL(12, 165, 7), // "stataus"
QT_MOC_LITERAL(13, 173, 14), // "UserInfoStruct"
QT_MOC_LITERAL(14, 188, 14), // "userInfoStruct"
QT_MOC_LITERAL(15, 203, 9), // "getFinish"
QT_MOC_LITERAL(16, 213, 6) // "status"

    },
    "LoginWidget\0lodingStartSiganl\0\0"
    "lodingFilishSiganl\0logingSucceed\0"
    "qrChartLoginSingal\0installSoftwareSignal\0"
    "onLoginButtonClicked\0checkLogin\0"
    "QString&\0tipStr\0loginFinish\0stataus\0"
    "UserInfoStruct\0userInfoStruct\0getFinish\0"
    "status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   64,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,
      11,    2,   68,    2, 0x08 /* Private */,
      15,    1,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,   12,   14,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void LoginWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginWidget *_t = static_cast<LoginWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lodingStartSiganl(); break;
        case 1: _t->lodingFilishSiganl(); break;
        case 2: _t->logingSucceed(); break;
        case 3: _t->qrChartLoginSingal(); break;
        case 4: _t->installSoftwareSignal(); break;
        case 5: _t->onLoginButtonClicked(); break;
        case 6: { int _r = _t->checkLogin((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->loginFinish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< UserInfoStruct(*)>(_a[2]))); break;
        case 8: _t->getFinish((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginWidget::lodingStartSiganl)) {
                *result = 0;
            }
        }
        {
            typedef void (LoginWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginWidget::lodingFilishSiganl)) {
                *result = 1;
            }
        }
        {
            typedef void (LoginWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginWidget::logingSucceed)) {
                *result = 2;
            }
        }
        {
            typedef void (LoginWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginWidget::qrChartLoginSingal)) {
                *result = 3;
            }
        }
        {
            typedef void (LoginWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginWidget::installSoftwareSignal)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject LoginWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginWidget.data,
      qt_meta_data_LoginWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoginWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoginWidget.stringdata0))
        return static_cast<void*>(const_cast< LoginWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoginWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LoginWidget::lodingStartSiganl()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void LoginWidget::lodingFilishSiganl()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void LoginWidget::logingSucceed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void LoginWidget::qrChartLoginSingal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void LoginWidget::installSoftwareSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
struct qt_meta_stringdata_LoginWeChartWidget_t {
    QByteArrayData data[12];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginWeChartWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginWeChartWidget_t qt_meta_stringdata_LoginWeChartWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "LoginWeChartWidget"
QT_MOC_LITERAL(1, 19, 20), // "changeLoginWaySiganl"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 19), // "weChartLoginSucceed"
QT_MOC_LITERAL(4, 61, 14), // "UserInfoStruct"
QT_MOC_LITERAL(5, 76, 19), // "showWCWidgetSignals"
QT_MOC_LITERAL(6, 96, 21), // "installSoftwareSignal"
QT_MOC_LITERAL(7, 118, 12), // "showWCWidget"
QT_MOC_LITERAL(8, 131, 1), // "i"
QT_MOC_LITERAL(9, 133, 16), // "bindingFlishSlot"
QT_MOC_LITERAL(10, 150, 6), // "status"
QT_MOC_LITERAL(11, 157, 14) // "userInfoStruct"

    },
    "LoginWeChartWidget\0changeLoginWaySiganl\0"
    "\0weChartLoginSucceed\0UserInfoStruct\0"
    "showWCWidgetSignals\0installSoftwareSignal\0"
    "showWCWidget\0i\0bindingFlishSlot\0status\0"
    "userInfoStruct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginWeChartWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   54,    2, 0x08 /* Private */,
       9,    2,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,   10,   11,

       0        // eod
};

void LoginWeChartWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginWeChartWidget *_t = static_cast<LoginWeChartWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeLoginWaySiganl((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->weChartLoginSucceed((*reinterpret_cast< UserInfoStruct(*)>(_a[1]))); break;
        case 2: _t->showWCWidgetSignals((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->installSoftwareSignal(); break;
        case 4: _t->showWCWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->bindingFlishSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< UserInfoStruct(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginWeChartWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginWeChartWidget::changeLoginWaySiganl)) {
                *result = 0;
            }
        }
        {
            typedef void (LoginWeChartWidget::*_t)(UserInfoStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginWeChartWidget::weChartLoginSucceed)) {
                *result = 1;
            }
        }
        {
            typedef void (LoginWeChartWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginWeChartWidget::showWCWidgetSignals)) {
                *result = 2;
            }
        }
        {
            typedef void (LoginWeChartWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginWeChartWidget::installSoftwareSignal)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject LoginWeChartWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginWeChartWidget.data,
      qt_meta_data_LoginWeChartWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoginWeChartWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginWeChartWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoginWeChartWidget.stringdata0))
        return static_cast<void*>(const_cast< LoginWeChartWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoginWeChartWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void LoginWeChartWidget::changeLoginWaySiganl(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginWeChartWidget::weChartLoginSucceed(UserInfoStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LoginWeChartWidget::showWCWidgetSignals(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LoginWeChartWidget::installSoftwareSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
struct qt_meta_stringdata_BindingEinWidget_t {
    QByteArrayData data[9];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BindingEinWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BindingEinWidget_t qt_meta_stringdata_BindingEinWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "BindingEinWidget"
QT_MOC_LITERAL(1, 17, 20), // "changeLoginWaySiganl"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 17), // "bindingEinSoucces"
QT_MOC_LITERAL(4, 57, 14), // "UserInfoStruct"
QT_MOC_LITERAL(5, 72, 8), // "userInfo"
QT_MOC_LITERAL(6, 81, 15), // "putInButtonSlot"
QT_MOC_LITERAL(7, 97, 13), // "getFilishSlot"
QT_MOC_LITERAL(8, 111, 6) // "status"

    },
    "BindingEinWidget\0changeLoginWaySiganl\0"
    "\0bindingEinSoucces\0UserInfoStruct\0"
    "userInfo\0putInButtonSlot\0getFilishSlot\0"
    "status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BindingEinWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x08 /* Private */,
       7,    2,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    8,    2,

       0        // eod
};

void BindingEinWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BindingEinWidget *_t = static_cast<BindingEinWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeLoginWaySiganl((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->bindingEinSoucces((*reinterpret_cast< UserInfoStruct(*)>(_a[1]))); break;
        case 2: _t->putInButtonSlot(); break;
        case 3: _t->getFilishSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< UserInfoStruct(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BindingEinWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BindingEinWidget::changeLoginWaySiganl)) {
                *result = 0;
            }
        }
        {
            typedef void (BindingEinWidget::*_t)(UserInfoStruct );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BindingEinWidget::bindingEinSoucces)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject BindingEinWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BindingEinWidget.data,
      qt_meta_data_BindingEinWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BindingEinWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BindingEinWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BindingEinWidget.stringdata0))
        return static_cast<void*>(const_cast< BindingEinWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BindingEinWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void BindingEinWidget::changeLoginWaySiganl(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BindingEinWidget::bindingEinSoucces(UserInfoStruct _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
