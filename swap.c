#include "monty.h"
/**
  * swap - delete the top of the stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void swap(stack_t **st_stack, unsigned int linu){
	stack_t *save;
	int i;
	if (*st_stack != NULL && (*st_stack)->next != NULL){
		save = (*st_stack)->next;
		i = (*st_stack)->n;

		(*st_stack)->n = save->n;
		save->n = i;
	}
	else{
		fprintf(stderr, "L%u: can't swap, stack too short\n", linu);
		exit(EXIT_FAILURE);
	}
}