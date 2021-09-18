#!python
#cython: language_level=3

## ! DO NOT MANUALLY INVOKE THIS setup.py, USE CATKIN INSTEAD

from setuptools import Extension, setup
from catkin_pkg.python_setup import generate_distutils_setup


setup_args = generate_distutils_setup(
    packages=['py_roscpp_pkg'],
    package_dir={'': 'src'},
    requires=['std_msgs', 'rospy'],
    language_level="3",
    compiler_directives={'language_level' : "3"}
)





setup(**setup_args)

