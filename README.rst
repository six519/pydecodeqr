pydecodeqr
==========

Decode QR code image file using libdecodeqr (Python Extension in C++ Sample Code). Code tested in Ubuntu 12.04

Install Requirements
====================
::

	sudo apt-get install libdecodeqr-dev

Building
========
::

	./setup.py build install

Python Sample Usage
===================
::

	import pydecodeqr
	data = pydecodeqr.decode('/home/six519/test.png')
