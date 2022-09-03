#include "monty.h"
/**
  * pint - print the top of the stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void pint(stack_t **st_stack, unsigned int linu){
	if (*st_stack != NULL)
		printf("%d\n", (*st_stack)->n);
	else{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linu);
		exit(EXIT_FAILURE);
	}
}