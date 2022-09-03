#include "monty.h"

/**
 * main - Start in main, always
 * @argc: The number of arguments passed to program
 * @argv: The strings passed to the program
 * Return: 1 if reaches end of the file, exit with EXIT_FAILURE
 * if any opcode fails
 **/
int main(int argc, char *argv[]){
	FILE *file;
	char *line = NULL, *command;
	size_t size=0, line_num = 1;
	stack_t *stack = NULL;
	ssize_t read = 0;
	if (argc != 2){
		printf("usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL){
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &size, file);
	while (read != -1){
		command = find_command(line, &stack, line_num);
		if (strcmp(command, "nop"))
			check_codes(command, &stack, line_num);
		if (ret_and_q.opcode_return != 0){
			free_and_exit(line, file, stack);
		}
		line_num++;
		read = getline(&line, &size, file);
	}
	free_stack(stack);
	free(line);
	fclose(file);
	return (0);
}

/**
 * find_command - Parse the line to find the given opcode
 * @line: Line grabbed from monty file
 * @stack: Double pointer pointing to top of stack/queue
 * @line_num: Line number in the file the line was on
 * Return: The name of the command found
 **/
char *find_command(char *line, stack_t **stack, unsigned int line_num){
	char *command, *push_arg;
	command = strtok(line, "\n\t\r ");
	if (command == NULL || command[0] == '#')
		command = "nop";
	if (strcmp(command, "push") == 0){
		command = "nop";
		push_arg = strtok(NULL, "\n \t\r");
		if (int_check(push_arg) == 0){
			if (ret_and_q.queue_val == 0)
				add_node(stack, atoi(push_arg));
			else
				add_node_end(stack, atoi(push_arg));
		}
		else{
			printf("L%u: usage: push integer\n", line_num);
			ret_and_q.opcode_return = 1;
			return (command);
		}
	}
	return (command);
}

/**
 * int_check - Check if the given argument to push is a valid integer or not
 * @push_arg: The string argument found after the push opcode
 * Return: 1 if it's not a valid integer, 0 if it is
 **/
int int_check(char *push_arg){
	int i;
	if (push_arg == NULL)
		return (1);
	i = 0;
	while (push_arg[i] != '\0'){
		if (isalpha(push_arg[i]))
			return (1);
		i++;
	}
	return (0);
}