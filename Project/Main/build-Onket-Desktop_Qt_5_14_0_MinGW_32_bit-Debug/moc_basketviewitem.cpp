/****************************************************************************
** Meta object code from reading C++ file 'basketviewitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Onket/basketviewitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basketviewitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BasketViewItem_t {
    QByteArrayData data[9];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BasketViewItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BasketViewItem_t qt_meta_stringdata_BasketViewItem = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BasketViewItem"
QT_MOC_LITERAL(1, 15, 17), // "totalPriceChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "itemRemoved"
QT_MOC_LITERAL(4, 46, 4), // "Item"
QT_MOC_LITERAL(5, 51, 3), // "itm"
QT_MOC_LITERAL(6, 55, 27), // "on_item_number_valueChanged"
QT_MOC_LITERAL(7, 83, 4), // "arg1"
QT_MOC_LITERAL(8, 88, 17) // "on_remove_clicked"

    },
    "BasketViewItem\0totalPriceChanged\0\0"
    "itemRemoved\0Item\0itm\0on_item_number_valueChanged\0"
    "arg1\0on_remove_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BasketViewItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   38,    2, 0x08 /* Private */,
       8,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void BasketViewItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BasketViewItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->totalPriceChanged(); break;
        case 1: _t->itemRemoved((*reinterpret_cast< const Item(*)>(_a[1]))); break;
        case 2: _t->on_item_number_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_remove_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BasketViewItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BasketViewItem::totalPriceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BasketViewItem::*)(const Item & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BasketViewItem::itemRemoved)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BasketViewItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_BasketViewItem.data,
    qt_meta_data_BasketViewItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BasketViewItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasketViewItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BasketViewItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BasketViewItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void BasketViewItem::totalPriceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BasketViewItem::itemRemoved(const Item & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
