#include <Python.h>

int main(int argc, char *argv[]) 
{
	Py_Initialize();
	//PyRun_SimpleString("print('hello world')\n");
	PyRun_SimpleString("import os,sys");
    PyRun_SimpleString("sys.path.append('./')");

	PyObject *module = PyImport_ImportModule("pytest");
	PyObject *function = PyObject_GetAttrString(module,"testc");
	if (!function)
	{
		printf("PyObject_GetAttrString fun error\n");
		return -1;
	}

	int a = 20;
	int b = 30;
	PyObject *args = PyTuple_New(2);
	PyTuple_SetItem(args,0,Py_BuildValue("i",a));
	PyTuple_SetItem(args,1,Py_BuildValue("i",b));

	PyObject *RetValue = PyObject_CallObject(function, args);

	long retval = PyLong_AsLong(RetValue);
	printf("retval = %ld\n",retval);

	Py_DECREF(args);
	Py_DECREF(function);
	Py_DECREF(module);

	Py_Finalize();

	return 0;
}
