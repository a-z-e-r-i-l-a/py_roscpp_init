#cython: language_level=3

from libcpp.string cimport string



cdef extern from "roscpp_init.h":
    cdef cppclass ROScppInitializer:
        ROScppInitializer(string node_name,
                          int    n_spinner) except +
        void roscpp_init();

cdef class PyRosCppInit:
    cdef ROScppInitializer *c_obj
    def __cinit__(self, node_name='pyroscpp',
                        n_async_spinner=5):
        self.c_obj = new ROScppInitializer(node_name,
                                           n_async_spinner)

    def roscpp_init(self):
        return self.c_obj.roscpp_init()

