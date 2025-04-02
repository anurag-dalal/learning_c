[YouTube tutorial Pointers](https://www.youtube.com/watch?v=zuegQmMdy8M&t=413s)

### Print a pointer
Accept a integer argument as command line and prints:
- The memory address of the integer.
- The size of data in bytes.
- The values in hex.
- The values in bits.

[Code](pointer_print.cpp)\
Compilation
```
g++ -o bin/pointer_print.o pointers/pointer_print.cpp
./bin/pointer_print.o 1025
```
Output
```
Pointer Address: 0x7ffe7ed1689c
Size of data: 4 bytes
Value in HEX: 00 00 04 01 
Value in BITS: 00000000 00000000 00000100 00000001
```

