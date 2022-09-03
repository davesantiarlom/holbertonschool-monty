#include "monty.h"
/**
  * pall - print the stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void pall(stack_t **st_stack, unsigned int linu)
{
	stack_t *save = *st_stack;

	(void) linu;
	if (*st_stack == NULL)
		return;
	while (save != NULL)
	{
		printf("%d\n", save->n);
		save = save->next;
	}
}