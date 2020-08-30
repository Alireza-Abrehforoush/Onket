/****************************************************************************
** Meta object code from reading C++ file 'commentlistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Onket/commentlistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commentlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommentListWidget_t {
    QByteArrayData data[11];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommentListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommentListWidget_t qt_meta_stringdata_CommentListWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CommentListWidget"
QT_MOC_LITERAL(1, 18, 15), // "commentsChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 6), // "update"
QT_MOC_LITERAL(4, 42, 10), // "changeUser"
QT_MOC_LITERAL(5, 53, 7), // "user_id"
QT_MOC_LITERAL(6, 61, 15), // "CommentFinished"
QT_MOC_LITERAL(7, 77, 12), // "commentAdded"
QT_MOC_LITERAL(8, 90, 29), // "action_sort_by_date_triggered"
QT_MOC_LITERAL(9, 120, 29), // "action_sort_by_like_triggered"
QT_MOC_LITERAL(10, 150, 29) // "action_sort_by_view_triggered"

    },
    "CommentListWidget\0commentsChanged\0\0"
    "update\0changeUser\0user_id\0CommentFinished\0"
    "commentAdded\0action_sort_by_date_triggered\0"
    "action_sort_by_like_triggered\0"
    "action_sort_by_view_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommentListWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x0a /* Public */,
       4,    1,   56,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CommentListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommentListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->commentsChanged(); break;
        case 1: _t->update(); break;
        case 2: _t->changeUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->CommentFinished(); break;
        case 4: _t->commentAdded(); break;
        case 5: _t->action_sort_by_date_triggered(); break;
        case 6: _t->action_sort_by_like_triggered(); break;
        case 7: _t->action_sort_by_view_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CommentListWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommentListWidget::commentsChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommentListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QScrollArea::staticMetaObject>(),
    qt_meta_stringdata_CommentListWidget.data,
    qt_meta_data_CommentListWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommentListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommentListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommentListWidget.stringdata0))
        return static_cast<void*>(this);
    return QScrollArea::qt_metacast(_clname);
}

int CommentListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CommentListWidget::commentsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
