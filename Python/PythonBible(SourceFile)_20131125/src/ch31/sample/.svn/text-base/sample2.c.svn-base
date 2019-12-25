#include "Python.h"

static PyObject *ErrorObject;

static PyObject* sample_exception(PyObject *self, PyObject *args)
{
	PyErr_SetString(ErrorObject, "my exception");
	return NULL;
}

static PyObject* sample_frange(PyObject *self, PyObject *args)
{
	PyObject* flist;
	double v, from, to, step;
	int size, k;

	/* 파이썬에서 넘어온 인수를 C로 변환 */
	if (!PyArg_ParseTuple(args, "ddd", &from, &to, &step))
		return NULL;
	size = (to-from) / step;
	flist = PyList_New(size); /* 크기 size의 새로운 리스트 생성 */
	v = from;
	for (k = 0; k < size; k++) {
		PyList_SetItem(flist, k, PyFloat_FromDouble(v)); /* 값 설정 */
		v += step;
	}
	return flist; /* 리스트 리턴 */
}

//////////////////////////////////////////////////////////////
static struct PyMethodDef _sample_methods[] = {
 {"test_exception", sample_exception, METH_VARARGS},
 {"frange", sample_frange, METH_VARARGS},
 {NULL}		/* end of module method table */
};

static struct PyModuleDef _sample_module = {
   PyModuleDef_HEAD_INIT,
   "_sample2",  /* 모듈 이름 */
   "This is a module doc",  /* 모듈 문서, 없으면 NULL */
   -1,
   _sample_methods
};

PyMODINIT_FUNC 
PyInit__sample2(void)
{
    PyObject *m;

    /* 모듈을 생성하고 함수를 등록한다 */
    m = PyModule_Create(&_sample_module);

	ErrorObject = PyErr_NewException("_sample2.error", NULL, NULL);
    Py_INCREF(ErrorObject);
    PyModule_AddObject(m, "error", ErrorObject);

    /* ... */
    return m;
}
