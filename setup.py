from distutils.core import setup
from distutils.extension import Extension
#lopencv_imgcodecs -lopencv_imgproc -lopencv_ximgproc -lopencv_highgui -lopencv_core
setup(name="PackageName", ext_modules=[ Extension("vibe", ["vibe-background-sequential.c","vibe.cpp"], libraries = ["opencv_core","boost_numpy38","boost_python38"] ) ])