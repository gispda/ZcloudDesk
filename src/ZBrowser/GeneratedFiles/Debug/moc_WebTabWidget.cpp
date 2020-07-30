/****************************************************************************
** Meta object code from reading C++ file 'WebTabWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WebTabWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WebTabWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TabBar_t {
    QByteArrayData data[1];
    char stringdata0[7];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabBar_t qt_meta_stringdata_TabBar = {
    {
QT_MOC_LITERAL(0, 0, 6) // "TabBar"

    },
    "TabBar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void TabBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject TabBar::staticMetaObject = {
    { &QTabBar::staticMetaObject, qt_meta_stringdata_TabBar.data,
      qt_meta_data_TabBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TabBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TabBar.stringdata0))
        return static_cast<void*>(const_cast< TabBar*>(this));
    return QTabBar::qt_metacast(_clname);
}

int TabBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_WebTabWidget_t {
    QByteArrayData data[40];
    char stringdata0[525];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WebTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WebTabWidget_t qt_meta_stringdata_WebTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WebTabWidget"
QT_MOC_LITERAL(1, 13, 8), // "loadPage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "url"
QT_MOC_LITERAL(4, 27, 11), // "tabsChanged"
QT_MOC_LITERAL(5, 39, 13), // "lastTabClosed"
QT_MOC_LITERAL(6, 53, 15), // "setCurrentTitle"
QT_MOC_LITERAL(7, 69, 20), // "showStatusBarMessage"
QT_MOC_LITERAL(8, 90, 7), // "message"
QT_MOC_LITERAL(9, 98, 11), // "linkHovered"
QT_MOC_LITERAL(10, 110, 4), // "link"
QT_MOC_LITERAL(11, 115, 23), // "geometryChangeRequested"
QT_MOC_LITERAL(12, 139, 8), // "geometry"
QT_MOC_LITERAL(13, 148, 32), // "menuBarVisibilityChangeRequested"
QT_MOC_LITERAL(14, 181, 7), // "visible"
QT_MOC_LITERAL(15, 189, 34), // "statusBarVisibilityChangeRequ..."
QT_MOC_LITERAL(16, 224, 32), // "toolBarVisibilityChangeRequested"
QT_MOC_LITERAL(17, 257, 14), // "printRequested"
QT_MOC_LITERAL(18, 272, 10), // "QWebFrame*"
QT_MOC_LITERAL(19, 283, 5), // "frame"
QT_MOC_LITERAL(20, 289, 8), // "download"
QT_MOC_LITERAL(21, 298, 14), // "QNetworkReply*"
QT_MOC_LITERAL(22, 313, 12), // "loadProgress"
QT_MOC_LITERAL(23, 326, 8), // "progress"
QT_MOC_LITERAL(24, 335, 23), // "webActionEnabledChanged"
QT_MOC_LITERAL(25, 359, 19), // "QWebPage::WebAction"
QT_MOC_LITERAL(26, 379, 6), // "action"
QT_MOC_LITERAL(27, 386, 7), // "enabled"
QT_MOC_LITERAL(28, 394, 14), // "tabWidgetClose"
QT_MOC_LITERAL(29, 409, 12), // "titleChanged"
QT_MOC_LITERAL(30, 422, 5), // "title"
QT_MOC_LITERAL(31, 428, 6), // "newTab"
QT_MOC_LITERAL(32, 435, 9), // "ZWebView*"
QT_MOC_LITERAL(33, 445, 11), // "makeCurrent"
QT_MOC_LITERAL(34, 457, 6), // "setUrl"
QT_MOC_LITERAL(35, 464, 8), // "closeTab"
QT_MOC_LITERAL(36, 473, 5), // "index"
QT_MOC_LITERAL(37, 479, 11), // "clostTabAll"
QT_MOC_LITERAL(38, 491, 20), // "handleCurrentChanged"
QT_MOC_LITERAL(39, 512, 12) // "choosMainTab"

    },
    "WebTabWidget\0loadPage\0\0url\0tabsChanged\0"
    "lastTabClosed\0setCurrentTitle\0"
    "showStatusBarMessage\0message\0linkHovered\0"
    "link\0geometryChangeRequested\0geometry\0"
    "menuBarVisibilityChangeRequested\0"
    "visible\0statusBarVisibilityChangeRequested\0"
    "toolBarVisibilityChangeRequested\0"
    "printRequested\0QWebFrame*\0frame\0"
    "download\0QNetworkReply*\0loadProgress\0"
    "progress\0webActionEnabledChanged\0"
    "QWebPage::WebAction\0action\0enabled\0"
    "tabWidgetClose\0titleChanged\0title\0"
    "newTab\0ZWebView*\0makeCurrent\0setUrl\0"
    "closeTab\0index\0clostTabAll\0"
    "handleCurrentChanged\0choosMainTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WebTabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  129,    2, 0x06 /* Public */,
       4,    0,  132,    2, 0x06 /* Public */,
       5,    0,  133,    2, 0x06 /* Public */,
       6,    1,  134,    2, 0x06 /* Public */,
       7,    1,  137,    2, 0x06 /* Public */,
       9,    1,  140,    2, 0x06 /* Public */,
      11,    1,  143,    2, 0x06 /* Public */,
      13,    1,  146,    2, 0x06 /* Public */,
      15,    1,  149,    2, 0x06 /* Public */,
      16,    1,  152,    2, 0x06 /* Public */,
      17,    1,  155,    2, 0x06 /* Public */,
      20,    1,  158,    2, 0x06 /* Public */,
      22,    1,  161,    2, 0x06 /* Public */,
      24,    2,  164,    2, 0x06 /* Public */,
      28,    0,  169,    2, 0x06 /* Public */,
      29,    1,  170,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      31,    1,  173,    2, 0x0a /* Public */,
      31,    0,  176,    2, 0x2a /* Public | MethodCloned */,
      34,    1,  177,    2, 0x0a /* Public */,
      35,    1,  180,    2, 0x0a /* Public */,
      37,    0,  183,    2, 0x0a /* Public */,
      38,    1,  184,    2, 0x08 /* Private */,
      39,    0,  187,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QRect,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, 0x80000000 | 25, QMetaType::Bool,   26,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   30,

 // slots: parameters
    0x80000000 | 32, QMetaType::Bool,   33,
    0x80000000 | 32,
    QMetaType::Void, QMetaType::QUrl,    3,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void,

       0        // eod
};

void WebTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WebTabWidget *_t = static_cast<WebTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadPage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->tabsChanged(); break;
        case 2: _t->lastTabClosed(); break;
        case 3: _t->setCurrentTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->showStatusBarMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->linkHovered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->geometryChangeRequested((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 7: _t->menuBarVisibilityChangeRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->statusBarVisibilityChangeRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->toolBarVisibilityChangeRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->printRequested((*reinterpret_cast< QWebFrame*(*)>(_a[1]))); break;
        case 11: _t->download((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 12: _t->loadProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->webActionEnabledChanged((*reinterpret_cast< QWebPage::WebAction(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: _t->tabWidgetClose(); break;
        case 15: _t->titleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: { ZWebView* _r = _t->newTab((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< ZWebView**>(_a[0]) = _r; }  break;
        case 17: { ZWebView* _r = _t->newTab();
            if (_a[0]) *reinterpret_cast< ZWebView**>(_a[0]) = _r; }  break;
        case 18: _t->setUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 19: _t->closeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->clostTabAll(); break;
        case 21: _t->handleCurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->choosMainTab(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWebFrame* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WebTabWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::loadPage)) {
                *result = 0;
            }
        }
        {
            typedef void (WebTabWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::tabsChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (WebTabWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::lastTabClosed)) {
                *result = 2;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::setCurrentTitle)) {
                *result = 3;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::showStatusBarMessage)) {
                *result = 4;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::linkHovered)) {
                *result = 5;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(const QRect & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::geometryChangeRequested)) {
                *result = 6;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::menuBarVisibilityChangeRequested)) {
                *result = 7;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::statusBarVisibilityChangeRequested)) {
                *result = 8;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::toolBarVisibilityChangeRequested)) {
                *result = 9;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(QWebFrame * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::printRequested)) {
                *result = 10;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(QNetworkReply * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::download)) {
                *result = 11;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::loadProgress)) {
                *result = 12;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(QWebPage::WebAction , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::webActionEnabledChanged)) {
                *result = 13;
            }
        }
        {
            typedef void (WebTabWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::tabWidgetClose)) {
                *result = 14;
            }
        }
        {
            typedef void (WebTabWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WebTabWidget::titleChanged)) {
                *result = 15;
            }
        }
    }
}

const QMetaObject WebTabWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_WebTabWidget.data,
      qt_meta_data_WebTabWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WebTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WebTabWidget.stringdata0))
        return static_cast<void*>(const_cast< WebTabWidget*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int WebTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void WebTabWidget::loadPage(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WebTabWidget::tabsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void WebTabWidget::lastTabClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void WebTabWidget::setCurrentTitle(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WebTabWidget::showStatusBarMessage(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void WebTabWidget::linkHovered(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void WebTabWidget::geometryChangeRequested(const QRect & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void WebTabWidget::menuBarVisibilityChangeRequested(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void WebTabWidget::statusBarVisibilityChangeRequested(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void WebTabWidget::toolBarVisibilityChangeRequested(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void WebTabWidget::printRequested(QWebFrame * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void WebTabWidget::download(QNetworkReply * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void WebTabWidget::loadProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void WebTabWidget::webActionEnabledChanged(QWebPage::WebAction _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void WebTabWidget::tabWidgetClose()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}

// SIGNAL 15
void WebTabWidget::titleChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_END_MOC_NAMESPACE
