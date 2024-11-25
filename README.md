# Project Printf Function Groupe

## Description 
This project implements a custom `_printf` function that produces output according to a format string. The function mimics the behavior of the standard C library function printf, but with a limited set of conversion specifiers.

## Compilation
The code should be compiled using the following command:
```gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c```

## Requirements
- All files will be compiled on Ubuntu 20.04 LTS using gcc
- Code should follow the Betty style guide
- No global variables are allowed
- Maximum of 5 functions per file
- Prototypes of all functions should be included in the header file main.h
- Header files should be include guarded
- Example Usage
```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "world");
    _printf("Character: %c\n", 'A');
    _printf("Percent sign: %%\n");
    return (0);
}
```


## Testing
To test the ``_printf function``, create a separate test folder containing main files with various test cases. 

## Authors

[Mano Delcourt](https://github.com/Maniok19)
[Warren Gomes Martins](https://github.com/Warrre)