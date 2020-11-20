# Enoki + pybind11 example project

This simple example project shows how to build a C++ Python extension module
using both Enoki and the pybind11 libraries.

Install via PIP, by directly specifying the URL
```
$ pip install https://github.com/wjakob/ek_python_test
```

or by checking out a local copy:

```
$ git clone https://github.com/wjakob/ek_python_test
$ cd ek_python_test
$ pip install .
```

You can also run ``setup.py`` manually, but in that case you must
first install the dependencies listed in ``pyproject.toml``:

```
$ pip install scikit-build cmake ninja pybind11 enoki
$ git clone https://github.com/wjakob/ek_python_test
$ cd ek_python_test
$ pip setup.py install
```

On Windows, these steps should be executed from the *x64 Native
Tools Command Prompt* or a similar shell that has executed the
``vcvarsall.bat`` script to set paths to the compiler.
