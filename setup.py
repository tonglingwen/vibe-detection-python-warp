from distutils.core import setup
from distutils.extension import Extension

setup(name="PackageName", ext_modules=[ Extension("vibe", ["vibe-background-sequential.c","vibe.cpp"], libraries = ["boost_numpy38","boost_python38"] ) ])
