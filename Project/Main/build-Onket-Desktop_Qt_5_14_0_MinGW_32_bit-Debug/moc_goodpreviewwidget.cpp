/****************************************************************************
** Meta object code from reading C++ file 'goodpreviewwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Onket/goodpreviewwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'goodpreviewwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GoodPreviewWidget_t {
    QByteArrayData data[7];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GoodPreviewWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GoodPreviewWidget_t qt_meta_stringdata_GoodPreviewWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "GoodPreviewWidget"
QT_MOC_LITERAL(1, 18, 23), // "on_good_preview_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 7), // "good_id"
QT_MOC_LITERAL(4, 51, 17), // "showCompareButton"
QT_MOC_LITERAL(5, 69, 17), // "hideCompareButton"
QT_MOC_LITERAL(6, 87, 32) // "on_checkBox_compare_stateChanged"

    },
    "GoodPreviewWidget\0on_good_preview_clicked\0"
    "\0good_id\0showCompareButton\0hideCompareButton\0"
    "on_checkBox_compare_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GoodPreviewWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,
       5,    0,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void GoodPreviewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GoodPreviewWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_good_preview_clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->showCompareButton(); break;
        case 2: _t->hideCompareButton(); break;
        case 3: _t->on_checkBox_compare_stateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GoodPreviewWidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GoodPreviewWidget::on_good_preview_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GoodPreviewWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GoodPreviewWidget::showCompareButton)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GoodPreviewWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GoodPreviewWidget::hideCompareButton)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GoodPreviewWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GoodPreviewWidget.data,
    qt_meta_data_GoodPreviewWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GoodPreviewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GoodPreviewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GoodPreviewWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GoodPreviewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void GoodPreviewWidget::on_good_preview_clicked(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GoodPreviewWidget::showCompareButton()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GoodPreviewWidget::hideCompareButton()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
