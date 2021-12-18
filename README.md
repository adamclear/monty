## 0x19 C. Stacks and Queues - LIFO, FIFO

# Monty Interpreter


Monty 0.98 is a scripting language that is first compiled into Monty byte
codes, just like Python. It relies on a unique stack, with specific 
instructions to manipulate it. The goal of this project is to create an 
interpreter for Monty bytecode files and execute the commands they contain.

---

## Monty bytecode files


Files containing Monty bytecodes typically have a `.m` extension. Most 
of the industry uses this standard, but it is not required by the 
specification of the language. There is not more than one instruction
per line. There can be any number of spaces before or after the opcode
and its argument.

```
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```

Monty byte code files can contain blank lines; empty or made of spaces only.
Any additional text after the opcode or its required argument is not taken
into account.

```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
```

---

## Compilation


To compile: `$ gcc *.c -o monty`

Once compiled, run: `$ ./monty yourfile.m`

---

## Monty Opcodes


| Opcode | Function |
|:------:|:--------------------------------------------------------------------|
| push | Pushes element to the stack. ex. `push 3` pushes 3 to the stack. |
| pall | Prints all values currently on the stack. |
| pint | Prints the value at the top of the stack, followed by newline (`\n`). |
| pop | Removes, or "pops" the top element of the stack. |
| swap | Swaps the top two elements of the stack. |
| add | Adds the top two elements of the stack. |
| nop | The nop (no operation) code doesn't do anything. |

---

## Usage and Errors


0. `./monty <file>`

	`<file>` is the file containing Monty bytecode.

	Error: `USAGE: monty file`

	If the user does not give a file, or if more than one argument is passed, 
	the program will return the above error.

	Error: `Error: Can't open file`

	If it is not possible to open the file, the program will return the above 
	error.

	Error: `L<line_number>: unknown instruction <opcode>`

	If the file contains invalid instructions, the program will return the 
	above error.


1. **push** `push <int>`

	Error: `L<line_number>: usage: push integer`

	If `<int>` is not an integer, or if there is no argument given to `push`, 
	the above error will print.


2. **pall** `pall`

	The `pall` opcode prints all values on the stack, starting from the top of 
	the stack. If the stack is empty, nothing will print.


3. **pint** `pint`

	Error: `L<line_number>: can't pint, stack empty`

	If there is nothing in the stack, the above error will return.


4. **pop** `pop`

	Error: `L<line_number>: can't pop an empty stack`

	If the stack is empty, the above error will return.


5. **swap** `swap`

	Error: `L<line_number>: can't swap, stack too short`

	If there are less than two elements in the stack, the above error 
	will return.


6. **add** `add`

	Error: `L<line_number>: can't add, stack too short`

	If the stack contains less than two elements, the above error returns.

	On success: The result is stored in the second to the top element of the
	stack, and the top element is removed. At the end:

	 * The top element of the stack holds the result

	 * The stack is one element shorter


7. **nop** `nop`

	The `nop` opcode does nothing, and has no error codes.



---

## Authors

<strong><em>This project was written by:</em></strong>

* Adam Clear || [Github](https://github.com/adamclear)

* Adam Brummer || [Github](https://github.com/AdamNB-sys)

[Station!](https://www.youtube.com/watch?v=pLqoZtmyxxk)

---
