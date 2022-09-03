#include "monty.h"
int num;
/**
  * push - push a number in a stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void push(stack_t **st_stack, unsigned int linu){
	stack_t *new = malloc(sizeof(stack_t));
	(void) linu;
	if (new == NULL)
		return;
	new->n = num;
	new->prev = NULL;
	new->next = NULL;
	if (*st_stack != NULL){
		new->next = *st_stack;
		(*st_stack)->prev = new;
	}
	*st_stack = new;
}