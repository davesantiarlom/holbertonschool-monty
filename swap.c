#include "monty.h"
/**
 * swap - Put the second element on top of the stack, put the top element
 * in the second position
 * @stack: Double pointer to the top of the stack
 * @line_num: The line of the file the command was found
 **/
void swap(stack_t **stack, unsigned int line_num){
	stack_t *walker;
	int tmp;
	walker = *stack;
	if (walker == NULL || walker->next == NULL){
		printf("L%u: can't swap, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1){
		tmp = walker->n;
		walker->n = walker->next->n;
		walker->next->n = tmp;
	}
}