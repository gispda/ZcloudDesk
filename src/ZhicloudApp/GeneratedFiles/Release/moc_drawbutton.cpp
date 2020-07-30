/****************************************************************************
** Meta object code from reading C++ file 'drawbutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../publicWidgets/drawbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DragButton_t {
    QByteArrayData data[16];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DragButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DragButton_t qt_meta_stringdata_DragButton = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DragButton"
QT_MOC_LITERAL(1, 11, 14), // "release_signal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "drag_signal"
QT_MOC_LITERAL(4, 39, 11), // "dragClicked"
QT_MOC_LITERAL(5, 51, 17), // "dragDoubleClicked"
QT_MOC_LITERAL(6, 69, 13), // "closeDownload"
QT_MOC_LITERAL(7, 83, 6), // "zoomIn"
QT_MOC_LITERAL(8, 90, 7), // "zoomOut"
QT_MOC_LITERAL(9, 98, 9), // "hold_slot"
QT_MOC_LITERAL(10, 108, 17), // "upDownloadProcess"
QT_MOC_LITERAL(11, 126, 13), // "bytesReceived"
QT_MOC_LITERAL(12, 140, 10), // "bytesTotal"
QT_MOC_LITERAL(13, 151, 15), // "upStatusChanged"
QT_MOC_LITERAL(14, 167, 16), // "APPDOWNLOADETYPE"
QT_MOC_LITERAL(15, 184, 15) // "appDownloadType"

    },
    "DragButton\0release_signal\0\0drag_signal\0"
    "dragClicked\0dragDoubleClicked\0"
    "closeDownload\0zoomIn\0zoomOut\0hold_slot\0"
    "upDownloadProcess\0bytesReceived\0"
    "bytesTotal\0upStatusChanged\0APPDOWNLOADETYPE\0"
    "appDownloadType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DragButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   71,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,
      10,    2,   74,    2, 0x08 /* Private */,
      13,    1,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void DragButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DragButton *_t = static_cast<DragButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->release_signal(); break;
        case 1: _t->drag_signal(); break;
        case 2: _t->dragClicked(); break;
        case 3: _t->dragDoubleClicked(); break;
        case 4: _t->closeDownload((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->zoomIn(); break;
        case 6: _t->zoomOut(); break;
        case 7: _t->hold_slot(); break;
        case 8: _t->upDownloadProcess((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 9: _t->upStatusChanged((*reinterpret_cast< APPDOWNLOADETYPE(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DragButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DragButton::release_signal)) {
                *result = 0;
            }
        }
        {
            typedef void (DragButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DragButton::drag_signal)) {
                *result = 1;
            }
        }
        {
            typedef void (DragButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DragButton::dragClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (DragButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DragButton::dragDoubleClicked)) {
                *result = 3;
            }
        }
        {
            typedef void (DragButton::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DragButton::closeDownload)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject DragButton::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_DragButton.data,
      qt_meta_data_DragButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DragButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DragButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DragButton.stringdata0))
        return static_cast<void*>(const_cast< DragButton*>(this));
    return QToolButton::qt_metacast(_clname);
}

int DragButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
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
void DragButton::release_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DragButton::drag_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void DragButton::dragClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void DragButton::dragDoubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void DragButton::closeDownload(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
