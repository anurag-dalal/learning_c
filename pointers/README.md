[YouTube tutorial Pointers](https://www.youtube.com/watch?v=zuegQmMdy8M&t=413s)

## Usage
Try to solve each problem by reading the problem and the output. If you are stuck you can see the code. Note that the adresses that are shown in ouput will be different and different each time you run the code.
### 0. Basics
This is not a problem but see the code read the comments and run it.

In C/C++, an `int` is a primitive data type. Primitives are stored directly in memory. Each piece of data resides in a specific memory block, and these blocks have "memory addresses" that uniquely identify them.

**Memory Allocation and Addresses**

When you declare `int i = 1;`, your computer:

1.  Allocates a block of memory suitable for storing an integer.
2.  Assigns a unique memory address to this block (e.g., `0xF00000`).
3.  Stores the value `1` in that memory location.

When you use the variable `i`, you're essentially accessing the value stored at the memory address `0xF00000`, which is `1`.

**The Address-of Operator (`&`)**

In C, you can obtain the memory address where a variable is stored using the ampersand (`&`) operator.

* `i === 1;`  // True: `i` holds the value 1.
* `&i === 1;` // False: `&i` is a memory address, not the value 1.
* `&i === 0xF00000;` // True (assuming `i` is stored at `0xF00000`).

Note: In 32 bit OS, pointers are 4 bytes, but in 64 bit its 8 bytes.

**Pointers**

A pointer is a variable that stores a memory address. It "points" to a specific location in memory. Pointers themselves don't hold values in the same way primitives do; they hold memory addresses.

**Dereferencing Pointers (`*`)**

To access the value stored at the memory address held by a pointer, you use the dereference operator (`*`).

```c
int i = 1;      // Allocates an integer and assigns it the value 1.
int *ptr = &i;  // Creates a pointer 'ptr' that stores the memory address of 'i'.

printf("%d", i);   // Prints the value of 'i' (1).
printf("%d", *ptr); // Prints the value at the memory address stored in 'ptr' (also 1).
```
[Code](basics.cpp)
### 1. Print a pointer
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

### 2. Pointer of user defined class
Create a simple animal class with 2 member variable.
- `name` (std::string): Represents the name of the animal.
- `age` (int): Represents the age of the animal.

[Code](pointer_class.cpp)\
Output
![Animal Class Pointer Example](op_images/pointers_class.png)


### 3. Pointer arithmetic
Using the same animal class. Create array of 3 animals.
Using pointer arithmetic display the address and details of pointer.

[Code](pointer_arithmetic.cpp)\
Output
```
Size of data: 40 bytes
Pointer Address: 0x7ffe939563a0
Animal Name: Lion
Age: 5
Pointer Address: 0x7ffe939563c8
Animal Name: Tiger
Age: 4
Pointer Address: 0x7ffe939563f0
Animal Name: Elephant
Age: 10
```
Note:\
0x7ffe939563c8 - 0x7ffe939563c8 = 0x000000000028 (in hex) = 40 in decimal\
When creating an array the memory for individual variable/object are consequent. Thus my incrementing the pointer value we can get to the next variable/object.

### 4. Void pointer
Go through the [code](void_pointer.cpp) and read the comments.

### 5. Pointer to Pointer
[Resource](https://home.csulb.edu/~pnguyen/cecs282/lecnotes/Pointer%20to%20Pointer.pdf)

Pointer to a pointer is a form of multiple indirection or a chain of pointers.
Normally, a pointer contains the address of a variable. When we define a
pointer to a pointer, the first pointer contains the address of the second
pointer, which points to the location that contains the actual value as shown
below.

A variable that is a pointer to a pointer must be declared as such. This is done
by placing an additional asterisk in front of its name. For example, following
is the declaration to declare a pointer to a pointer of type int −
`int **var;`
When a target value is indirectly pointed to by a pointer to a pointer,
accessing that value requires that the asterisk operator be applied twice, as
is shown below in the example −

```c
#include <iostream>
using namespace std;
int main () {
 int var;
 int *ptr;
 int **pptr;
 var = 3000;
 // take the address of var
 ptr = &var;
 // take the address of ptr using address of operator &
 pptr = &ptr;
 // take the value using pptr
 cout << "Value of var :" << var << endl;
 cout << "Value available at *ptr :" << *ptr << endl;
 cout << "Value available at **pptr :" << **pptr << endl;
 return 0;
}

```
Output
```
Value of var :3000
Value available at *ptr :3000
Value available at **pptr :3000
```
C++ allows the use of pointers that point to pointers, that these, in its turn,
point to data (or even to other pointers). The syntax simply requires an
asterisk (*) for each level of indirection in the declaration of the pointer:
```c
char a;
char * b;
char ** c;
a = 'z';
b = &a;
c = &b;
```
This, assuming the randomly chosen memory locations for each variable
of 7230, 8092, and 10502, could be represented as:

![Pointer to Pointer](op_images/p2p.png)

See this [code](pointer_to_pointer.cpp) and read the comments.

Output:
```
x = 5
x = 10
Address of x = 0x7fffbf775edc, value of x = 10
Address of p = 0x7fffbf775ee0, value of p = -1082695972
Address of pp = 0x7fffbf775ee8, value of pp = -1082695968
Dereferencing of p = 10
Dereferencing of pp one time = -1082695972, two time = 10
Dereferencing of ppp one time = -1082695968, two time = -1082695972, three time = 10
```
### 6. Pointers as function arguments - Call by reference


<img src="op_images/memory.png" alt="Memory" width="300px">\

#### Example of function call stack:
See this [code](pointer?function.cpp) and the expected output:

```
a initial value in main = 5
a initial value in Increment = 5
a value in Increment after +1 = 6
a final value in main after increment= 5
a initial value in Increment with pointer = 5
a value in Increment after +1 with pointer= 6
a final value in main after increment with pointer= 6
```
Call stack:

Call Stack Diagram:
```
-------------------------------------------------------------

1. main() is called:

   Stack: [main()]

   Memory:
     a (in main) : 5  (Address: 0x1000, for example)

   Output:
     a initial value in main = 5

-------------------------------------------------------------

2. Increment(a) is called (pass by value):

   Stack: [main(), Increment(a)]

   Memory:
     a (in main) : 5 (Address: 0x1000)
     a (in Increment): 5 (Address: 0x2000, a copy)

   Output:
     a initial value in Increment = 5
     a value in Increment after +1 = 6

   Stack: [main()] // Increment(a) returns and is popped

   Memory:
     a (in main) : 5 (Address: 0x1000)

   Output:
     a final value in main after increment= 5

-------------------------------------------------------------

3. Increment(&a) is called (pass by pointer):

   Stack: [main(), Increment(&a)]

   Memory:
     a (in main) : 5 (Address: 0x1000)
     a (in Increment): 0x1000 (Address of a in main)

   Output:
     a initial value in Increment with pointer = 5
     a value in Increment after +1 with pointer= 6

   Stack: [main()] // Increment(&a) returns and is popped

   Memory:
     a (in main) : 6 (Address: 0x1000)

   Output:
     a final value in main after increment with pointer= 6

-------------------------------------------------------------

4. main() returns:

   Stack: []

   Program terminates.
```

### 7a. Pointer and array
When arrays are declared they are consecutive in memory, and by incrementing the pointer we can have a reference to next element.

<img src="op_images/pointer_array.png" alt="Memory allocation" width="700px">

```c
int A[5] = {2,4,5,8,1};
int i = 1;
// can get the address of ith element in array by: &A[i] or (A+i)
// can get value at i by: A[i] or *(A+i)
```
### 7b. Sum of all elements of int array

Using pass by reference find sum of all elements in an `int` array. Think how you will know the size of the array...

[Code](pointer_array_sum.cpp)\
Output:
```
In main(), size of A = 20, A[0] = 4
In SumOfElements(int A[]), size of A = 8, A[0] = 4
In SumOfElements(int A[]), size of A = 8, A[0] = 4
Sum of elements when size is not passed = 3
In SumOfElements(int A[], int size), size of A = 8, A[0] = 4
Sum of elements = 15
```

### 8. Characters arrays and pointers

Character -> 'a', '#', '3', '\t', '\n', '\0'

String -> Group of characters. Ex "john", "Hello World!!", "I'm feeling luckky".

Strings are stored in `char` array.
Size of the char array >= # of characters in string + 1.
In older versions of C (C89/C90, the concept of a "string" was tightly coupled with null-terminated character arrays.
Ex. for "John" size of array >= 5
Actually "John" is stored as {'J', 'o', 'h','n','\0'}. '\0' is a null character signifies end of the string. String in c are null terminated.

