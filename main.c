#include "monty.h"

/**
  * main - start the monty interpreter
  * @argc: argument count
  * @argv: argument vector
  * Return: 0 in success exit or different to 0 in unsuccess
  */
int main(int argc, char **argv){
	if (argc == 2)
		monty(argv);
	else{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
  * monty - Monty Interpreter
  * @av: argument vector
  * Return: nothing
  */
void monty(char **argv){
	char *file = argv[1], *buffer = NULL, **tokens = NULL;
	size_t len = 0, linu = 1;
	ssize_t r_line;
	stack_t *st_stack = NULL;
	FILE *open_f;
	open_f = fopen(file, "r");
	if (open_f == NULL){
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	for (linu = 1; (r_line = getline(&buffer, &len, open_f)) != -1; linu++){
		tokenize(&buffer, &tokens, r_line);
		if (tokens != NULL)
			opcode_choose(&st_stack, &tokens, linu);
		free_tokens(&tokens);
	}
	fclose(open_f);
	if (buffer != NULL)
		free(buffer);
	free_stack(st_stack);
}

/**
  * tokenize - start the monty interpreter
  * @buffer: buffer where will store the data line
  * @tokens: where the opcode will be stored
  * @r_line: number of characters read it
  * Return: nothing
  */
void tokenize(char **buffer, char ***tokens, ssize_t r_line){
	size_t i, j, number;
	int f;
	char *token = NULL, *delim = " \n\t";

	if (r_line > 0){
		for (i = 0; (*buffer)[i] == ' ' || (*buffer)[i] == '\t'; i++){
			if ((*buffer)[i + 1] == '\n')
				return;
		}
	}
	if (**buffer != '\n'){
		for (f = 0; (*buffer)[f] != '\0'; i++)
			;
		(*buffer)[f - 1] = '\0';	
        token = strtok(*buffer, delim);
        if (strcmp(token, "push") == 0)
            number = 3;
        else
            number = 2;
        *tokens = malloc(sizeof(char *) * number);
        for (j = 0; token != NULL && j <= number - 2; j++){
            (*tokens)[j] = token;
            token = strtok(NULL, delim);
        }
        (*tokens)[j] = NULL;
	}
}