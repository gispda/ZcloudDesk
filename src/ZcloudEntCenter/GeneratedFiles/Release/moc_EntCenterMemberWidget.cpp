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
    QByteArrayData data[14];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EntCenterMemberWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EntCenterMemberWidget_t qt_meta_stringdata_EntCenterMemberWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "EntCenterMemberWidget"
QT_MOC_LITERAL(1, 22, 21), // "sigEditMemberSucessed"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 11), // "onAddMember"
QT_MOC_LITERAL(4, 57, 17), // "onAddMemberSucess"
QT_MOC_LITERAL(5, 75, 18), // "onFreshFinanMember"
QT_MOC_LITERAL(6, 94, 14), // "onRemoveMember"
QT_MOC_LITERAL(7, 109, 9), // "strUserId"
QT_MOC_LITERAL(8, 119, 14), // "onModifyMember"
QT_MOC_LITERAL(9, 134, 11), // "strTrueName"
QT_MOC_LITERAL(10, 146, 6), // "strJob"
QT_MOC_LITERAL(11, 153, 20), // "onModifyMemberSucess"
QT_MOC_LITERAL(12, 174, 12), // "strCurUserId"
QT_MOC_LITERAL(13, 187, 10) // "onHandOver"

    },
    "EntCenterMemberWidget\0sigEditMemberSucessed\0"
    "\0onAddMember\0onAddMemberSucess\0"
    "onFreshFinanMember\0onRemoveMember\0"
    "strUserId\0onModifyMember\0strTrueName\0"
    "strJob\0onModifyMemberSucess\0strCurUserId\0"
    "onHandOver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EntCenterMemberWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   59,    2, 0x08 /* Private */,
       4,    0,   60,    2, 0x08 /* Private */,
       5,    0,   61,    2, 0x08 /* Private */,
       6,    1,   62,    2, 0x08 /* Private */,
       8,    3,   65,    2, 0x08 /* Private */,
      11,    3,   72,    2, 0x08 /* Private */,
      13,    1,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   12,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void EntCenterMemberWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EntCenterMemberWidget *_t = static_cast<EntCenterMemberWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigEditMemberSucessed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->onAddMember(); break;
        case 2: _t->onAddMemberSucess(); break;
        case 3: _t->onFreshFinanMember(); break;
        case 4: _t->onRemoveMember((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->onModifyMember((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->onModifyMemberSucess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->onHandOver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EntCenterMemberWidget::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntCenterMemberWidget::sigEditMemberSucessed)) {
                *result = 0;
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
void EntCenterMemberWidget::sigEditMemberSucessed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
