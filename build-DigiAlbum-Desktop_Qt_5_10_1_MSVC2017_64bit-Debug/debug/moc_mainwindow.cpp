/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DigiAlbum/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "on_pageBackButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 29), // "on_pageForwardsButton_clicked"
QT_MOC_LITERAL(4, 68, 26), // "on_sheetViewButton_clicked"
QT_MOC_LITERAL(5, 95, 11), // "viewClicked"
QT_MOC_LITERAL(6, 107, 14), // "realitiveIndex"
QT_MOC_LITERAL(7, 122, 34), // "on_currentImageBox_editingFin..."
QT_MOC_LITERAL(8, 157, 31), // "on_presentCheckbox_stateChanged"
QT_MOC_LITERAL(9, 189, 4), // "arg1"
QT_MOC_LITERAL(10, 194, 24), // "on_delayBox_valueChanged"
QT_MOC_LITERAL(11, 219, 23), // "on_addTagButton_clicked"
QT_MOC_LITERAL(12, 243, 26), // "on_removeTagButton_clicked"
QT_MOC_LITERAL(13, 270, 23), // "on_searchButton_clicked"
QT_MOC_LITERAL(14, 294, 25), // "on_addPhotoButton_clicked"
QT_MOC_LITERAL(15, 320, 23), // "on_returnButton_clicked"
QT_MOC_LITERAL(16, 344, 23) // "on_importButton_clicked"

    },
    "MainWindow\0on_pageBackButton_clicked\0"
    "\0on_pageForwardsButton_clicked\0"
    "on_sheetViewButton_clicked\0viewClicked\0"
    "realitiveIndex\0on_currentImageBox_editingFinished\0"
    "on_presentCheckbox_stateChanged\0arg1\0"
    "on_delayBox_valueChanged\0"
    "on_addTagButton_clicked\0"
    "on_removeTagButton_clicked\0"
    "on_searchButton_clicked\0"
    "on_addPhotoButton_clicked\0"
    "on_returnButton_clicked\0on_importButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
      10,    1,   89,    2, 0x08 /* Private */,
      11,    0,   92,    2, 0x08 /* Private */,
      12,    0,   93,    2, 0x08 /* Private */,
      13,    0,   94,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pageBackButton_clicked(); break;
        case 1: _t->on_pageForwardsButton_clicked(); break;
        case 2: _t->on_sheetViewButton_clicked(); break;
        case 3: _t->viewClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_currentImageBox_editingFinished(); break;
        case 5: _t->on_presentCheckbox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_delayBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_addTagButton_clicked(); break;
        case 8: _t->on_removeTagButton_clicked(); break;
        case 9: _t->on_searchButton_clicked(); break;
        case 10: _t->on_addPhotoButton_clicked(); break;
        case 11: _t->on_returnButton_clicked(); break;
        case 12: _t->on_importButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
