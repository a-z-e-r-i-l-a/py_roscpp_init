# CAUTION:
#  - You can specify only one .pyx file for each cython module.
#  - The name of the module and the .pyx file should be identical.




set_source_files_properties(roscpp_init.pyx PROPERTIES CYTHON_IS_CXX TRUE)
cython_add_module(roscpp_init roscpp_init.pyx ../roscpp_init.cpp)
target_link_libraries(roscpp_init py_roscpp)
set_target_properties(roscpp_init
                      PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY
                      ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION})




