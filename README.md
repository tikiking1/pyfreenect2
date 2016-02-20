pyfreenect2
===========

Python bindings to [libfreenect2](https://github.com/OpenKinect/libfreenect2).

Requirements
---------

- Python2 (python3 support coming)
- numpy
- scipy (as appropriated by your python version)
- openCV

Installation
---------

To install, run `sudo python setup.py install`.

Usage
---------

For usage, see `test.py`.


TODO List
---------

 * Make `test.py` actually display the frames
 * Implement Registration.apply (in py_Registration_apply)
 * Make the pipeline argument of Freenect2Device's constructor actually do something
 * Test everything

You can probably find more TODOs in [Issues](https://github.com/tikiking1/pyfreenect2/issues) or by `grep -R TODO .`.
