A python interface to warp c vibe detection.It runs faster than implemented in python.

download [boost::python](https://dl.bintray.com/boostorg/release/1.75.0/source/boost_1_75_0_rc1.zip) and install boost::python 
Use python3.8 gcc5.4
# Install boost::python
```
unzip boost_1_75_0_rc1.zip
cd boost_1_75_0_rc1
./bootstrap.sh --with-python=[python-bin-path]
./b2 cxxflags=-fPIC cflags=-fPIC --c++11
./b2 install
```

# Build vibe
```
python setup.py build
python setup.py install
```

# Test
`python test.py`
