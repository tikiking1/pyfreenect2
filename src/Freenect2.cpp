#include "../pyfreenect2.hpp"

using libfreenect2::Freenect2;

Freenect2 freenect2;
Freenect2& getGlobalFreenect2() { return freenect2; }

PyObject *py_numberOfDevices(PyObject *self, PyObject *args) {
	if(!PyArg_ParseTuple(args, ""))
		return NULL;
    return PyLong_FromLong(freenect2.enumerateDevices()); // Updated here
}

PyObject *py_getDefaultDeviceSerialNumber(PyObject *self, PyObject *args) {
	if(!PyArg_ParseTuple(args, ""))
		return NULL;
	std::string serialNumber = freenect2.getDefaultDeviceSerialNumber();
    return PyUnicode_FromString(serialNumber.c_str()); // Updated here
}
