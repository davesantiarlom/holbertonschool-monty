#include "monty.h"
/**
 * add - Add the top two values of the stack, store sum in second position,
 * set *stack to second node, and remove top node
 * @stack: Dopule pointer to the top of the stack
 * @line_num: The line the command was found in the monty file
 **/
void add(stack_t **stack, unsigned int line_num){
	stack_t *walker;
	walker = *stack;
	if (walker == NULL || walker->next == NULL){
		printf("L%u: can't add, stack too short\n", line_num);
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1){
		walker->next->n += walker->n;
		pop(stack, line_num);
	}
}

/**
 * add_node - Add a node to the top of the list
 * @stack: Double pointer to the top of the stack
 * @push_value: The value to assign to the new node
 **/
void add_node(stack_t **stack, int push_value){
	stack_t *new_node;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL){
		printf("Error: malloc failed\n");
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1){
		if (*stack != NULL)
			(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->n = push_value;
		new_node->prev = NULL;
		*stack = new_node;
	}
}
/**
 * add_node_end - Add a node at the end of the list
 * @stack: Double pointer to the top of the stack
 * @push_value: The value to assign to the new node
 **/
void add_node_end(stack_t **stack, int push_value){
	stack_t *new_node;
	stack_t *walker;
	walker = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL){
		printf("Error: malloc failed\n");
		ret_and_q.opcode_return = 1;
	}
	if (ret_and_q.opcode_return != 1){
		while (walker != NULL && walker->next != NULL)
			walker = walker->next;
		new_node->n = push_value;
		new_node->next = NULL;
		new_node->prev = walker;
		if (walker != NULL)
			walker->next = new_node;
		else
			*stack = new_node;
	}
}