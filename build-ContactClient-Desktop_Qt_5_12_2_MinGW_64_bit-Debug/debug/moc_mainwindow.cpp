/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ContactClient/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 34), // "on_actionNouveau_Contact_trig..."
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 39), // "on_actionNouvelle_Interaction..."
QT_MOC_LITERAL(4, 87, 9), // "selection"
QT_MOC_LITERAL(5, 97, 3), // "tri"
QT_MOC_LITERAL(6, 101, 20), // "selectionTypeContact"
QT_MOC_LITERAL(7, 122, 24), // "selectionTypeInteraction"
QT_MOC_LITERAL(8, 147, 17), // "selectionTypeTodo"
QT_MOC_LITERAL(9, 165, 7), // "affiche"
QT_MOC_LITERAL(10, 173, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 185, 13), // "effaceContact"
QT_MOC_LITERAL(12, 199, 8), // "Contact*"
QT_MOC_LITERAL(13, 208, 14), // "afficheTabTodo"
QT_MOC_LITERAL(14, 223, 5), // "toDo*"
QT_MOC_LITERAL(15, 229, 10) // "sauvegarde"

    },
    "MainWindow\0on_actionNouveau_Contact_triggered\0"
    "\0on_actionNouvelle_Interaction_triggered\0"
    "selection\0tri\0selectionTypeContact\0"
    "selectionTypeInteraction\0selectionTypeTodo\0"
    "affiche\0QModelIndex\0effaceContact\0"
    "Contact*\0afficheTabTodo\0toDo*\0sauvegarde"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    1,   71,    2, 0x08 /* Private */,
       5,    1,   74,    2, 0x08 /* Private */,
       6,    0,   77,    2, 0x08 /* Private */,
       7,    0,   78,    2, 0x08 /* Private */,
       8,    0,   79,    2, 0x08 /* Private */,
       9,    1,   80,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      13,    1,   86,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionNouveau_Contact_triggered(); break;
        case 1: _t->on_actionNouvelle_Interaction_triggered(); break;
        case 2: _t->selection((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->tri((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->selectionTypeContact(); break;
        case 5: _t->selectionTypeInteraction(); break;
        case 6: _t->selectionTypeTodo(); break;
        case 7: _t->affiche((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 8: _t->effaceContact((*reinterpret_cast< Contact*(*)>(_a[1]))); break;
        case 9: _t->afficheTabTodo((*reinterpret_cast< toDo*(*)>(_a[1]))); break;
        case 10: _t->sauvegarde(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
