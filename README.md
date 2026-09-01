# Project 0 - Compile, Test, Debug

- Name: Nathan Marquis
- Email: nathanmarquis659@u.boisestate.edu
- Class: 425-001

## Known Bugs or Issues

The only issue I had was very minor, my IDE kept trying to install and use a docker container to run this project inside the container,
but it would error out every time I tried to use it. I ended up ignoring it and just running it bare on my machine which worked fine. 

## Experience

This project was mostly straightforward, but at times there was enough vagueness where I was unsure of how to proceed. The most clear
example of this was all the additional erroneous code that we added, which was then never specified whether we should leave in or not.
My best assumption is that we are meant to comment it out before submission so that is what I did. However, they can be included and still
get 100% coverage and tests passing so this could be made more clear in the future. I usually struggle with C because it is a weakness of
mine, but this project has enough premade in the makefile that it was not difficult at all for the introduction.


Task 4 - Initial NULL pointer deref
``` bash
✔ ~/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug [master|● 1✚ 2…1] $ ./build/debug/myapp_d
Hello, World!
AddressSanitizer:DEADLYSIGNAL
=================================================================
==363622==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x5b6fa17ca2fb bp 0x7ffd4d51b3d0 sp 0x7ffd4d51b3c0 T0)
==363622==The signal is caused by a READ memory access.                                                                                                                                                
==363622==Hint: address points to the zero page.
#0 0x5b6fa17ca2fb in main src/main.c:22
#1 0x7de61b02a600 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:59
#2 0x7de61b02a717 in __libc_start_main_impl ../csu/libc-start.c:360
#3 0x5b6fa17ca1a4 in _start (/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug/build/debug/myapp_d+0x11a4) (BuildId: ad039a666e9018cf7e4cdd2c1f3fad3bdcf13947)

==363622==Register values:
rax = 0x0000000000000000  rbx = 0x0000000000000000  rcx = 0x0000000000000003  rdx = 0x0000000000000000  
rdi = 0x00007de61bba20d0  rsi = 0x00007de61bbab300  rbp = 0x00007ffd4d51b3d0  rsp = 0x00007ffd4d51b3c0  
r8 = 0x00007a061a3e0000   r9 = 0x000000000000200e  r10 = 0x0000000000000008  r11 = 0x000079e61a3e0000  
r12 = 0x00007ffd4d51b508  r13 = 0x0000000000000001  r14 = 0x00007de61bc51000  r15 = 0x00005b6fa17ccd38  
AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV src/main.c:22 in main
==363622==ABORTING
✘-1 ~/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug [master|● 1✚ 2…1] $ ./build/release/myapp
Hello, World!
Segmentation fault         (core dumped) ./build/release/myapp
```
## Task 4 - After adding volatile keyword
``` bash
✔ ~/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug [master|● 1✚ 4…1] $ ./build/debug/myapp_d
Hello, World!
AddressSanitizer:DEADLYSIGNAL
=================================================================
==407892==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x5592c421f2fb bp 0x7ffd6d24d670 sp 0x7ffd6d24d650 T0)
==407892==The signal is caused by a READ memory access.                                                                                                                                                
==407892==Hint: address points to the zero page.
    #0 0x5592c421f2fb in main src/main.c:22
    #1 0x7fd4d562a600 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:59
    #2 0x7fd4d562a717 in __libc_start_main_impl ../csu/libc-start.c:360
    #3 0x5592c421f1a4 in _start (/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug/build/debug/myapp_d+0x11a4) (BuildId: fbc2a4de965524514a6b008a179d3c4af04b3714)

==407892==Register values:
rax = 0x0000000000000000  rbx = 0x0000000000000000  rcx = 0x0000000000000003  rdx = 0x0000000000000000  
rdi = 0x00007fd4d59e40d0  rsi = 0x00007fd4d59ed300  rbp = 0x00007ffd6d24d670  rsp = 0x00007ffd6d24d650  
 r8 = 0x00007bf4d49e0000   r9 = 0x000000000000200e  r10 = 0x0000000000000008  r11 = 0x00007bd4d49e0000  
r12 = 0x00007ffd6d24d7a8  r13 = 0x0000000000000001  r14 = 0x00007fd4d62cf000  r15 = 0x00005592c4221d38  
AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV src/main.c:22 in main
==407892==ABORTING
✘-1 ~/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug [master|● 1✚ 4…1] $ ./build/release/myapp
Hello, World!
Segmentation fault         (core dumped) ./build/release/myapp
✘-SEGV ~/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug [master|● 1✚ 4…1] $ 
```

