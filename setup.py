from skbuild import setup

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
