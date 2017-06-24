
Environment:
	Mac OS 10.12.3 (16D32)
	gcc/g++ --version
		Configured with: --prefix=/Applications/Xcode.app/Contents/Developer//usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/usr/include/c++/4.2.1
		Apple LLVM version 6.0 (clang-600.0.56) (based on LLVM 3.5svn)
		Target: x86_64-apple-darwin16.4.0
		Thread model: posix

First way:  
	using smr.sh:

How to execute the test program:
	1 Test list without header node:
		./smr.sh test_list list.c

	2 Test list with header node:
		./smr.sh test_hlist hlist.c


Second way:
	Using mr.sh: 
	this will include common header files and compile common src files which repo is: 
		https://github.com/cxsjabc/common.git
	eg:
		./mr.sh test_sort sort.c

