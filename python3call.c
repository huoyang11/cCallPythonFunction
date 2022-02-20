#include <Python.h>

int test(int argc, char *argv[]) 
{
	Py_Initialize();
	//PyRun_SimpleString("print('hello world')\n");
	PyRun_SimpleString("import os,sys");
	PyRun_SimpleString("sys.path.append('./')");

	PyObject *module = PyImport_ImportModule("pytest");
	PyObject *function = PyObject_GetAttrString(module,"testc");

	PyObject *width = PyObject_GetAttrString(module,"width");

	if (PyLong_Check(width))
	{
		long val = PyLong_AsLong(width);
		printf("width = %ld\n",val);
	}

	int height = 77;
	PyObject_SetAttrString(module,"height",Py_BuildValue("i",height));

	if (!function)
	{
		printf("PyObject_GetAttrString fun error\n");
		return -1;
	}

	int a = 20;
	int b = 30;
	PyObject *args = Py_BuildValue("(ii)",a,b);

	PyObject *RetValue = PyObject_CallObject(function, args);

	
	
	long retval = PyLong_AsLong(RetValue);
	printf("retval = %ld\n",retval);

	Py_DECREF(args);
	Py_DECREF(function);
	Py_DECREF(module);

	Py_Finalize();

	return 0;
}

int main(int argc, char *argv[])
{
	Py_Initialize();
	PyRun_SimpleString("import os,sys");
	PyRun_SimpleString("sys.path.append('./')");

	PyObject *module = PyImport_ImportModule("pytest");

	PyObject *str = Py_BuildValue("s","asb");
	PyObject *list = PyObject_GetAttrString(module,"testlist");

	int n = PyList_Size(list);
	for (int i = 0;i < n;i++)
	{
		PyObject *item = PyList_GetItem(list,i);
		if (PyLong_Check(item))
		{
			long val = PyLong_AsLong(item);
			printf("%ld\n",val);
		}
	}

	Py_Finalize();

	return 0;
}

int testtuple(int argc, char *argv[])
{
	Py_Initialize();
	PyRun_SimpleString("import os,sys");
	PyRun_SimpleString("sys.path.append('./')");

	PyObject *module = PyImport_ImportModule("pytest");

	PyObject *list = PyObject_GetAttrString(module,"testtuple");

	int n = PyTuple_Size(list);
	for (int i = 0;i < n;i++)
	{
		PyObject *item = PyTuple_GetItem(list,i);
		if (PyUnicode_Check(item))
		{
			wchar_t *val = PyUnicode_AsUnicode(item);
			wprintf(L"%ls\n",val);
		}
	}

	Py_Finalize();

	return 0;
}

int testdict(int argc, char *argv[])
{
	Py_Initialize();
	PyRun_SimpleString("import os,sys");
	PyRun_SimpleString("sys.path.append('./')");

	PyObject *module = PyImport_ImportModule("pytest");

	PyObject *list = PyObject_GetAttrString(module,"testdict");
	
	PyObject *key = NULL;
	PyObject *value = NULL;
	int n = PyDict_Size(list);
	for (int i = 0;i < n;i++)
	{
		Py_ssize_t pos = i;
		PyDict_Next(list, &pos, &key, &value);
		if (PyUnicode_Check(key))
		{
			wchar_t *val = PyUnicode_AsUnicode(key);
			wprintf(L"%ls\n",val);
		}

		if (PyLong_Check(value))
		{
			long val = PyLong_AsLong(value);
			wprintf(L"%ld\n",val);
		}
	}

	Py_Finalize();

	return 0;
}

int basevals(int argc, char *argv[])
{
	Py_Initialize();

	PyRun_SimpleString("import os,sys");
	PyRun_SimpleString("sys.path.append('./')");

	PyObject *module = PyImport_ImportModule("pytest");

	PyObject *widthobj = PyObject_GetAttrString(module,"width");
	if (PyLong_Check(widthobj))
	{
		long width = PyLong_AsLong(widthobj);
		printf("width = %ld\n",width);
	}

	PyObject *teststrobj = PyObject_GetAttrString(module,"teststr");
	if (PyUnicode_Check(teststrobj))
	{
		wchar_t *teststr = PyUnicode_AsUnicode(teststrobj);
		printf("teststr = %ls\n",teststr);
	}

	PyObject *testfloatobj = PyObject_GetAttrString(module,"testfloat");
	if (PyFloat_Check(testfloatobj))
	{
		double testfloat = PyFloat_AsDouble(testfloatobj);
		printf("testfloat = %lf\n",testfloat);
	}

	Py_Finalize();

	return 0;
}

int setvals(int argc, char *argv[])
{
	Py_Initialize();

	PyRun_SimpleString("import os,sys");
	PyRun_SimpleString("sys.path.append('./')");

	PyObject *module = PyImport_ImportModule("pytest");

	PyObject_SetAttrString(module,"mki",Py_BuildValue("i",1));
	PyObject_SetAttrString(module,"mkd",Py_BuildValue("d",1.1));
	PyObject_SetAttrString(module,"mks",Py_BuildValue("s","aaaa"));

	PyObject_SetAttrString(module,"mktuple",Py_BuildValue("(ii)",1,2));
	PyObject_SetAttrString(module,"mklist",Py_BuildValue("[ii]",1,2));

	PyObject *function = PyObject_GetAttrString(module,"mk");
	PyObject *args = Py_BuildValue("(ii)",1,2);

	if (function)
	{
		PyObject_CallObject(function, args);
	}

	Py_Finalize();

	return 0;
}