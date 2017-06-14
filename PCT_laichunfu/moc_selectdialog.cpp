/****************************************************************************
** Meta object code from reading C++ file 'selectdialog.h'
**
** Created: Wed Dec 23 21:30:25 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "select/selectdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SelectDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      46,   13,   13,   13, 0x08,
      75,   13,   13,   13, 0x08,
      92,   13,   13,   13, 0x08,
     122,   13,   13,   13, 0x08,
     151,   13,   13,   13, 0x08,
     181,   13,   13,   13, 0x08,
     211,   13,   13,   13, 0x08,
     243,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SelectDialog[] = {
    "SelectDialog\0\0on_SelectPushButton_2_clicked()\0"
    "on_SelectReturnBtn_clicked()\0"
    "updateDatetime()\0on_DeletePushButton_clicked()\0"
    "on_PrintPushButton_clicked()\0"
    "on_SelectPushButton_clicked()\0"
    "on_UpPagePushButton_clicked()\0"
    "on_DownPagePushButton_clicked()\0"
    "showImage(QTableWidgetItem*)\0"
};

const QMetaObject SelectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SelectDialog,
      qt_meta_data_SelectDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SelectDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SelectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SelectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SelectDialog))
        return static_cast<void*>(const_cast< SelectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SelectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_SelectPushButton_2_clicked(); break;
        case 1: on_SelectReturnBtn_clicked(); break;
        case 2: updateDatetime(); break;
        case 3: on_DeletePushButton_clicked(); break;
        case 4: on_PrintPushButton_clicked(); break;
        case 5: on_SelectPushButton_clicked(); break;
        case 6: on_UpPagePushButton_clicked(); break;
        case 7: on_DownPagePushButton_clicked(); break;
        case 8: showImage((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
