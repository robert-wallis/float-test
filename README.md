float-test
==========

Load and multiply 10 million floats in C.  To test if a platform like the Raspberry Pi is fast enough to do Machine Learning.

Installation
------------
```
$ make
$ ./data-gen random.float
```

Testing
-------
```
$ test ./fptest random.float
Loaded 10000000 floats from random.float
result 1094621.875000

real	0m3.362s
user	0m2.910s
sys   0m0.440s
```
