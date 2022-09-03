#include "monty.h"
/**
  * free_tokens - Free the tokens
  * @tokens: tokens to free
  * Return: nothing
  */
void free_tokens(char ***tokens){
	if (*tokens != NULL){
		free(*tokens);
		*tokens = NULL;
	}
}
/**
  * free_stack - Free the stack
  * @st_stack: Stack to free
  * Return: nothing
  */
void free_stack(stack_t *st_stack){
	stack_t *savepoin;
	if (st_stack != NULL){
		while (st_stack != NULL){
			savepoin = st_stack->next;
			free(st_stack);
			st_stack = savepoin;
		}
	}
}