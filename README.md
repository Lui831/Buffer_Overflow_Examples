# Buffer Overflow Examples

This repository contains four C programs demonstrating different types of buffer overflow vulnerabilities. Each example highlights a specific scenario where improper memory handling can lead to security issues, such as overwriting adjacent memory or redirecting program execution.

## Examples

### 1. [example1.c](example1.c)
**Heap-based Buffer Overflow using `gets`**

- Allocates a small buffer on the heap.
- Reads user input with `gets`, which does not check bounds.
- Overflows into adjacent memory and checks for a "magic string" to trigger a privileged function.

### 2. [example2.c](example2.c)
**Stack-based Buffer Overflow in a Struct using `gets`**

- Defines a struct with two adjacent buffers.
- Reads input into the first buffer using `gets`.
- Overflow can overwrite the second buffer, allowing control over program logic.

### 3. [example3.c](example3.c)
**Stack-based Buffer Overflow using `strcpy`**

- Allocates a buffer with `malloc` and a pointer to an adjacent memory region.
- Copies unchecked user input with `strcpy`, potentially overflowing into the adjacent region.
- Checks if the overflowed region contains a "magic string" to trigger a privileged function.

### 4. [example4.c](example4.c)
**Buffer Overflow Redirecting Function Pointer**

- Allocates executable memory with `mmap`.
- Stores a function pointer after a buffer.
- User input can overflow the buffer and overwrite the function pointer, redirecting execution to a privileged function.

## Compilation and Execution

Each example can be compiled with `gcc`:

```sh
gcc -o example1 example1.c
gcc -o example2 example2.c
gcc -o example3 example3.c
gcc -o example4 example4.c
```

Run the compiled binaries:

```sh
./example1
./example2
./example3
./example4
```

## Disclaimer

These programs are for educational purposes only. They demonstrate insecure coding practices and should **not** be used in production code.

## Authors

- Luiz H. A. Santos
- Bruno G. Mauricio
