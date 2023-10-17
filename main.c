#include <Python.h>

void write_google_sheet(int row, double x) {
    PyObject *pName, *pModule, *pFunc, *pArgs, *pRes;

    // Import System Env and append the path
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");

    // Import Python module & function
    pName = PyUnicode_FromString("googleSheet"); // Python File Name
    pModule = PyImport_Import(pName);
    pFunc = PyObject_GetAttrString(pModule, "writeInGoogleSheet"); // Python Function Name
    
    // Bind the object to pass in
    pArgs = Py_BuildValue("(id)", row, x); // integer, double
    // Call function with args
    pRes = PyObject_CallObject(pFunc, pArgs);

    // Decrement reference to avoid memory leak
    Py_DECREF(pName);
    Py_DECREF(pModule);
    Py_DECREF(pFunc);
    Py_DECREF(pArgs);
    Py_DECREF(pRes);
}

int main() {
    int row = 5;
    double x = 3.3;

    Py_Initialize();
    write_google_sheet(row, x);
    // Py_Finalize();
}