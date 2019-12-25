/*///////////////////////////////////////////////////////
square.c
주어진 인덱스의 제곱을 넘기는 간단한 클래스를 정의한다.

사용법은 다음과 같다.

import square

s = square.Square(10)

for k in s:
	print (k)

print (len(s))
print (s.middle())

__getitem__, __len__, middle 메쏘드를 정의한다.

이강성 2002.1, 2013.3
///////////////////////////////////////////////////////*/

#include <Python.h>
#include "structmember.h"


typedef struct {	/* 인스턴스 고유 공간 */
    PyObject_HEAD	/* 파이썬 헤더 : 레퍼런스 카운트와 형 정보를 가진다 */
    int limit;		/* 인스턴스 객체 멤버를 여기부터 선언한다 */
} Square;

static PyObject *	/* 객체 생성 */
Square_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    Square *self;

    self = (Square *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->limit = 0;
    }

    return (PyObject *)self;
}

static void
Square_dealloc(Square* self)
{
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static int			/* 객체 초기화 (생성자) */
Square_init(Square *self, PyObject *args, PyObject *kwds)
{
    static char *kwlist[] = {"limit", NULL};

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "i", kwlist,
                                     &self->limit))
        return -1;

    return 0;
}

static PyObject *
Square_middle(Square* self)
{
	return Py_BuildValue("i", self->limit / 2);
}

/*///////////////////////////////////////////////////////
              멤버들
///////////////////////////////////////////////////////*/

static PyMemberDef Square_members[] = {
    {"limit", T_INT, offsetof(Square, limit), 0, "limit"},
    {NULL}  /* 끝 */
};

/*///////////////////////////////////////////////////////
              메써드들
///////////////////////////////////////////////////////*/

static PyMethodDef Square_methods[] = {
    {"middle", (PyCFunction)Square_middle, METH_NOARGS, "half value of limit"},
    {NULL}  /* 끝 */
};

/*///////////////////////////////////////////////////////
              시퀀스 자료형 메써드들
///////////////////////////////////////////////////////*/

static int Square_length(Square* self)
{
    return self->limit;		/* 길이 정보는 정수를 그냥 넘기면 된다 */
}

static PyObject* Square_getitem(Square* self, int index)
{  
    if (index < 0 || index >= self->limit) { 
        PyErr_SetString(PyExc_IndexError, "index out-of-bounds"); 
        return NULL;
    } 
    return Py_BuildValue("i", index * index);
}

static PyObject* Square_slice(Square* self, int low, int high)
{
	PyErr_SetString(PyExc_RuntimeError, "Slicing is not implemented yet.");
	return NULL;
}

/*///////////////////////////////////////////////////////
              자료형의 종류에 따른 메써드들
///////////////////////////////////////////////////////*/

static PySequenceMethods Square_sequence = {
    (lenfunc) Square_length,	/* len(x) */
    (binaryfunc) 0,				/* x + y */
    (ssizeargfunc) 0,			/* x * n */
    (ssizeargfunc) Square_getitem,	/* x[i] */
    (void *)Square_slice,			/* x[i:j] */
    (ssizeobjargproc) 0,			/* x[i] = v */
    (void *)0,						/* x[i:j]=v */
    (objobjproc) 0,					/* in */

    (binaryfunc) 0,
    (ssizeargfunc) 0,
};

static PyTypeObject SquareType = {	/* 인스턴스 공유 공간 (클래스 공간) */
    PyVarObject_HEAD_INIT(NULL, 0)
    "square.Square",            /* tp_name */
    sizeof(Square),             /* tp_basicsize */
    0,							/* tp_itemsize */
    (destructor)Square_dealloc, /* tp_dealloc */
    0,							/* tp_print */
    0,							/* tp_getattr */
    0,							/* tp_setattr */
    0,							/* tp_reserved */
    0,							/* tp_repr */
    0,							/* 수치 자료형 메쏘드들 */
    &Square_sequence,			/* 시퀀스 자료형 메쏘드들 */
    0,							/* 매핑 자료형 메쏘드들 */
    0,							/* tp_hash */
    0,							/* tp_call */
    0,							/* tp_str */
    0,							/* tp_getattro */
    0,							/* tp_setattro */
    0,							/* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
        Py_TPFLAGS_BASETYPE,	/* tp_flags */
    "Square objects",           /* tp_doc */
    0,							/* tp_traverse */
    0,							/* tp_clear */
    0,							/* tp_richcompare */
    0,							/* tp_weaklistoffset */
    0,							/* tp_iter */
    0,							/* tp_iternext */
    Square_methods,             /* 사용자 정의 메쏘드 */
    Square_members,             /* 클래스 멤버 */
    0,							/* tp_getset */
    0,							/* tp_base */
    0,							/* tp_dict */
    0,							/* tp_descr_get */
    0,							/* tp_descr_set */
    0,							/* tp_dictoffset */
    (initproc)Square_init,      /* tp_init */
    0,							/* tp_alloc */
    Square_new,                 /* tp_new */
};

static PyModuleDef SqaureModule = {
    PyModuleDef_HEAD_INIT,
    "sqaure",
    "Example module that creates an extension type.",
    -1,
    NULL, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_square(void)
{
    PyObject* m;

    if (PyType_Ready(&SquareType) < 0)	/* type 초기화 */
        return NULL;

    m = PyModule_Create(&SqaureModule);	/* 모듈 초기화 */
    if (m == NULL)
        return NULL;

    Py_INCREF(&SquareType);
    PyModule_AddObject(m, "Square", (PyObject *)&SquareType);
    return m;
}
