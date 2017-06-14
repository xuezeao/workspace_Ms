/****************************************************************************
** Meta object code from reading C++ file 'managedialog.h'
**
** Created: Wed Dec 23 21:30:26 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "manage/managedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManageDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      43,   13,   13,   13, 0x08,
      60,   13,   13,   13, 0x08,
      90,   13,   13,   13, 0x08,
     120,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ManageDialog[] = {
    "ManageDialog\0\0on_manageReturnBtn_clicked()\0"
    "updateDatetime()\0on_DeletePushButton_clicked()\0"
    "on_ImportPushButton_clicked()\0"
    "recordNo(QTableWidgetItem*)\0"
};

const QMetaObject ManageDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ManageDialog,
      qt_meta_data_ManageDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManageDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManageDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManageDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManageDialog))
        return static_cast<void*>(const_cast< ManageDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ManageDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_manageReturnBtn_clicked(); break;
        case 1: updateDatetime(); break;
        case 2: on_DeletePushButton_clicked(); break;
        case 3: on_ImportPushButton_clicked(); break;
        case 4: recordNo((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
