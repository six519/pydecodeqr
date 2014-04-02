#!/usr/bin/env python
 
from distutils.core import setup
from distutils.extension import Extension

setup(name="pydecodeqr",
    version="1.0",
    description="QR Code Image Decoder Using libdecodeqr",
    author="Ferdinand Silva",
    author_email="ferdinandsilva@ferdinandsilva.com",
    url="https://github.com/six519/pydecodeqr",
    classifiers=(
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Natural Language :: English',
        'Programming Language :: Python',
		'Programming Language :: C',
		'Programming Language :: C++',
        'License :: Freeware',
        'Topic :: Software Development :: Libraries :: Python Modules',
    ),
    download_url="https://github.com/six519/pydecodeqr",
    ext_modules=[
        Extension("pydecodeqr",
            include_dirs = ['/usr/include/opencv'],
            libraries = ['decodeqr', 'opencv_core', 'opencv_highgui'], 
            sources = ["pydecodeqr.cpp"]
        )
    ]
)