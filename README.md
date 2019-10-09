# perf-tests

Currious to see how c++ and rust behave relatively to each other

## Tests descriptions

A naïve algorithme that search for the `20001st` prime number.
Implemented in C,C++ and rust in a way that looks idiomatic…

### Building the test binaries

#### C/C++

```bash
cd nth-prime_cpp
make
```

generates 3 binaries:

- `nth_prime_array` is a `C++` using an array to store the prime numbers
- `nth_prime_vector` is a `C++` using a vector to store the prime numbers
- `nth_prime_array_c` is a `C` version using variadic array

#### Rust

```bash
cd nth-prime_rs
cargo build
cargo build --release
```

generates 2 binaries:

- `target/debug/nth_prime` with debug info and some code instrumentation
- `target/release/nth_prime` optimized for runtime

## perf results

### C/C++

```bash
nth-prime_cpp$ hyperfine ./nth_prime_array_c
Benchmark #1: ./nth_prime_array_c
  Time (mean ± σ):     947.5 ms ±   7.3 ms    [User: 938.4 ms, System: 7.5 ms]
  Range (min … max):   940.0 ms … 960.6 ms    10 runs

nth-prime_cpp$ hyperfine ./nth_prime_array
Benchmark #1: ./nth_prime_array
  Time (mean ± σ):     956.8 ms ±  19.9 ms    [User: 951.1 ms, System: 5.8 ms]
  Range (min … max):   941.2 ms … 999.7 ms    10 runs

nth-prime_cpp$ hyperfine ./nth_prime_vector
Benchmark #1: ./nth_prime_vector
  Time (mean ± σ):     966.2 ms ±  30.1 ms    [User: 961.0 ms, System: 5.3 ms]
  Range (min … max):   940.7 ms … 1036.8 ms    10 runs
```

### Rust

```bash
nth-prime_rs$ hyperfine target/debug/nth_prime
Benchmark #1: target/debug/nth_prime
  Time (mean ± σ):      9.415 s ±  0.043 s    [User: 9.393 s, System: 0.013 s]
  Range (min … max):    9.367 s …  9.510 s    10 runs

nth-prime_rs$ hyperfine target/release/nth_prime
Benchmark #1: target/release/nth_prime
  Time (mean ± σ):     701.7 ms ±  18.0 ms    [User: 700.3 ms, System: 0.7 ms]
  Range (min … max):   685.3 ms … 744.9 ms    10 runs
```

## Tools version

```bash
$ gcc --version
gcc (Ubuntu 8.3.0-6ubuntu1) 8.3.0

$ g++ --version
g++ (Ubuntu 8.3.0-6ubuntu1) 8.3.0

$ rustup --version
rustup 1.19.0 (2af131cf9 2019-09-08)

$ cargo --version
cargo 1.37.0 (9edd08916 2019-08-02)

$ rustc --version
rustc 1.37.0 (eae3437df 2019-08-13)
```

## Conclusion

The first attempt, that triggered the creation of this page, showed that the C++ version with vector was 4 times slower than the one with simple array.

The results were not recorded and can't be reproduced for the moment, in a sense that's a good news because all C/C++ versions have the same performances, but it requires more investigation to understand where the problem was.

On the other side, Rust implementation compiled in release mode outperform all other solutions.

## Comments are very welcome (I'm n00b)
