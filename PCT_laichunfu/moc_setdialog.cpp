/****************************************************************************
** Meta object code from reading C++ file 'setdialog.h'
**
** Created: Wed Dec 23 21:30:27 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "set/setdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SetDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      44,   10,   10,   10, 0x08,
      76,   10,   10,   10, 0x08,
     102,   10,   10,   10, 0x08,
     129,   10,   10,   10, 0x08,
     152,   10,   10,   10, 0x08,
     181,   10,   10,   10, 0x08,
     210,   10,   10,   10, 0x08,
     238,   10,   10,   10, 0x08,
     265,   10,   10,   10, 0x08,
     290,   10,   10,   10, 0x08,
     318,   10,   10,   10, 0x08,
     344,   10,   10,   10, 0x08,
     370,   10,   10,   10, 0x08,
     400,   10,   10,   10, 0x08,
     430,   10,   10,   10, 0x08,
     457,   10,   10,   10, 0x08,
     486,   10,   10,   10, 0x08,
     503,   10,   10,   10, 0x08,
     518,   10,   10,   10, 0x08,
     531,   10,   10,   10, 0x08,
     561,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SetDialog[] = {
    "SetDialog\0\0on_UserCheckConfirmBtn_clicked()\0"
    "on_DatetimeConfirmBtn_clicked()\0"
    "on_IPConfirmBtn_clicked()\0"
    "on_cmosCameraBtn_clicked()\0"
    "on_cmosTCBtn_clicked()\0"
    "on_sysCheckSaveBtn_clicked()\0"
    "on_sysCheckTestBtn_clicked()\0"
    "on_sysCheckDelBtn_clicked()\0"
    "on_cmosReturnBtn_clicked()\0"
    "on_sysCheckBtn_clicked()\0"
    "on_sysCheckRetBtn_clicked()\0"
    "on_cmosCheckBtn_clicked()\0"
    "on_userCheckBtn_clicked()\0"
    "on_programUpdateBtn_clicked()\0"
    "on_DateTimeIPRetBtn_clicked()\0"
    "on_VersionRetBtn_clicked()\0"
    "on_UserCheckRetBtn_clicked()\0"
    "updateDatetime()\0testSysCheck()\0"
    "setDays(int)\0on_checkOrUpdateBtn_clicked()\0"
    "recordNo(QTableWidgetItem*)\0"
};

const QMetaObject SetDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SetDialog,
      qt_meta_data_SetDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SetDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SetDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SetDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SetDialog))
        return static_cast<void*>(const_cast< SetDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SetDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_UserCheckConfirmBtn_clicked(); break;
        case 1: on_DatetimeConfirmBtn_clicked(); break;
        case 2: on_IPConfirmBtn_clicked(); break;
        case 3: on_cmosCameraBtn_clicked(); break;
        case 4: on_cmosTCBtn_clicked(); break;
        case 5: on_sysCheckSaveBtn_clicked(); break;
        case 6: on_sysCheckTestBtn_clicked(); break;
        case 7: on_sysCheckDelBtn_clicked(); break;
        case 8: on_cmosReturnBtn_clicked(); break;
        case 9: on_sysCheckBtn_clicked(); break;
        case 10: on_sysCheckRetBtn_clicked(); break;
        case 11: on_cmosCheckBtn_clicked(); break;
        case 12: on_userCheckBtn_clicked(); break;
        case 13: on_programUpdateBtn_clicked(); break;
        case 14: on_DateTimeIPRetBtn_clicked(); break;
        case 15: on_VersionRetBtn_clicked(); break;
        case 16: on_UserCheckRetBtn_clicked(); break;
        case 17: updateDatetime(); break;
        case 18: testSysCheck(); break;
        case 19: setDays((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: on_checkOrUpdateBtn_clicked(); break;
        case 21: recordNo((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
