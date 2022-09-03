#include "monty.h"
/**
  * pop - delete the top of the stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void pop(stack_t **st_stack, unsigned int linu){
	stack_t *save;
	if (*st_stack != NULL){
		save = (*st_stack)->next;
		free(*st_stack);
		*st_stack = save;
		if (*st_stack != NULL)
			(*st_stack)->prev = NULL;
	}
	else{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linu);
		exit(EXIT_FAILURE);
	}
}