/****************************************************************************
** Meta object code from reading C++ file 'expdialog.h'
**
** Created: Wed Dec 23 21:30:25 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "exp/expdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'expdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ExpDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      36,   10,   10,   10, 0x08,
      65,   10,   10,   10, 0x08,
      91,   10,   10,   10, 0x08,
     108,   10,   10,   10, 0x08,
     125,  119,   10,   10, 0x08,
     147,   10,   10,   10, 0x08,
     176,   10,   10,   10, 0x08,
     207,   10,   10,   10, 0x08,
     236,   10,   10,   10, 0x08,
     264,   10,   10,   10, 0x08,
     296,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ExpDialog[] = {
    "ExpDialog\0\0on_selectOkBtn_clicked()\0"
    "on_selectReturnBtn_clicked()\0"
    "on_expReturnBtn_clicked()\0updateDatetime()\0"
    "testCard()\0value\0getCheckBoxValue(int)\0"
    "on_CheckPushButton_clicked()\0"
    "on_MeasurePushButton_clicked()\0"
    "on_PrintPushButton_clicked()\0"
    "recordNo(QTableWidgetItem*)\0"
    "selectRecord(QTableWidgetItem*)\0"
    "getPaientId()\0"
};

const QMetaObject ExpDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ExpDialog,
      qt_meta_data_ExpDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ExpDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ExpDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ExpDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ExpDialog))
        return static_cast<void*>(const_cast< ExpDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ExpDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_selectOkBtn_clicked(); break;
        case 1: on_selectReturnBtn_clicked(); break;
        case 2: on_expReturnBtn_clicked(); break;
        case 3: updateDatetime(); break;
        case 4: testCard(); break;
        case 5: getCheckBoxValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_CheckPushButton_clicked(); break;
        case 7: on_MeasurePushButton_clicked(); break;
        case 8: on_PrintPushButton_clicked(); break;
        case 9: recordNo((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 10: selectRecord((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 11: getPaientId(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
