/****************************************************************************
** Meta object code from reading C++ file 'gameView.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SpleendorDuel_Interface/gameView.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSgameViewENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSgameViewENDCLASS = QtMocHelpers::stringData(
    "gameView",
    "checkCoinsSelection",
    "",
    "fillCoinsBoard",
    "usePrivilege",
    "checkBuyCard",
    "cardReservationCoinBoardPart"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSgameViewENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[9];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[13];
    char stringdata5[13];
    char stringdata6[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSgameViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSgameViewENDCLASS_t qt_meta_stringdata_CLASSgameViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "gameView"
        QT_MOC_LITERAL(9, 19),  // "checkCoinsSelection"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 14),  // "fillCoinsBoard"
        QT_MOC_LITERAL(45, 12),  // "usePrivilege"
        QT_MOC_LITERAL(58, 12),  // "checkBuyCard"
        QT_MOC_LITERAL(71, 28)   // "cardReservationCoinBoardPart"
    },
    "gameView",
    "checkCoinsSelection",
    "",
    "fillCoinsBoard",
    "usePrivilege",
    "checkBuyCard",
    "cardReservationCoinBoardPart"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSgameViewENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

Q_CONSTINIT const QMetaObject gameView::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSgameViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSgameViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSgameViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<gameView, std::true_type>,
        // method 'checkCoinsSelection'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'fillCoinsBoard'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'usePrivilege'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'checkBuyCard'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'cardReservationCoinBoardPart'
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void gameView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<gameView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->checkCoinsSelection();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->fillCoinsBoard();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->usePrivilege();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->checkBuyCard();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->cardReservationCoinBoardPart();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *gameView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSgameViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int gameView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