## Task 4 - Leak Test
```bash
✔ ~/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug [master|● 1✚ 4…1] $ make all
make[1]: Entering directory '/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug'
mkdir -p build/debug
cc -g -O0 -DDEBUG -fno-omit-frame-pointer -fsanitize=address -c src/main.c -o build/debug/main.c.o
mkdir -p build/debug
cc -g -O0 -DDEBUG -fno-omit-frame-pointer -fsanitize=address -c src/lab.c -o build/debug/lab.c.o
cc -g -O0 -DDEBUG -fno-omit-frame-pointer -fsanitize=address build/debug/main.c.o build/debug/lab.c.o -o build/debug/myapp_d -fsanitize=address
make[1]: Leaving directory '/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug'
make[1]: Entering directory '/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug'
mkdir -p build/release
cc -Wall -Wextra -O2 -fPIE -MMD -MP -Wformat -Wformat=2 -Wconversion -Wsign-conversion -Wimplicit-fallthrough -fstack-protector-strong -Werror=format-security -Werror=implicit -Werror=incompatible-pointer-types -Werror=int-conversion -c src/main.c -o build/release/main.c.o
src/main.c: In function ‘main’:
src/main.c:24:11: warning: unused variable ‘leaked’ [-Wunused-variable]
   24 |     char *leaked = malloc(64); // Memory leak
      |           ^~~~~~
mkdir -p build/release
cc -Wall -Wextra -O2 -fPIE -MMD -MP -Wformat -Wformat=2 -Wconversion -Wsign-conversion -Wimplicit-fallthrough -fstack-protector-strong -Werror=format-security -Werror=implicit -Werror=incompatible-pointer-types -Werror=int-conversion -c src/lab.c -o build/release/lab.c.o
src/lab.c: In function ‘get_product’:
src/lab.c:38:9: warning: unused variable ‘leaked’ [-Wunused-variable]
   38 |   char *leaked = malloc(64);
      |         ^~~~~~
cc -Wall -Wextra -O2 -fPIE -MMD -MP -Wformat -Wformat=2 -Wconversion -Wsign-conversion -Wimplicit-fallthrough -fstack-protector-strong -Werror=format-security -Werror=implicit -Werror=incompatible-pointer-types -Werror=int-conversion build/release/main.c.o build/release/lab.c.o -o build/release/myapp 
make[1]: Leaving directory '/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug'
make[1]: Entering directory '/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug'
mkdir -p build/tests
cc -g -O0 -DTEST -fprofile-arcs -ftest-coverage -c src/main.c -o build/tests/main.c.o
mkdir -p build/tests
cc -g -O0 -DTEST -fprofile-arcs -ftest-coverage -c src/lab.c -o build/tests/lab.c.o
mkdir -p build/tests/
cc -g -O0 -DTEST -fprofile-arcs -ftest-coverage -c tests/lab-test.c -o build/tests/lab-test.c.o
mkdir -p build/tests/harness/
cc -g -O0 -DTEST -fprofile-arcs -ftest-coverage -c tests/harness/unity.c -o build/tests/harness/unity.c.o
cc -g -O0 -DTEST -fprofile-arcs -ftest-coverage build/tests/main.c.o build/tests/lab.c.o build/tests/lab-test.c.o build/tests/harness/unity.c.o -o build/tests/myapp_t -fprofile-arcs -ftest-coverage
make[1]: Leaving directory '/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug'
make[1]: Entering directory '/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug'
mkdir -p build/debug-test
cc -g -O0 -DDEBUG -DTEST -fno-omit-frame-pointer -fsanitize=address -c src/main.c -o build/debug-test/main.c.o
mkdir -p build/debug-test
cc -g -O0 -DDEBUG -DTEST -fno-omit-frame-pointer -fsanitize=address -c src/lab.c -o build/debug-test/lab.c.o
mkdir -p build/debug-test/
cc -g -O0 -DDEBUG -DTEST -fno-omit-frame-pointer -fsanitize=address -c tests/lab-test.c -o build/debug-test/lab-test.c.o
mkdir -p build/debug-test/harness/
cc -g -O0 -DDEBUG -DTEST -fno-omit-frame-pointer -fsanitize=address -c tests/harness/unity.c -o build/debug-test/harness/unity.c.o
cc -g -O0 -DDEBUG -DTEST -fno-omit-frame-pointer -fsanitize=address build/debug-test/main.c.o build/debug-test/lab.c.o build/debug-test/lab-test.c.o build/debug-test/harness/unity.c.o -o build/debug-test/myapp_td -fsanitize=address
make[1]: Leaving directory '/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug'
Builds completed. You can run the application with: ./build/release/myapp
You can run the debug build with: ./build/debug/myapp_d
You can run the test build with: ./build/tests/myapp_t
You can run the debug-test build with: ./build/debug-test/myapp_td
✔ ~/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug [master|● 1✚ 4…1] $ make leak
Hello, World!
AddressSanitizer:DEADLYSIGNAL
=================================================================
==399236==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x563ce6fb32fb bp 0x7ffc81573f00 sp 0x7ffc81573ee0 T0)
==399236==The signal is caused by a READ memory access.                                                                                                                                                
==399236==Hint: address points to the zero page.
    #0 0x563ce6fb32fb in main src/main.c:22
    #1 0x7f1897e2a600 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:59
    #2 0x7f1897e2a717 in __libc_start_main_impl ../csu/libc-start.c:360
    #3 0x563ce6fb31a4 in _start (/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug/build/debug/myapp_d+0x11a4) (BuildId: 5bc26a0e6e27426e3bc5462240b18a206f3bb479)

==399236==Register values:
rax = 0x0000000000000000  rbx = 0x0000000000000000  rcx = 0x0000000000000003  rdx = 0x0000000000000000  
rdi = 0x00007f189895e0d0  rsi = 0x00007f1898967300  rbp = 0x00007ffc81573f00  rsp = 0x00007ffc81573ee0  
 r8 = 0x00007b38971e0000   r9 = 0x000000000000200e  r10 = 0x0000000000000008  r11 = 0x00007b18971e0000  
r12 = 0x00007ffc81574038  r13 = 0x0000000000000001  r14 = 0x00007f1898b33000  r15 = 0x0000563ce6fb5d38  
AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV src/main.c:22 in main
==399236==ABORTING
make: *** [Makefile:109: leak] Error 1
✘-2 ~/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug [master|● 1✚ 4…1] $ make leak-test
Setting up tests...
Tearing down tests...
tests/lab-test.c:43:test_get_greeting:PASS
Setting up tests...
Tearing down tests...
tests/lab-test.c:44:test_get_product:PASS
Setting up tests...
Tearing down tests...
tests/lab-test.c:45:test_bad_sum:PASS

-----------------------
3 Tests 0 Failures 0 Ignored 
OK

=================================================================
==399321==ERROR: LeakSanitizer: detected memory leaks
                                                                                                                                                                                                       
Direct leak of 64 byte(s) in 1 object(s) allocated from:
    #0 0x7f6ca1f2b60f in malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:67                                                                                                             
    #1 0x557abd7715d3 in get_product src/lab.c:38
    #2 0x557abd771781 in test_get_product tests/lab-test.c:32
    #3 0x557abd775961 in UnityDefaultTestRun tests/harness/unity.c:2202
    #4 0x557abd771863 in main tests/lab-test.c:44
    #5 0x7f6ca1a2a600 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:59
    #6 0x7f6ca1a2a717 in __libc_start_main_impl ../csu/libc-start.c:360
    #7 0x557abd771344 in _start (/home/nathanm/Seafile/Boise State/FA-26/CS425_Networks/P0_Compile-Test-Debug/build/debug-test/myapp_td+0x3344) (BuildId: effe51aa3dd97b068b2dd12de21a5fd53fea86d0)

SUMMARY: AddressSanitizer: 64 byte(s) leaked in 1 allocation(s).
make: *** [Makefile:117: leak-test] Error 1
```