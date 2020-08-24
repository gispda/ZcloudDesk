/****************************************************************************
** Meta object code from reading C++ file 'EntCenterMemberWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EntCenterMemberWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EntCenterMemberWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EntCenterMemberWidget_t {
    QByteArrayData data[15];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EntCenterMemberWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EntCenterMemberWidget_t qt_meta_stringdata_EntCenterMemberWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "EntCenterMemberWidget"
QT_MOC_LITERAL(1, 22, 12), // "sigNeedLogin"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "sigEditMemberSucessed"
QT_MOC_LITERAL(4, 58, 11), // "onAddMember"
QT_MOC_LITERAL(5, 70, 17), // "onAddMemberSucess"
QT_MOC_LITERAL(6, 88, 18), // "onFreshFinanMember"
QT_MOC_LITERAL(7, 107, 14), // "onRemoveMember"
QT_MOC_LITERAL(8, 122, 9), // "strUserId"
QT_MOC_LITERAL(9, 132, 14), // "onModifyMember"
QT_MOC_LITERAL(10, 147, 11), // "strTrueName"
QT_MOC_LITERAL(11, 159, 6), // "strJob"
QT_MOC_LITERAL(12, 166, 20), // "onModifyMemberSucess"
QT_MOC_LITERAL(13, 187, 12), // "strCurUserId"
QT_MOC_LITERAL(14, 200, 10) // "onHandOver"

    },
    "EntCenterMemberWidget\0sigNeedLogin\0\0"
    "sigEditMemberSucessed\0onAddMember\0"
    "onAddMemberSucess\0onFreshFinanMember\0"
    "onRemoveMember\0strUserId\0onModifyMember\0"
    "strTrueName\0strJob\0onModifyMemberSucess\0"
    "strCurUserId\0onHandOver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EntCenterMemberWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    2,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   65,    2, 0x08 /* Private */,
       5,    0,   66,    2, 0x08 /* Private */,
       6,    0,   67,    2, 0x08 /* Private */,
       7,    1,   68,    2, 0x08 /* Private */,
       9,    3,   71,    2, 0x08 /* Private */,
      12,    3,   78,    2, 0x08 /* Private */,
      14,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   13,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void EntCenterMemberWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EntCenterMemberWidget *_t = static_cast<EntCenterMemberWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigNeedLogin(); break;
        case 1: _t->sigEditMemberSucessed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->onAddMember(); break;
        case 3: _t->onAddMemberSucess(); break;
        case 4: _t->onFreshFinanMember(); break;
        case 5: _t->onRemoveMember((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->onModifyMember((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->onModifyMemberSucess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: _t->onHandOver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EntCenterMemberWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntCenterMemberWidget::sigNeedLogin)) {
                *result = 0;
            }
        }
        {
            typedef void (EntCenterMemberWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntCenterMemberWidget::sigEditMemberSucessed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject EntCenterMemberWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EntCenterMemberWidget.data,
      qt_meta_data_EntCenterMemberWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EntCenterMemberWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EntCenterMemberWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EntCenterMemberWidget.stringdata0))
        return static_cast<void*>(const_cast< EntCenterMemberWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int EntCenterMemberWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void EntCenterMemberWidget::sigNeedLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void EntCenterMemberWidget::sigEditMemberSucessed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
