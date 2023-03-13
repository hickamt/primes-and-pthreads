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
  1000000 2 real 0.12
  1000000 3 real 0.11
  1000000 5 real 0.09
  1000000 7 real 0.07
  1000000 9 real 0.07
  1000000 12 real 0.06
  1000000 16 real 0.06
  1000000 20 real 0.05
  1000000 25 real 0.05
  1000000 30 real 0.06
  10000000 1 real 1.86
  10000000 2 real 1.00
  10000000 3 real 0.80
  10000000 5 real 0.62
  10000000 7 real 0.60
  10000000 9 real 0.53
  10000000 12 real 0.45
  10000000 16 real 0.43
  10000000 20 real 0.38
  10000000 25 real 0.39
  10000000 30 real 0.36
  100000000 1 real 38.70
  100000000 2 real 21.51
  100000000 3 real 14.79
  100000000 5 real 9.83
  100000000 7 real 7.78
  100000000 9 real 6.55
  100000000 12 real 5.71
  100000000 16 real 4.92
  100000000 20 real 4.40
  100000000 25 real 4.12
  100000000 30 real 4.13
  1000000000 1 real 180.13
  1000000000 2 real 180.13
  1000000000 3 real 180.13
  1000000000 5 real 134.84
  1000000000 7 real 98.67
  1000000000 9 real 80.06
  1000000000 12 real 67.71
  1000000000 16 real 57.73
  1000000000 20 real 50.63
  1000000000 25 real 46.65
  1000000000 30 real 47.10
```
