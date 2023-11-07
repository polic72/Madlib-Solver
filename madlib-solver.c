#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "linkedlist.h"

#define BUFFER_SIZE 4096


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


	char buffer[BUFFER_SIZE];

	while (fgets(buffer, BUFFER_SIZE, words_file))
	{
		printf("%s", buffer);
	}


	//


	fclose(words_file);
	fclose(madlib_file);

	return 0;
}
