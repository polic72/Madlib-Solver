#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "linkedlist.h"

#define BUFFER_SIZE 4096


typedef struct TypeWords
{
	char *type;
	LinkedList *words;
}TypeWords;


int main(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "usage: %s [words_file] [madlib_file]\n", argv[0]);

		return -1;
	}

	
	FILE * words_file = fopen(argv[1], "r");

	if (words_file == NULL)
	{
		fprintf(stderr, "The [%s] file failed to open.\n", argv[1]);

		return -2;
	}


	FILE * madlib_file = fopen(argv[2], "r");

	if (madlib_file == NULL)
	{
		fprintf(stderr, "The [%s] file failed to open.\n", argv[2]);

		return -3;
	}


	//Make a list for the TypeWords instead and go from there.
	LinkedList *type_list = ll_create();
	LinkedList *word_list = ll_create();

	char line_buffer[BUFFER_SIZE];

	char type_buffer[BUFFER_SIZE];
	char word_buffer[BUFFER_SIZE];

	while (fgets(line_buffer, BUFFER_SIZE, words_file))
	{
		int i;
		for (i = 0; i < BUFFER_SIZE; ++i)
		{
			if (line_buffer[i] == ':')
			{
				strncpy(type_buffer, line_buffer, i);
				break;
			}
		}

		if (i == BUFFER_SIZE - 1)
		{
			fprintf(stderr, "The line (%s) was either malformed or the BUFFER_SIZE (%d) was too small for the type.\n", line_buffer, BUFFER_SIZE);
		}


		//i++;
		//strncpy(word_buffer, line_buffer + i, strlen(line_buffer + i) - 1);	//The " - 1" is just to get rid of the newline char.

		int colon_pos = i;
		for (++i; i < BUFFER_SIZE; ++i)
		{
			if (line_buffer[i] == '\r' || line_buffer[i] == '\n')
			{
				strncpy(word_buffer, line_buffer + colon_pos + 1, i - colon_pos - 1);
				break;
			}
		}


		//printf("line_buffer: \"%s\", type_buffer: \"%s\", word_buffer: \"%s\"\n", line_buffer, type_buffer, word_buffer);
		printf("type_buffer: \"%s\", word_buffer: \"%s\"\n", type_buffer, word_buffer);


		int type_len = colon_pos - 1;
		int word_len = strlen(word_buffer);


		char *temp_obj = malloc(type_len);
		memcpy(temp_obj, type_buffer, type_len);

		ll_add_end(type_list, temp_obj);


		temp_obj = malloc(word_len);	//This is ok because we no longer own the memory.
		memcpy(temp_obj, word_buffer, word_len);

		ll_add_end(word_list, temp_obj);


		memset(type_buffer, 0, BUFFER_SIZE);
		memset(word_buffer, 0, BUFFER_SIZE);
	}




	fclose(words_file);
	fclose(madlib_file);

	return 0;
}
