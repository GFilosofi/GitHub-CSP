Cosmed Streaming Protocol
Author: G.Filosofi
10 March 2017

---------------------------------------------------------------------------------
Introduction

The purpose of this C library is to easily interface COSMED products with modern 
handheld smart devices. CSP is inspired to the NMEA 0813 standard.
The library and test programs are a C, POSIX implementation.
The library, as the protocol, is asymmetric. It can be deployed for two entities: 

- Product: any applicable COSMED equipment, to date K5 (ARM based)
- Device: any compatible smart device, to date Apple iPhone 5 or newer

Subject’s physiological data gathered by Product may be used directly on Device or
transferred to other applications.
The Product is a service server and a communication slave, the Device is a client
and the communication master.

CSP is inspired to the NMEA 0813 standard. All messages are formatted as ASCII
strings, allowing simplified debugging and readability.
Initially inspired to NMEA library implementation by Tim (xtimor@gmail.com), which
is available at http://nmea.sourceforge.net.

---------------------------------------------------------------------------------
Features

- ToDo

---------------------------------------------------------------------------------
Supported platforms

- linux
- iOS

---------------------------------------------------------------------------------
Build
- host:
	$ BUILDALT=host make
- k5 (arm):
	$ make
- iPhone (Xcode project available on request)

---------------------------------------------------------------------------------
Licence:
	LGPL (http://www.gnu.org/licenses/lgpl.html)


---------------------------------------------------------------------------------
libsrc
	This is the main CSP library source code. It includes the CSP message framing.
	This target produces as output a shared object library, libcsp.so.

dylibcsp
	This project defines a C dynamic library interface for macOS 12.0 and later, 
	which may be imported into other languages that support dynamic libraries.
	Use of the CSP dynamic library interface greatly simplifies Mac OS X application
	development with CSP. A binary release version, libcsp.dylib, is available in 
	the bin directory.

libtest
	A simple command line application built on top of the CSP .so library

dylibtest
	A simple command line application built on top of the CSP .dylib library


---------------------------------------------------------------------------------
Using dynamic libraries

After compiling an application using the dynamic library, make sure that the binary
version of the library is either in the same path as the executable, or in a path
specified by either of the following environment variables:
LD_LIBRARY_PATH
DYLD_LIBRARY_PATH
DYLD_FALLBACK_LIBRARY_PATH

