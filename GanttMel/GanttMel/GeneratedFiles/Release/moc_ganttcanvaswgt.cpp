/****************************************************************************
** Meta object code from reading C++ file 'ganttcanvaswgt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ganttcanvaswgt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ganttcanvaswgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GanttCanvasWgt_t {
    QByteArrayData data[13];
    char stringdata[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GanttCanvasWgt_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GanttCanvasWgt_t qt_meta_stringdata_GanttCanvasWgt = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 16),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 8),
QT_MOC_LITERAL(4, 42, 4),
QT_MOC_LITERAL(5, 47, 10),
QT_MOC_LITERAL(6, 58, 4),
QT_MOC_LITERAL(7, 63, 16),
QT_MOC_LITERAL(8, 80, 19),
QT_MOC_LITERAL(9, 100, 18),
QT_MOC_LITERAL(10, 119, 23),
QT_MOC_LITERAL(11, 143, 12),
QT_MOC_LITERAL(12, 156, 7)
    },
    "GanttCanvasWgt\0slot_addTaskInfo\0\0"
    "TaskInfo\0info\0NotifyType\0type\0"
    "slot_delTaskInfo\0slot_updateTaskInfo\0"
    "slot_clearTaskInfo\0slot_updatePaintSetting\0"
    "PaintSetting\0setting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GanttCanvasWgt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x08 /* Private */,
       7,    2,   44,    2, 0x08 /* Private */,
       8,    2,   49,    2, 0x08 /* Private */,
       9,    2,   54,    2, 0x08 /* Private */,
      10,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void GanttCanvasWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GanttCanvasWgt *_t = static_cast<GanttCanvasWgt *>(_o);
        switch (_id) {
        case 0: _t->slot_addTaskInfo((*reinterpret_cast< TaskInfo(*)>(_a[1])),(*reinterpret_cast< NotifyType(*)>(_a[2]))); break;
        case 1: _t->slot_delTaskInfo((*reinterpret_cast< TaskInfo(*)>(_a[1])),(*reinterpret_cast< NotifyType(*)>(_a[2]))); break;
        case 2: _t->slot_updateTaskInfo((*reinterpret_cast< TaskInfo(*)>(_a[1])),(*reinterpret_cast< NotifyType(*)>(_a[2]))); break;
        case 3: _t->slot_clearTaskInfo((*reinterpret_cast< TaskInfo(*)>(_a[1])),(*reinterpret_cast< NotifyType(*)>(_a[2]))); break;
        case 4: _t->slot_updatePaintSetting((*reinterpret_cast< PaintSetting(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TaskInfo >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TaskInfo >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TaskInfo >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TaskInfo >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PaintSetting >(); break;
            }
            break;
        }
    }
}

const QMetaObject GanttCanvasWgt::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GanttCanvasWgt.data,
      qt_meta_data_GanttCanvasWgt,  qt_static_metacall, 0, 0}
};


const QMetaObject *GanttCanvasWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GanttCanvasWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GanttCanvasWgt.stringdata))
        return static_cast<void*>(const_cast< GanttCanvasWgt*>(this));
    return QWidget::qt_metacast(_clname);
}

int GanttCanvasWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
