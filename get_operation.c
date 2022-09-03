#include "monty.h"

/**
 * get_operation -  checks opcode and returns the correct function
 * @str: the opcode
 * Return: returns a function, or NULL on failure
 */
instruct_func get_operation(char *str){
	int i = 0;
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0){
		i++;
	}
	return (instruct[i].f);
}

/**
 * check_string - checks if a string is a number
 * @str: string being passed
 *
 * Return: returns 1 if string is a number, 0 otherwise
 */
int check_string(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}