# C++ program that only compiles on Fridays

Jordi Delgado teased me with https://github.com/jwilk/perl-friday. *—Could you improve it?—* he said.

Well, no. But I can do it in C++: The following program (without #includes) can only be compiled on Fridays.

```c++
template <bool>
struct static_check {
};

template <>
struct static_check<false> {
    static_check();
};

int main()
{
    static_check<(__TIMESTAMP__[0]) == 'F'>();
}
```

Here it is:

```
> date
Thu Feb 17 11:09:04 CET 2022

> g++ -std=c++20 friday.cc
Undefined symbols for architecture x86_64:
  "static_check<false>::static_check()", referenced from:
      _main in friday-c06475.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)

⋮

> date
Fri Feb 18 02:05:11 CET 2022

> g++ -std=c++20 friday.cc

>
```

Have a good day.
