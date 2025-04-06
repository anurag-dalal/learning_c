# Learning C/C++

Playground for everything c and c++ related.
Need to have basic knowledge in programming in c/c++.
Mostly will code for specific topics.
Free links and tutorial resources will also be linked.

## Changing g++/gcc version
```
sudo update-alternatives --config gcc
sudo update-alternatives --config g++
```
change default in ~/.bashrc:
```
update-alternatives --set gcc "/usr/bin/gcc-$1"
update-alternatives --set g++ "/usr/bin/g++-$1"
```
## Pointer
Pointers are variable that store addresses of another variable.

```
int a = 10; // int variable
int *p = &a; // pointer variable storing address of a
printf("Address: %d, Value: %d",p,a);
```
[Learn more about pointers](pointers/README.md)