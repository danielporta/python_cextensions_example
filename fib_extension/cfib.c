#include <Python.h>
#include "../fib_c/src/fib.h"

/* 1. Wrapper Methods */

static PyObject* _fib(PyObject* module, PyObject* args) {
    int n;

    if (!PyArg_ParseTuple(args, "i", &n)) {
        return NULL; 
    }

    if (n < 0) {
        PyErr_Format(PyExc_ValueError,"n must be >= 0, was %d", n);
        
        return NULL;
    }

    int result = fib(n);
    return Py_BuildValue("i", result);
}

/* 2. Method Definitions for Python Module*/

static PyMethodDef pyMethodDefs[] = {
    { "fib", _fib, METH_VARARGS, "calulates fib(n)" },
    {NULL, NULL, 0, NULL}
};

/* 3. Python Module Definition */

static PyModuleDef pyModuleDef = {
    PyModuleDef_HEAD_INIT,
    "cfib",
    "The cfib module",
    -1,
    pyMethodDefs
};

/* 4. Initialize the Module */

PyMODINIT_FUNC PyInit_cfib() {
    return PyModule_Create(&pyModuleDef);
}








