/****************************************************************************
** Meta object code from reading C++ file 'dmat_sat_lum.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dmat_sat_lum.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dmat_sat_lum.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dmat_sat_lum_t {
    QByteArrayData data[8];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dmat_sat_lum_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dmat_sat_lum_t qt_meta_stringdata_dmat_sat_lum = {
    {
QT_MOC_LITERAL(0, 0, 12), // "dmat_sat_lum"
QT_MOC_LITERAL(1, 13, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 5), // "value"
QT_MOC_LITERAL(4, 53, 34), // "on_horizontalSlider_2_valueCh..."
QT_MOC_LITERAL(5, 88, 20), // "on_dial_valueChanged"
QT_MOC_LITERAL(6, 109, 24), // "on_dmat_sat_lum_accepted"
QT_MOC_LITERAL(7, 134, 24) // "on_dmat_sat_lum_rejected"

    },
    "dmat_sat_lum\0on_horizontalSlider_valueChanged\0"
    "\0value\0on_horizontalSlider_2_valueChanged\0"
    "on_dial_valueChanged\0on_dmat_sat_lum_accepted\0"
    "on_dmat_sat_lum_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dmat_sat_lum[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    1,   45,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dmat_sat_lum::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dmat_sat_lum *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_horizontalSlider_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_dmat_sat_lum_accepted(); break;
        case 4: _t->on_dmat_sat_lum_rejected(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dmat_sat_lum::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_dmat_sat_lum.data,
    qt_meta_data_dmat_sat_lum,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dmat_sat_lum::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dmat_sat_lum::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dmat_sat_lum.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int dmat_sat_lum::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
