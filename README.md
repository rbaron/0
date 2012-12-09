0
==

Quick, dirty and RPN-ish calculations on your terminal. The main goal is to quickly do calculations using only your numpad as input.

Description
-----------

0 is a reverse polish notation calculator for the terminal. It supports addition, subtraction, multiplication, division, exponentiation and root operations.

Configuration
-------------

The input methods were thought to allow quick calculations using only your numpad. Since numpads can have slightly different layouts (such as `,` instead of `.`), you can configure your input on `config.h`, such as what is your decimal point notation or how many significant digits should be printed. Further configuration can be done on `cmd.h` (for custom commands) and `op.h` (for custom operations).

Operations
----------

Type ,,2 (or ..2, depending on your `config.h`) to access the help menu:

```
Help:
=====

Operations:
+  y + x  
-  y - x  
*  y * x  
/  y / x  
**   y ^ x  
//   y ^ 1/x

Commands:
,,0  pop the stack  
,,1  clear the stack  
,,2  print this help
```

As an example, suppose you were to calculate 12.3^(1/3) (the cubic square of 12.3):

```
Stack:
======
Y: 12.3
X: 3

//

Stack:
======
X: 2.3083502

```

License
-------

MIT License.
