/****************************************************************************
** Meta object code from reading C++ file 'dcapturar_de_video.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dcapturar_de_video.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dcapturar_de_video.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dcapturar_de_video_t {
    QByteArrayData data[10];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dcapturar_de_video_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dcapturar_de_video_t qt_meta_stringdata_dcapturar_de_video = {
    {
QT_MOC_LITERAL(0, 0, 18), // "dcapturar_de_video"
QT_MOC_LITERAL(1, 19, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 5), // "value"
QT_MOC_LITERAL(4, 59, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(5, 83, 4), // "arg1"
QT_MOC_LITERAL(6, 88, 30), // "on_dcapturar_de_video_finished"
QT_MOC_LITERAL(7, 119, 6), // "result"
QT_MOC_LITERAL(8, 126, 30), // "on_dcapturar_de_video_rejected"
QT_MOC_LITERAL(9, 157, 30) // "on_dcapturar_de_video_accepted"

    },
    "dcapturar_de_video\0on_horizontalSlider_valueChanged\0"
    "\0value\0on_spinBox_valueChanged\0arg1\0"
    "on_dcapturar_de_video_finished\0result\0"
    "on_dcapturar_de_video_rejected\0"
    "on_dcapturar_de_video_accepted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dcapturar_de_video[] = {

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
       6,    1,   45,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dcapturar_de_video::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dcapturar_de_video *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_dcapturar_de_video_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_dcapturar_de_video_rejected(); break;
        case 4: _t->on_dcapturar_de_video_accepted(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dcapturar_de_video::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_dcapturar_de_video.data,
    qt_meta_data_dcapturar_de_video,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dcapturar_de_video::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dcapturar_de_video::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dcapturar_de_video.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int dcapturar_de_video::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
