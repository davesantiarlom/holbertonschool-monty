#include "monty.h"
/**
 * push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int push_arg;

	push_arg = 0;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		error_exit(stack);
	}

	arg = strtok(NULL, "\n ");
	if (check_string(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
	{
		printf("L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	if (sq_flag == 1)
	{
		add_node_end(stack, push_arg);
	}

	if (sq_flag == 0)
	{
		add_node(stack, push_arg);
	}

}