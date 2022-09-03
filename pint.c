#include "monty.h"
/**
 * pint - Print the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_num: The line of the file the command was found
 **/
void pint(stack_t **stack, unsigned int line_num){
	if (*stack == NULL){
		printf("L%u: can't pint, stack empty\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1){
		printf("%d\n", (*stack)->n);
	}
}