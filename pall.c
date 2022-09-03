#include "monty.h"
/**
 * pall - Print all values in the stack
 * @stack: Double pointer to the top of the stack
 * @line_num: The line of the file the command was found
 **/
void pall(stack_t **stack, unsigned int line_num){
	stack_t *walker;
	(void) line_num;
	walker = *stack;
	while (walker != NULL){
		printf("%d\n", walker->n);
		walker = walker->next;
	}
}