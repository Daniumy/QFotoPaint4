/****************************************************************************
** Meta object code from reading C++ file 'dcurva_tunal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dcurva_tunal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dcurva_tunal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dcurva_tunal_t {
    QByteArrayData data[9];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dcurva_tunal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dcurva_tunal_t qt_meta_stringdata_dcurva_tunal = {
    {
QT_MOC_LITERAL(0, 0, 12), // "dcurva_tunal"
QT_MOC_LITERAL(1, 13, 24), // "on_dcurva_tunal_accepted"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 24), // "on_dcurva_tunal_rejected"
QT_MOC_LITERAL(4, 64, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 86, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 110, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 134, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(8, 159, 4) // "arg1"

    },
    "dcurva_tunal\0on_dcurva_tunal_accepted\0"
    "\0on_dcurva_tunal_rejected\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0"
    "on_checkBox_stateChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dcurva_tunal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void dcurva_tunal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dcurva_tunal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_dcurva_tunal_accepted(); break;
        case 1: _t->on_dcurva_tunal_rejected(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dcurva_tunal::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_dcurva_tunal.data,
    qt_meta_data_dcurva_tunal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dcurva_tunal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dcurva_tunal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dcurva_tunal.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int dcurva_tunal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
