/****************************************************************************
** Meta object code from reading C++ file 'brillocontraste.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../brillocontraste.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'brillocontraste.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_brillocontraste_t {
    QByteArrayData data[13];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_brillocontraste_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_brillocontraste_t qt_meta_stringdata_brillocontraste = {
    {
QT_MOC_LITERAL(0, 0, 15), // "brillocontraste"
QT_MOC_LITERAL(1, 16, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(4, 61, 34), // "on_horizontalSlider_2_valueCh..."
QT_MOC_LITERAL(5, 96, 5), // "value"
QT_MOC_LITERAL(6, 102, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(7, 135, 25), // "on_spinBox_2_valueChanged"
QT_MOC_LITERAL(8, 161, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(9, 185, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(10, 210, 4), // "arg1"
QT_MOC_LITERAL(11, 215, 25), // "on_spinBox_3_valueChanged"
QT_MOC_LITERAL(12, 241, 34) // "on_horizontalSlider_3_valueCh..."

    },
    "brillocontraste\0on_buttonBox_accepted\0"
    "\0on_buttonBox_rejected\0"
    "on_horizontalSlider_2_valueChanged\0"
    "value\0on_horizontalSlider_valueChanged\0"
    "on_spinBox_2_valueChanged\0"
    "on_spinBox_valueChanged\0"
    "on_checkBox_stateChanged\0arg1\0"
    "on_spinBox_3_valueChanged\0"
    "on_horizontalSlider_3_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_brillocontraste[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    1,   61,    2, 0x08 /* Private */,
       6,    1,   64,    2, 0x08 /* Private */,
       7,    1,   67,    2, 0x08 /* Private */,
       8,    1,   70,    2, 0x08 /* Private */,
       9,    1,   73,    2, 0x08 /* Private */,
      11,    1,   76,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void brillocontraste::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<brillocontraste *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_buttonBox_accepted(); break;
        case 1: _t->on_buttonBox_rejected(); break;
        case 2: _t->on_horizontalSlider_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spinBox_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_spinBox_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_horizontalSlider_3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject brillocontraste::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_brillocontraste.data,
    qt_meta_data_brillocontraste,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *brillocontraste::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *brillocontraste::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_brillocontraste.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int brillocontraste::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
