#include <Python.h>

static PyObject *
greet(PyObject *self, PyObject *args) {
  const char *s;
  if (!PyArg_ParseTuple(args, "s", &s)) {
    return NULL;
  }
  return PyUnicode_FromFormat("Hello, %s", s);
}

static PyMethodDef HelloMethods[] = {
  {"greet", greet, METH_VARARGS, "greet something"},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef hellomodule = {
  PyModuleDef_HEAD_INIT,
  "hello",
  "say hello to the world",
  -1,
  HelloMethods
};

PyMODINIT_FUNC
PyInit_hello(void) {
  return PyModule_Create(&hellomodule);
}
