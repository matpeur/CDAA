/****************************************************************************
** Meta object code from reading C++ file 'visucontactwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ContactClient/visucontactwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visucontactwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VisuContactWidget_t {
    QByteArrayData data[9];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VisuContactWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VisuContactWidget_t qt_meta_stringdata_VisuContactWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "VisuContactWidget"
QT_MOC_LITERAL(1, 18, 9), // "verouille"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "efface"
QT_MOC_LITERAL(4, 36, 8), // "Contact*"
QT_MOC_LITERAL(5, 45, 4), // "sauv"
QT_MOC_LITERAL(6, 50, 9), // "supprimer"
QT_MOC_LITERAL(7, 60, 10), // "sauvegarde"
QT_MOC_LITERAL(8, 71, 9) // "parcourir"

    },
    "VisuContactWidget\0verouille\0\0efface\0"
    "Contact*\0sauv\0supprimer\0sauvegarde\0"
    "parcourir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VisuContactWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,
       5,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   51,    2, 0x0a /* Public */,
       7,    0,   52,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VisuContactWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VisuContactWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->verouille((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->efface((*reinterpret_cast< Contact*(*)>(_a[1]))); break;
        case 2: _t->sauv(); break;
        case 3: _t->supprimer(); break;
        case 4: _t->sauvegarde(); break;
        case 5: _t->parcourir(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VisuContactWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VisuContactWidget::verouille)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VisuContactWidget::*)(Contact * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VisuContactWidget::efface)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VisuContactWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VisuContactWidget::sauv)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VisuContactWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_VisuContactWidget.data,
    qt_meta_data_VisuContactWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VisuContactWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VisuContactWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VisuContactWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VisuContactWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void VisuContactWidget::verouille(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VisuContactWidget::efface(Contact * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VisuContactWidget::sauv()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
