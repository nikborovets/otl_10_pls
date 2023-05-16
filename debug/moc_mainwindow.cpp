/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[16];
    char stringdata5[25];
    char stringdata6[27];
    char stringdata7[24];
    char stringdata8[23];
    char stringdata9[22];
    char stringdata10[12];
    char stringdata11[21];
    char stringdata12[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "paint_filters"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 5),  // "value"
        QT_MOC_LITERAL(32, 15),  // "settings_filter"
        QT_MOC_LITERAL(48, 24),  // "on_action_open_triggered"
        QT_MOC_LITERAL(73, 26),  // "on_action_remove_triggered"
        QT_MOC_LITERAL(100, 23),  // "on_save_filters_clicked"
        QT_MOC_LITERAL(124, 22),  // "on_push_button_clicked"
        QT_MOC_LITERAL(147, 21),  // "on_set_button_clicked"
        QT_MOC_LITERAL(169, 11),  // "ReDrawLines"
        QT_MOC_LITERAL(181, 20),  // "on_calculate_clicked"
        QT_MOC_LITERAL(202, 13)   // "slotReadyRead"
    },
    "MainWindow",
    "paint_filters",
    "",
    "value",
    "settings_filter",
    "on_action_open_triggered",
    "on_action_remove_triggered",
    "on_save_filters_clicked",
    "on_push_button_clicked",
    "on_set_button_clicked",
    "ReDrawLines",
    "on_calculate_clicked",
    "slotReadyRead"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x08,    1 /* Private */,
       4,    0,   77,    2, 0x08,    3 /* Private */,
       5,    0,   78,    2, 0x08,    4 /* Private */,
       6,    0,   79,    2, 0x08,    5 /* Private */,
       7,    0,   80,    2, 0x08,    6 /* Private */,
       8,    0,   81,    2, 0x08,    7 /* Private */,
       9,    0,   82,    2, 0x08,    8 /* Private */,
      10,    0,   83,    2, 0x08,    9 /* Private */,
      11,    0,   84,    2, 0x08,   10 /* Private */,
      12,    0,   85,    2, 0x0a,   11 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'paint_filters'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'settings_filter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_open_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_remove_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_save_filters_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_push_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_set_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ReDrawLines'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_calculate_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->paint_filters((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->settings_filter(); break;
        case 2: _t->on_action_open_triggered(); break;
        case 3: _t->on_action_remove_triggered(); break;
        case 4: _t->on_save_filters_clicked(); break;
        case 5: _t->on_push_button_clicked(); break;
        case 6: _t->on_set_button_clicked(); break;
        case 7: _t->ReDrawLines(); break;
        case 8: _t->on_calculate_clicked(); break;
        case 9: _t->slotReadyRead(); break;
        default: ;
        }
    }
}

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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
