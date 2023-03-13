```c

Testing build (the Makefile)
    Passed "make clean" A good start. Keep it up.
    Trying "make ./primesMT.o"
    Trying "make ./primesMT"
    Trying "make all"
      You had no warnings messages. Excellent!
    Looking for "-Wall" in build log
    Looking for "-Wshadow" in build log
    Looking for "-Wextra" in build log
    Looking for "-Wunreachable-code" in build log
    Looking for "-Wredundant-decls" in build log
    Looking for "-Wmissing-declarations" in build log
    Looking for "-Wold-style-definition" in build log
    Looking for "-Wmissing-prototypes" in build log
    Looking for "-Wdeclaration-after-statement" in build log
    Looking for "-Wno-return-local-addr" in build log
    Looking for "-Wunsafe-loop-optimizations" in build log
    Looking for "-Wuninitialized" in build log
primes 1000 begin
  ** Found 0 non-matches of 11 tests for 1000
  ** Found 0 seg faults of 11 tests for 1000
primes 1000 end

primes 10000 begin
  ** Found 0 non-matches of 11 tests for 10000
  ** Found 0 seg faults of 11 tests for 10000
primes 10000 end

primes 100000 begin
  ** Found 0 non-matches of 11 tests for 100000
  ** Found 0 seg faults of 11 tests for 100000
primes 100000 end

primes 1000000 begin
  ** Found 0 non-matches of 11 tests for 1000000
  ** Found 0 seg faults of 11 tests for 1000000
primes 1000000 end

The PThreads library will show false leaks.
  So, don't fret too much if your code shows some reachable leaks.
  The PTheads library leave some stuff allocated.
leaks 10000 begin
  ** Found 0 leak-test failures of 5 tests for 10000
  ** Found 0 leak-test seg faults of 5 tests for 10000
  ** Look at the leakLog.err file for more information
  **   These may be false positives. CHECK THE FILE!!! leakLog.err
leaks 10000 end

timing tests 100000 begin
  100000 1
  100000 2
  100000 3
  100000 5
  100000 7
  100000 9
  100000 12
  100000 16
  100000 20
  100000 25
  100000 30
  ** Found 0 timing-test failures of 11 tests for 100000
  ** Found 0 timing-test seg faults of 11 tests for 100000
timing tests 100000 end
timing tests 1000000 begin
  1000000 1
  1000000 2
  1000000 3
  1000000 5
  1000000 7
  1000000 9
  1000000 12
  1000000 16
  1000000 20
  1000000 25
  1000000 30
  ** Found 0 timing-test failures of 11 tests for 1000000
  ** Found 0 timing-test seg faults of 11 tests for 1000000
timing tests 1000000 end
timing tests 10000000 begin
  10000000 1
  10000000 2
  10000000 3
  10000000 5
  10000000 7
  10000000 9
  10000000 12
  10000000 16
  10000000 20
  10000000 25
  10000000 30
  ** Found 0 timing-test failures of 11 tests for 10000000
  ** Found 0 timing-test seg faults of 11 tests for 10000000
timing tests 10000000 end
timing tests 100000000 begin
  100000000 1
  100000000 2
  100000000 3
  100000000 5
  100000000 7
  100000000 9
  100000000 12
  100000000 16
  100000000 20
  100000000 25
  100000000 30
  ** Found 0 timing-test failures of 11 tests for 100000000
  ** Found 0 timing-test seg faults of 11 tests for 100000000
timing tests 100000000 end
timing tests 1000000000 begin
  1000000000 1
  1000000000 2
  1000000000 3
  1000000000 5
  1000000000 7
  1000000000 9
  1000000000 12
  1000000000 16
  1000000000 20
  1000000000 25
  1000000000 30
  ** Found 0 timing-test failures of 11 tests for 1000000000
  ** Found 0 timing-test seg faults of 11 tests for 1000000000
timing tests 1000000000 end
  100000 1 real 0.02
  100000 2 real 0.02
  100000 3 real 0.02
  100000 5 real 0.01
  100000 7 real 0.01
  100000 9 real 0.01
  100000 12 real 0.01
  100000 16 real 0.01
  100000 20 real 0.01
  100000 25 real 0.01
  100000 30 real 0.01
  1000000 1 real 0.16
  1000000 2 real 0.14
  1000000 3 real 0.10
  1000000 5 real 0.08
  1000000 7 real 0.07
  1000000 9 real 0.06
  1000000 12 real 0.06
  1000000 16 real 0.05
  1000000 20 real 0.05
  1000000 25 real 0.06
  1000000 30 real 0.05
  10000000 1 real 2.27
  10000000 2 real 1.16
  10000000 3 real 0.73
  10000000 5 real 0.84
  10000000 7 real 0.62
  10000000 9 real 0.54
  10000000 12 real 0.52
  10000000 16 real 0.46
  10000000 20 real 0.43
  10000000 25 real 0.39
  10000000 30 real 0.39
  100000000 1 real 37.08
  100000000 2 real 20.86
  100000000 3 real 16.44
  100000000 5 real 10.66
  100000000 7 real 8.10
  100000000 9 real 7.16
  100000000 12 real 6.16
  100000000 16 real 4.96
  100000000 20 real 4.55
  100000000 25 real 4.32
  100000000 30 real 4.11
  1000000000 1 real 180.12
  1000000000 2 real 180.10
  1000000000 3 real 180.13
  1000000000 5 real 137.45
  1000000000 7 real 105.71
  1000000000 9 real 107.52
  1000000000 12 real 89.97
  1000000000 16 real 65.64
  1000000000 20 real 55.48
  1000000000 25 real 48.01
  1000000000 30 real 44.53
```
