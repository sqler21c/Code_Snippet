#include "Python.h"

static PyObject *ErrorObject;

static char add_doc[] = "adds two inters";
static PyObject* sample_add(PyObject *self, PyObject *args)
{
    int a, b, r;
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
	r = a + b;
    return Py_BuildValue("i", r);
}

static char area_doc[] = "area(width, height)";
static PyObject* sample_area(PyObject *self, PyObject *args, PyObject * kwdict)
{
	static char *kwlist[] = {"width", "height", NULL};
    int width, height, r;
    if (!PyArg_ParseTupleAndKeywords(args, kwdict, "ii", kwlist, 
                                     &width, &height))
        return NULL;
	r = width * height;
    return Py_BuildValue("i", r);
}

static PyObject* sample_dictest(PyObject *self, PyObject *args)
{
	PyObject* dic;
	int len;

	if (!PyArg_ParseTuple(args, "O", &dic)) /* 파이썬 객체를 dic로 전달받는다 */
		return NULL;
	if (!PyDict_Check(dic)) { /* 사전인지 검사 */
		/* 사전이 아니면 예외 발생. 일단 건너뛰자 */
		PyErr_SetString(ErrorObject, "my exception");
		return NULL;
	}
	len = PyDict_Size(dic); /* 사전의 길이를 얻는다. */
	printf("Yes, this is a dictionary of len %d\n", len); /* 메시지 출력 */

	Py_INCREF(Py_None); /* 파이썬 None 객체 리턴 */
	return Py_None;
}

//////////////////////////////////////////////////////////////
static struct PyMethodDef _sample_methods[] = {
 {"add",     sample_add,    METH_VARARGS, add_doc},
 {"area",    sample_area,   METH_VARARGS|METH_KEYWORDS, area_doc},
 {"dictest", sample_dictest, METH_VARARGS},
 {NULL}		/* end of module method table */
};

static struct PyModuleDef _sample_module = {
   PyModuleDef_HEAD_INIT,
   "_sample",  /* 모듈 이름 */
   "This is a module doc",  /* 모듈 문서, 없으면 NULL */
   -1,
   _sample_methods
};

PyMODINIT_FUNC 
PyInit__sample(void)
{
    PyObject *m;

    /* 모듈을 생성하고 함수를 등록한다 */
    m = PyModule_Create(&_sample_module);

    /* ... */
    return m;
}
