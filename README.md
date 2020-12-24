A python interface to warp vibe detection c++.It runs faster than implemented in Python.

download [boost.python](https://dl.bintray.com/boostorg/release/1.75.0/source/boost_1_75_0_rc1.zip) and install boost.python 

1.install boost.python
./bootstrap --with-python=[python-bin-path]
./b2 cxxflags=-fPIC cflags=-fPIC --c++11
./b2 install
