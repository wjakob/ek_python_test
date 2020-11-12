import setuptools

try:
    from skbuild import setup
    import pybind11
except ImportError:
    print("The preferred way to invoke 'setup.py' is via pip, as in 'pip "
          "install .'. If you wish to run the setup script directly, you must "
          "first install the build dependencies listed in pyproject.toml!",
          file=sys.stderr)
    raise

setup(
    name="ek_python_test",
    version="0.0.1",
    author="Author name",
    author_email="user@domain.org",
    description="A brief description",
    url="https://github.com/...",
    long_description="A longer description",
    long_description_content_type='text/markdown',
    cmake_args=[
        # List of commands that should be specified to CMake
        '-DSOME_FLAGS=1234'
    ],
    packages=['ek_python_test']
)
