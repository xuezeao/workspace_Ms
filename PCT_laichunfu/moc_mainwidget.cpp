/****************************************************************************
** Meta object code from reading C++ file 'mainwidget.h'
**
** Created: Wed Dec 23 21:30:24 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     143,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     202,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWidget[] = {
    "MainWidget\0\0updateDateTime()\0"
    "on_pushButtonExp_clicked()\0"
    "on_pushButtonManage_clicked()\0"
    "on_pushButtonSelect_clicked()\0"
    "on_pushButtonSet_clicked()\0"
    "on_pushButtonClose_clicked()\0"
    "on_pushButtonReboot_clicked()\0"
    "readCommandData()\0"
};

const QMetaObject MainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWidget,
      qt_meta_data_MainWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidget))
        return static_cast<void*>(const_cast< MainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateDateTime(); break;
        case 1: on_pushButtonExp_clicked(); break;
        case 2: on_pushButtonManage_clicked(); break;
        case 3: on_pushButtonSelect_clicked(); break;
        case 4: on_pushButtonSet_clicked(); break;
        case 5: on_pushButtonClose_clicked(); break;
        case 6: on_pushButtonReboot_clicked(); break;
        case 7: readCommandData(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
