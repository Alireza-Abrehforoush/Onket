/****************************************************************************
** Meta object code from reading C++ file 'goodpreviewscrollarea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Onket/goodpreviewscrollarea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'goodpreviewscrollarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GoodPreviewScrollArea_t {
    QByteArrayData data[11];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GoodPreviewScrollArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GoodPreviewScrollArea_t qt_meta_stringdata_GoodPreviewScrollArea = {
    {
QT_MOC_LITERAL(0, 0, 21), // "GoodPreviewScrollArea"
QT_MOC_LITERAL(1, 22, 20), // "onGoodPreviewClicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 7), // "good_id"
QT_MOC_LITERAL(4, 52, 17), // "showCompareButton"
QT_MOC_LITERAL(5, 70, 17), // "hideCompareButton"
QT_MOC_LITERAL(6, 88, 23), // "on_good_preview_clicked"
QT_MOC_LITERAL(7, 112, 19), // "show_compare_button"
QT_MOC_LITERAL(8, 132, 19), // "hide_compare_button"
QT_MOC_LITERAL(9, 152, 6), // "update"
QT_MOC_LITERAL(10, 159, 5) // "clear"

    },
    "GoodPreviewScrollArea\0onGoodPreviewClicked\0"
    "\0good_id\0showCompareButton\0hideCompareButton\0"
    "on_good_preview_clicked\0show_compare_button\0"
    "hide_compare_button\0update\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GoodPreviewScrollArea[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   59,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GoodPreviewScrollArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GoodPreviewScrollArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onGoodPreviewClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->showCompareButton(); break;
        case 2: _t->hideCompareButton(); break;
        case 3: _t->on_good_preview_clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->show_compare_button(); break;
        case 5: _t->hide_compare_button(); break;
        case 6: _t->update(); break;
        case 7: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GoodPreviewScrollArea::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GoodPreviewScrollArea::onGoodPreviewClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GoodPreviewScrollArea::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GoodPreviewScrollArea::showCompareButton)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GoodPreviewScrollArea::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GoodPreviewScrollArea::hideCompareButton)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GoodPreviewScrollArea::staticMetaObject = { {
    QMetaObject::SuperData::link<QScrollArea::staticMetaObject>(),
    qt_meta_stringdata_GoodPreviewScrollArea.data,
    qt_meta_data_GoodPreviewScrollArea,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GoodPreviewScrollArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GoodPreviewScrollArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GoodPreviewScrollArea.stringdata0))
        return static_cast<void*>(this);
    return QScrollArea::qt_metacast(_clname);
}

int GoodPreviewScrollArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
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
void GoodPreviewScrollArea::onGoodPreviewClicked(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GoodPreviewScrollArea::showCompareButton()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GoodPreviewScrollArea::hideCompareButton()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
