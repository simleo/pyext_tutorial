#include <Python.h>

static PyObject *
greet(PyObject *self, PyObject *args) {
  const char *s;
  if (!PyArg_ParseTuple(args, "s", &s)) {
    return NULL;
  }
  return PyString_FromFormat("Hello, %s", s);
}

static PyMethodDef HelloMethods[] = {
  {"greet", greet, METH_VARARGS, "greet something"},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
inithello(void) {
  Py_InitModule3("hello", HelloMethods, "say hello to the world");
}
