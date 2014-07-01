PyPi Link
=========

https://pypi.python.org/pypi/pydecodeqr/1.0

pydecodeqr
==========

Decode QR code image file using libdecodeqr (Python Extension in C++ Sample Code). Code tested in Ubuntu 12.04

Install Requirements
====================
::

	sudo apt-get install libdecodeqr-dev

Building and Installing
=======================
::

	./setup.py build install

Installing Through PyPi
=======================
::

	pip install pydecodeqr

Python Sample Usage
===================
::

	import pydecodeqr
	data = pydecodeqr.decode('/home/six519/test.png')
