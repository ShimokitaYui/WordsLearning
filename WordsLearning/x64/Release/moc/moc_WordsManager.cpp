/****************************************************************************
** Meta object code from reading C++ file 'WordsManager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../WordsManager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WordsManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
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
struct qt_meta_stringdata_CLASSWordsManagerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSWordsManagerENDCLASS = QtMocHelpers::stringData(
    "WordsManager",
    "getOldWord",
    "",
    "getNewWord",
    "errorPath",
    "setNewWord",
    "setPath",
    "setYes",
    "setNo",
    "setYes_2",
    "setNo_2",
    "setFileName",
    "getFileName",
    "getPath",
    "readFile",
    "init"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWordsManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,
       3,    0,  101,    2, 0x06,    3 /* Public */,
       4,    0,  102,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,  103,    2, 0x0a,    5 /* Public */,
       6,    1,  106,    2, 0x0a,    7 /* Public */,
       7,    0,  109,    2, 0x0a,    9 /* Public */,
       8,    0,  110,    2, 0x0a,   10 /* Public */,
       9,    0,  111,    2, 0x0a,   11 /* Public */,
      10,    0,  112,    2, 0x0a,   12 /* Public */,
      11,    1,  113,    2, 0x0a,   13 /* Public */,
      12,    0,  116,    2, 0x0a,   15 /* Public */,
      13,    0,  117,    2, 0x0a,   16 /* Public */,
      14,    1,  118,    2, 0x0a,   17 /* Public */,
      15,    0,  121,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject WordsManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSWordsManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWordsManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWordsManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WordsManager, std::true_type>,
        // method 'getOldWord'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getNewWord'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'errorPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setNewWord'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setYes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setNo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setYes_2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setNo_2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setFileName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getFileName'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getPath'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'readFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'init'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void WordsManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WordsManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getOldWord((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->getNewWord(); break;
        case 2: _t->errorPath(); break;
        case 3: _t->setNewWord((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->setPath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->setYes(); break;
        case 6: _t->setNo(); break;
        case 7: _t->setYes_2(); break;
        case 8: _t->setNo_2(); break;
        case 9: _t->setFileName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: { QString _r = _t->getFileName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->getPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->readFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->init(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WordsManager::*)(QString );
            if (_t _q_method = &WordsManager::getOldWord; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WordsManager::*)();
            if (_t _q_method = &WordsManager::getNewWord; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WordsManager::*)();
            if (_t _q_method = &WordsManager::errorPath; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *WordsManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WordsManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWordsManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WordsManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void WordsManager::getOldWord(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WordsManager::getNewWord()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WordsManager::errorPath()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
