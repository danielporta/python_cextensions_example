#include <Python.h>
#include "../fib_c/src/fib.h"

/* 1. Wrapper Methods */

static PyObject* _fib(PyObject* module, PyObject* args) {
    int n;
    if (!PyArg_ParseTuple(args, "i", &n)) {
        return NULL;
    }

    if (n < 0) {
        PyErr_Format(PyExc_ValueError, "n soll >= 0 sein, war aber %d", n);
        return NULL;
    }

    int result = fib(n);

    return Py_BuildValue("i", result);
}

/* 2. Method Definitions for Python Module*/

static PyModuleDef pyMethodDefs[] = {
    {"fib", _fib, METH_VARARGS, "Berechnet fib(n)"},
    {NULL, NULL, 0, NULL}
};

/* 3. Python Module Definition */

static PyModuleDef pyModuleDef = {
    PyModuleDef_HEAD_INIT,
    "cfib",
    "Das Module liefert fib(n)",
    -1,
    pyMethodDefs
};

/* 4. Initialize the Module */

PyMODINIT_FUNC PyInit_cfib() {
    PyModule_Create(&pyModuleDef);
}







