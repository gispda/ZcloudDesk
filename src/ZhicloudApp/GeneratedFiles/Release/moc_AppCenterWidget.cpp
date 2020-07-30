/****************************************************************************
** Meta object code from reading C++ file 'AppCenterWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AppCenter/AppCenterWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppCenterWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AppCenterWidget_t {
    QByteArrayData data[18];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppCenterWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppCenterWidget_t qt_meta_stringdata_AppCenterWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AppCenterWidget"
QT_MOC_LITERAL(1, 16, 13), // "installFilish"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 1), // "n"
QT_MOC_LITERAL(4, 33, 12), // "AppDataInfo*"
QT_MOC_LITERAL(5, 46, 5), // "pData"
QT_MOC_LITERAL(6, 52, 13), // "newFlushClass"
QT_MOC_LITERAL(7, 66, 6), // "cateId"
QT_MOC_LITERAL(8, 73, 25), // "on_mainPushButton_clicked"
QT_MOC_LITERAL(9, 99, 7), // "checked"
QT_MOC_LITERAL(10, 107, 29), // "on_categoryPushButton_clicked"
QT_MOC_LITERAL(11, 137, 28), // "on_managerPushButton_clicked"
QT_MOC_LITERAL(12, 166, 25), // "on_downloadButton_clicked"
QT_MOC_LITERAL(13, 192, 22), // "openAppParticularsSlot"
QT_MOC_LITERAL(14, 215, 5), // "appId"
QT_MOC_LITERAL(15, 221, 14), // "onFindBtnClick"
QT_MOC_LITERAL(16, 236, 15), // "addDownloadItem"
QT_MOC_LITERAL(17, 252, 16) // "AppDownLoadItem*"

    },
    "AppCenterWidget\0installFilish\0\0n\0"
    "AppDataInfo*\0pData\0newFlushClass\0"
    "cateId\0on_mainPushButton_clicked\0"
    "checked\0on_categoryPushButton_clicked\0"
    "on_managerPushButton_clicked\0"
    "on_downloadButton_clicked\0"
    "openAppParticularsSlot\0appId\0"
    "onFindBtnClick\0addDownloadItem\0"
    "AppDownLoadItem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppCenterWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       6,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   87,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x28 /* Private | MethodCloned */,
      10,    1,   91,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x28 /* Private | MethodCloned */,
      11,    1,   95,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x28 /* Private | MethodCloned */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      13,    1,  101,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    2,

       0        // eod
};

void AppCenterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppCenterWidget *_t = static_cast<AppCenterWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->installFilish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< AppDataInfo*(*)>(_a[2]))); break;
        case 1: _t->newFlushClass((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_mainPushButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_mainPushButton_clicked(); break;
        case 4: _t->on_categoryPushButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_categoryPushButton_clicked(); break;
        case 6: _t->on_managerPushButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_managerPushButton_clicked(); break;
        case 8: _t->on_downloadButton_clicked(); break;
        case 9: _t->openAppParticularsSlot(); break;
        case 10: _t->openAppParticularsSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->onFindBtnClick(); break;
        case 12: _t->addDownloadItem((*reinterpret_cast< AppDownLoadItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AppDownLoadItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AppCenterWidget::*_t)(int , AppDataInfo * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppCenterWidget::installFilish)) {
                *result = 0;
            }
        }
        {
            typedef void (AppCenterWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppCenterWidget::newFlushClass)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject AppCenterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AppCenterWidget.data,
      qt_meta_data_AppCenterWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AppCenterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppCenterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AppCenterWidget.stringdata0))
        return static_cast<void*>(const_cast< AppCenterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AppCenterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void AppCenterWidget::installFilish(int _t1, AppDataInfo * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppCenterWidget::newFlushClass(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
