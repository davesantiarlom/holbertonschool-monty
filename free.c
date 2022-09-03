#include "monty.h"
/**
 * free_and_exit - Free all necessary memory and exit with EXIT_FAILURE
 * @line: The line found using getline()
 * @file: The file opened and being read from
 * @stack: The top of the stack list
 **/
void free_and_exit(char *line, FILE *file, stack_t *stack){
	free_stack(stack);
	free(line);
	fclose(file);
	exit(EXIT_FAILURE);
}
/**
 * free_stack - Free all nodes of the stack
 * @stack: Top of the stack list
 **/
void free_stack(stack_t *stack){
	stack_t *kill_node;
	while (stack != NULL){
		kill_node = stack;
		stack = stack->next;
		free(kill_node);
	}
}