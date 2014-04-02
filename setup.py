#!/usr/bin/env python
 
from distutils.core import setup
from distutils.extension import Extension

setup(name="pydecodeqr",
    ext_modules=[
        Extension("pydecodeqr",
            include_dirs = ['/usr/include/opencv'],
            libraries = ['decodeqr', 'opencv_core', 'opencv_highgui'], 
            sources = ["pydecodeqr.cpp"]
        )
    ]
)