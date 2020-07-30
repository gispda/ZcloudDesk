/****************************************************************************
** Meta object code from reading C++ file 'ZBrowser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ZBrowser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ZBrowser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZBrowser_t {
    QByteArrayData data[17];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZBrowser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZBrowser_t qt_meta_stringdata_ZBrowser = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ZBrowser"
QT_MOC_LITERAL(1, 9, 8), // "flushWeb"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "stopFlushWeb"
QT_MOC_LITERAL(4, 32, 25), // "on_backPushButton_clicked"
QT_MOC_LITERAL(5, 58, 28), // "on_forwardPushButton_clicked"
QT_MOC_LITERAL(6, 87, 24), // "on_maxPushButton_clicked"
QT_MOC_LITERAL(7, 112, 25), // "on_miniPushButton_clicked"
QT_MOC_LITERAL(8, 138, 26), // "on_closePushButton_clicked"
QT_MOC_LITERAL(9, 165, 25), // "handleWebViewLoadProgress"
QT_MOC_LITERAL(10, 191, 8), // "progress"
QT_MOC_LITERAL(11, 200, 29), // "handleWebActionEnabledChanged"
QT_MOC_LITERAL(12, 230, 19), // "QWebPage::WebAction"
QT_MOC_LITERAL(13, 250, 6), // "action"
QT_MOC_LITERAL(14, 257, 7), // "enabled"
QT_MOC_LITERAL(15, 265, 17), // "downloadRequested"
QT_MOC_LITERAL(16, 283, 14) // "QNetworkReply*"

    },
    "ZBrowser\0flushWeb\0\0stopFlushWeb\0"
    "on_backPushButton_clicked\0"
    "on_forwardPushButton_clicked\0"
    "on_maxPushButton_clicked\0"
    "on_miniPushButton_clicked\0"
    "on_closePushButton_clicked\0"
    "handleWebViewLoadProgress\0progress\0"
    "handleWebActionEnabledChanged\0"
    "QWebPage::WebAction\0action\0enabled\0"
    "downloadRequested\0QNetworkReply*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZBrowser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    1,   71,    2, 0x08 /* Private */,
      11,    2,   74,    2, 0x08 /* Private */,
      15,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Bool,   13,   14,
    QMetaType::Void, 0x80000000 | 16,    2,

       0        // eod
};

void ZBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZBrowser *_t = static_cast<ZBrowser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->flushWeb(); break;
        case 1: _t->stopFlushWeb(); break;
        case 2: _t->on_backPushButton_clicked(); break;
        case 3: _t->on_forwardPushButton_clicked(); break;
        case 4: _t->on_maxPushButton_clicked(); break;
        case 5: _t->on_miniPushButton_clicked(); break;
        case 6: _t->on_closePushButton_clicked(); break;
        case 7: _t->handleWebViewLoadProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->handleWebActionEnabledChanged((*reinterpret_cast< QWebPage::WebAction(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->downloadRequested((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ZBrowser::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ZBrowser.data,
      qt_meta_data_ZBrowser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZBrowser.stringdata0))
        return static_cast<void*>(const_cast< ZBrowser*>(this));
    return QWidget::qt_metacast(_clname);
}

int ZBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
