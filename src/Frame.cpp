#include "../pyfreenect2.hpp"
#include <iostream>
#include "SmartFrame.h"
#include <numpy/arrayobject.h>

using libfreenect2::Frame;

void py_Frame_destroy(PyObject *frameCapsule) {
	delete ((SPFrame*) PyCapsule_GetPointer(frameCapsule, "Frame"));
}

PyObject *py_Frame_getHeight(PyObject *self, PyObject *args) {
	PyObject *frameCapsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &frameCapsule))
		return NULL;
	SPFrame *spFrame = (SPFrame*) PyCapsule_GetPointer(frameCapsule, "Frame");
	Frame *frame = spFrame->acquire();
    size_t height = frame->height;
	spFrame->release();
    return PyLong_FromSize_t(height); // Updated here
}

PyObject *py_Frame_getWidth(PyObject *self, PyObject *args) {
	PyObject *frameCapsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &frameCapsule))
		return NULL;
	SPFrame *spFrame = (SPFrame*) PyCapsule_GetPointer(frameCapsule, "Frame");
	Frame *frame = spFrame->acquire();
    size_t width = frame->width;
	spFrame->release();
    return PyLong_FromSize_t(width); // Updated here
}

PyObject *py_Frame_getData(PyObject *self, PyObject *args) {
	PyObject *frameCapsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &frameCapsule))
		return NULL;
	SPFrame *spFrame = (SPFrame*) PyCapsule_GetPointer(frameCapsule, "Frame");
	Frame *frame = spFrame->acquire();

	// frames are apparently 4 channel (4 bytes per pixel)
    npy_intp dims[] = {static_cast<npy_intp>(frame->height), static_cast<npy_intp>(frame->width), 4}; // Updated here

	// this should be elsewhere, however, fails without it.
	import_array();

	PyArrayObject *array = (PyArrayObject*) PyArray_SimpleNewFromData(3, 
									  dims, 
									  NPY_UINT8,
									  frame->data);
	spFrame->release();
	return (PyObject*) array;
}

PyObject *py_Frame_getDepthData(PyObject *self, PyObject *args){

	PyObject *frameCapsule = NULL;
	if(!PyArg_ParseTuple(args, "O", &frameCapsule))
		return NULL;
	SPFrame *spFrame = (SPFrame*) PyCapsule_GetPointer(frameCapsule, "Frame");
	Frame *frame = spFrame->acquire();

    npy_intp dims[] = {static_cast<npy_intp>(frame->height), static_cast<npy_intp>(frame->width), 4}; // Updated here

	import_array();

	PyArrayObject *array = (PyArrayObject*) PyArray_SimpleNewFromData(3, 
									  dims, 
									  NPY_UINT8,
									  frame->data);
	spFrame->release();
	return (PyObject*) array;
}
