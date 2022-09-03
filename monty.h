#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
extern int num;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **st_stack, unsigned int linu);
void pall(stack_t **st_stack, unsigned int linu);
void pint(stack_t **st_stack, unsigned int linu);
void pop(stack_t **st_stack, unsigned int linu);
void swap(stack_t **st_stack, unsigned int linu);
void add(stack_t **st_stack, unsigned int linu);
void nop(stack_t **st_stack, unsigned int linu);
void monty(char **av);
void tokenize(char **buffer, char ***tokens, ssize_t r_line);
void opcode_choose(stack_t **st_stack, char ***tokens, unsigned int linu);
void free_tokens(char ***tokens);
void free_stack(stack_t *st_stack);
void check_number(char *n, unsigned int line_number);
void (*choose_opcode(char *code))(stack_t **st_stack, unsigned int linu);

#endif
