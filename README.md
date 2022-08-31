# :bulb: C - Stacks, Queues - LIFO, FIFO :bulb:

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python).
It relies on a unique stack, with specific instructions to manipulate it.
The goal of this project is to create an interpreter for Monty ByteCodes files.

**Monty byte code files**

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

    user@ubuntu:~/monty$ cat -e bytecodes/000.m
    push 0$
    push 1$
    push 2$
      push 3$
                       pall    $
    push 4$
        push 5    $
          push    6        $
    pall$
    user@ubuntu:~/monty$
    
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

    user@ubuntu:~/monty$ cat -e bytecodes/001.m
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
    pall This is the end of our program. Monty is awesome!$
    user@ubuntu:~/monty$

### Resources
Read or watch:

 * [Google](https://www.google.com/webhp?q=stack%20and%20queue)
 * [How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)

### Compilation & Output
Your code will be compiled this way:

    $ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

### Structure

* The **push opcode** pushes an element to the stack.
* The **opcode pall** prints all the values on the stack, starting from the top of the stack.
* The **opcode pint** prints the value at the top of the stack, followed by a new line.
* The **opcode pop** removes the top element of the stack.
* The **opcode swap** swaps the top two elements of the stack.
* The **opcode add** adds the top two elements of the stack.
* The **opcode nop** doesn’t do anything.

### Author
David Santiago Arias Lombana C18 @davesantiarlom
