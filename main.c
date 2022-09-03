#include "monty.h"

/**
  * main - an interpreter for Monty ByteCodes filesstart the monty interpreter
  * @argc: argument count
  * @argv: argument vector
  * Return: 0 Success
  */
int main(int argc, char **argv){
    stack_t *stack = NULL;
    stack_t *tmp = NULL;
    instruct_func operation;
    FILE *open_file;
    char *file = argv[0], *line = NULL, *op_code = NULL;
    size_t size = 0;
    ssize_t read = 0;
    int count = 1;

    if (argc != 2){
        printf("USAGE: monty file\n");
        error_exit(&stack);
    }
    open_file = fopen(file, "r");
    if (open_file == NULL){
        printf("Error: Can't open file %s\n", file);
		error_exit(stack);
	}
    read = getline(&line, size, file);
    while (read != -1){
        op_code = strtok(line, "\n\t");
        if (op_code == NULL || op_code[0] == '#'){
            count++;
            continue;
        }
        operation = get_operation(op_code);
        if(operation == NULL){
            printf("L%d unknown instruction %s\n", count, op_code);
            error_exit(stack);
        }
        operation(stack, count);
        count++;
    }
    free(line);
    if ((fclose(file)) == -1) 
        return(EXIT_FAILURE);
    free_stack(stack);    
    return(EXIT_SUCCESS);
}

/**
 * error_exit - frees the stack and exits due to error
 * @stack: pointer to the head of the stack
 */
void error_exit(stack_t **stack){
	if (*stack)
        free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - free a list
 * @head: pointer to first node
 */
void free_stack(stack_t *stack){
	stack_t *tmp;
	while (stack != NULL){
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}