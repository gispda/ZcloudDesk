/****************************************************************************
** Meta object code from reading C++ file 'SettingWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SettingWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SettingItemWidget_t {
    QByteArrayData data[5];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingItemWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingItemWidget_t qt_meta_stringdata_SettingItemWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SettingItemWidget"
QT_MOC_LITERAL(1, 18, 19), // "sigToolCheckChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "onToolCheckChanged"
QT_MOC_LITERAL(4, 58, 5) // "state"

    },
    "SettingItemWidget\0sigToolCheckChanged\0"
    "\0onToolCheckChanged\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingItemWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   29,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void SettingItemWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingItemWidget *_t = static_cast<SettingItemWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigToolCheckChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->onToolCheckChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SettingItemWidget::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingItemWidget::sigToolCheckChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SettingItemWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SettingItemWidget.data,
      qt_meta_data_SettingItemWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SettingItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SettingItemWidget.stringdata0))
        return static_cast<void*>(const_cast< SettingItemWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SettingItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void SettingItemWidget::sigToolCheckChanged(QString _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_SettingWidget_t {
    QByteArrayData data[33];
    char stringdata0[504];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingWidget_t qt_meta_stringdata_SettingWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SettingWidget"
QT_MOC_LITERAL(1, 14, 18), // "sigTopCheckChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "sigRightCheckChanged"
QT_MOC_LITERAL(4, 55, 19), // "sigToolCheckChanged"
QT_MOC_LITERAL(5, 75, 9), // "strToolId"
QT_MOC_LITERAL(6, 85, 9), // "sigLogout"
QT_MOC_LITERAL(7, 95, 19), // "showNoviceDlgSignal"
QT_MOC_LITERAL(8, 115, 21), // "onDeskSettingBtnClick"
QT_MOC_LITERAL(9, 137, 18), // "onFeedBackBtnClick"
QT_MOC_LITERAL(10, 156, 16), // "onHelperBtnClick"
QT_MOC_LITERAL(11, 173, 17), // "onAboutUsBtnClick"
QT_MOC_LITERAL(12, 191, 17), // "onTopCheckChanged"
QT_MOC_LITERAL(13, 209, 5), // "state"
QT_MOC_LITERAL(14, 215, 19), // "onRightCheckChanged"
QT_MOC_LITERAL(15, 235, 16), // "onCommitBtnClick"
QT_MOC_LITERAL(16, 252, 17), // "onDeskAppBtnClick"
QT_MOC_LITERAL(17, 270, 16), // "onDesignBtnClick"
QT_MOC_LITERAL(18, 287, 15), // "onErrorBtnClick"
QT_MOC_LITERAL(19, 303, 15), // "onMajorBtnClick"
QT_MOC_LITERAL(20, 319, 15), // "onOtherBtnClick"
QT_MOC_LITERAL(21, 335, 13), // "onTextChanged"
QT_MOC_LITERAL(22, 349, 11), // "anyliseJson"
QT_MOC_LITERAL(23, 361, 7), // "strJson"
QT_MOC_LITERAL(24, 369, 8), // "QString&"
QT_MOC_LITERAL(25, 378, 13), // "strFeedBackId"
QT_MOC_LITERAL(26, 392, 14), // "onDemoBtnClick"
QT_MOC_LITERAL(27, 407, 15), // "onGuideBtnClick"
QT_MOC_LITERAL(28, 423, 14), // "onHelpBtnClick"
QT_MOC_LITERAL(29, 438, 18), // "onQuestionBtnClick"
QT_MOC_LITERAL(30, 457, 21), // "onCheckUpdateBtnClick"
QT_MOC_LITERAL(31, 479, 13), // "onLogoutClick"
QT_MOC_LITERAL(32, 493, 10) // "openVerDes"

    },
    "SettingWidget\0sigTopCheckChanged\0\0"
    "sigRightCheckChanged\0sigToolCheckChanged\0"
    "strToolId\0sigLogout\0showNoviceDlgSignal\0"
    "onDeskSettingBtnClick\0onFeedBackBtnClick\0"
    "onHelperBtnClick\0onAboutUsBtnClick\0"
    "onTopCheckChanged\0state\0onRightCheckChanged\0"
    "onCommitBtnClick\0onDeskAppBtnClick\0"
    "onDesignBtnClick\0onErrorBtnClick\0"
    "onMajorBtnClick\0onOtherBtnClick\0"
    "onTextChanged\0anyliseJson\0strJson\0"
    "QString&\0strFeedBackId\0onDemoBtnClick\0"
    "onGuideBtnClick\0onHelpBtnClick\0"
    "onQuestionBtnClick\0onCheckUpdateBtnClick\0"
    "onLogoutClick\0openVerDes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  144,    2, 0x06 /* Public */,
       3,    1,  147,    2, 0x06 /* Public */,
       4,    2,  150,    2, 0x06 /* Public */,
       6,    0,  155,    2, 0x06 /* Public */,
       7,    1,  156,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  159,    2, 0x08 /* Private */,
       9,    0,  160,    2, 0x08 /* Private */,
      10,    0,  161,    2, 0x08 /* Private */,
      11,    0,  162,    2, 0x08 /* Private */,
      12,    1,  163,    2, 0x08 /* Private */,
      14,    1,  166,    2, 0x08 /* Private */,
      15,    0,  169,    2, 0x08 /* Private */,
      16,    0,  170,    2, 0x08 /* Private */,
      17,    0,  171,    2, 0x08 /* Private */,
      18,    0,  172,    2, 0x08 /* Private */,
      19,    0,  173,    2, 0x08 /* Private */,
      20,    0,  174,    2, 0x08 /* Private */,
      21,    0,  175,    2, 0x08 /* Private */,
      22,    2,  176,    2, 0x08 /* Private */,
      26,    0,  181,    2, 0x08 /* Private */,
      27,    0,  182,    2, 0x08 /* Private */,
      28,    0,  183,    2, 0x08 /* Private */,
      29,    0,  184,    2, 0x08 /* Private */,
      30,    0,  185,    2, 0x08 /* Private */,
      31,    0,  186,    2, 0x08 /* Private */,
      32,    0,  187,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    5,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 24,   23,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SettingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SettingWidget *_t = static_cast<SettingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigTopCheckChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sigRightCheckChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sigToolCheckChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->sigLogout(); break;
        case 4: _t->showNoviceDlgSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onDeskSettingBtnClick(); break;
        case 6: _t->onFeedBackBtnClick(); break;
        case 7: _t->onHelperBtnClick(); break;
        case 8: _t->onAboutUsBtnClick(); break;
        case 9: _t->onTopCheckChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onRightCheckChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onCommitBtnClick(); break;
        case 12: _t->onDeskAppBtnClick(); break;
        case 13: _t->onDesignBtnClick(); break;
        case 14: _t->onErrorBtnClick(); break;
        case 15: _t->onMajorBtnClick(); break;
        case 16: _t->onOtherBtnClick(); break;
        case 17: _t->onTextChanged(); break;
        case 18: { int _r = _t->anyliseJson((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 19: _t->onDemoBtnClick(); break;
        case 20: _t->onGuideBtnClick(); break;
        case 21: _t->onHelpBtnClick(); break;
        case 22: _t->onQuestionBtnClick(); break;
        case 23: _t->onCheckUpdateBtnClick(); break;
        case 24: _t->onLogoutClick(); break;
        case 25: _t->openVerDes(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SettingWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingWidget::sigTopCheckChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (SettingWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingWidget::sigRightCheckChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (SettingWidget::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingWidget::sigToolCheckChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (SettingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingWidget::sigLogout)) {
                *result = 3;
            }
        }
        {
            typedef void (SettingWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SettingWidget::showNoviceDlgSignal)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject SettingWidget::staticMetaObject = {
    { &AppCommWidget::staticMetaObject, qt_meta_stringdata_SettingWidget.data,
      qt_meta_data_SettingWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SettingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SettingWidget.stringdata0))
        return static_cast<void*>(const_cast< SettingWidget*>(this));
    return AppCommWidget::qt_metacast(_clname);
}

int SettingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AppCommWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void SettingWidget::sigTopCheckChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SettingWidget::sigRightCheckChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SettingWidget::sigToolCheckChanged(QString _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SettingWidget::sigLogout()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void SettingWidget::showNoviceDlgSignal(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
