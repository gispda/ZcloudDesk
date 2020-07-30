/****************************************************************************
** Meta object code from reading C++ file 'zwebview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../zwebview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zwebview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ZWebPage_t {
    QByteArrayData data[8];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZWebPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZWebPage_t qt_meta_stringdata_ZWebPage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ZWebPage"
QT_MOC_LITERAL(1, 9, 10), // "loadingUrl"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 3), // "url"
QT_MOC_LITERAL(4, 25, 13), // "downloadReply"
QT_MOC_LITERAL(5, 39, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 54, 5), // "reply"
QT_MOC_LITERAL(7, 60, 24) // "handleUnsupportedContent"

    },
    "ZWebPage\0loadingUrl\0\0url\0downloadReply\0"
    "QNetworkReply*\0reply\0handleUnsupportedContent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZWebPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QUrl,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void ZWebPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZWebPage *_t = static_cast<ZWebPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadingUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 1: _t->downloadReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->handleUnsupportedContent((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ZWebPage::*_t)(const QUrl & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZWebPage::loadingUrl)) {
                *result = 0;
            }
        }
        {
            typedef void (ZWebPage::*_t)(QNetworkReply * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZWebPage::downloadReply)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ZWebPage::staticMetaObject = {
    { &QWebPage::staticMetaObject, qt_meta_stringdata_ZWebPage.data,
      qt_meta_data_ZWebPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZWebPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZWebPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZWebPage.stringdata0))
        return static_cast<void*>(const_cast< ZWebPage*>(this));
    return QWebPage::qt_metacast(_clname);
}

int ZWebPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebPage::qt_metacall(_c, _id, _a);
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
void ZWebPage::loadingUrl(const QUrl & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZWebPage::downloadReply(QNetworkReply * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_ZWebView_t {
    QByteArrayData data[17];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZWebView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZWebView_t qt_meta_stringdata_ZWebView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ZWebView"
QT_MOC_LITERAL(1, 9, 23), // "webActionEnabledChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "QWebPage::WebAction"
QT_MOC_LITERAL(4, 54, 9), // "webAction"
QT_MOC_LITERAL(5, 64, 7), // "enabled"
QT_MOC_LITERAL(6, 72, 21), // "downloadRequestSignal"
QT_MOC_LITERAL(7, 94, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 109, 16), // "setStatusBarText"
QT_MOC_LITERAL(9, 126, 6), // "string"
QT_MOC_LITERAL(10, 133, 11), // "setProgress"
QT_MOC_LITERAL(11, 145, 8), // "progress"
QT_MOC_LITERAL(12, 154, 12), // "loadFinished"
QT_MOC_LITERAL(13, 167, 17), // "downloadRequested"
QT_MOC_LITERAL(14, 185, 7), // "request"
QT_MOC_LITERAL(15, 193, 16), // "openLinkInNewTab"
QT_MOC_LITERAL(16, 210, 12) // "openLinkSlot"

    },
    "ZWebView\0webActionEnabledChanged\0\0"
    "QWebPage::WebAction\0webAction\0enabled\0"
    "downloadRequestSignal\0QNetworkReply*\0"
    "setStatusBarText\0string\0setProgress\0"
    "progress\0loadFinished\0downloadRequested\0"
    "request\0openLinkInNewTab\0openLinkSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZWebView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       6,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   62,    2, 0x08 /* Private */,
      10,    1,   65,    2, 0x08 /* Private */,
      12,    0,   68,    2, 0x08 /* Private */,
      13,    1,   69,    2, 0x08 /* Private */,
      15,    0,   72,    2, 0x08 /* Private */,
      16,    1,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    2,

       0        // eod
};

void ZWebView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZWebView *_t = static_cast<ZWebView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->webActionEnabledChanged((*reinterpret_cast< QWebPage::WebAction(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->downloadRequestSignal((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->setStatusBarText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->loadFinished(); break;
        case 5: _t->downloadRequested((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->openLinkInNewTab(); break;
        case 7: _t->openLinkSlot((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ZWebView::*_t)(QWebPage::WebAction , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZWebView::webActionEnabledChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ZWebView::*_t)(QNetworkReply * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ZWebView::downloadRequestSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ZWebView::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_ZWebView.data,
      qt_meta_data_ZWebView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ZWebView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZWebView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ZWebView.stringdata0))
        return static_cast<void*>(const_cast< ZWebView*>(this));
    return QWebView::qt_metacast(_clname);
}

int ZWebView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ZWebView::webActionEnabledChanged(QWebPage::WebAction _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZWebView::downloadRequestSignal(QNetworkReply * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
