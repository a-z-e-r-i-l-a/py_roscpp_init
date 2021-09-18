# py_roscpp_init

This implementation helps for initializing ROS C++ classes that use nodehandels and are wrapped with python bindings such as Cython, similar to what explained [here](http://wiki.ros.org/ROS/Tutorials/Using%20a%20C%2B%2B%20class%20in%20Python#Class_with_NodeHandle)

This package provides the advantage of compatibility for python3 implementations with ROS Melodic using the following cmake argumets:

```
catkin config --cmake-args   -DPYTHON_EXECUTABLE=/usr/bin/python3   -DPYTHON_INCLUDE_DIR=/usr/include/python3.6m   -DPYTHON_LIBRARY=/usr/lib/x86_64-linux-gnu/libpython3.6m.so -Wno-dev -DCMAKE_CXX_FLAGS=-Wno-comment -DCMAKE_BUILD_TYPE=Release
```

Before initializing the wrapped c++ object in python simply do:

```
cppnode = roscpp_init.PyRosCppInit(node_name=b'py_cpp_class', n_async_spinner=2)
```
