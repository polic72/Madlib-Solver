#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

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
//    LinkedList *type_list = ll_create();
//    LinkedList *word_list = ll_create();
    LinkedList *TypeWord_list = ll_create();

    char line_buffer[BUFFER_SIZE];

    char type_buffer[BUFFER_SIZE];
    char word_buffer[BUFFER_SIZE];

    while (fgets(line_buffer, BUFFER_SIZE, words_file))
    {
        unsigned int i;
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

            return 1;
        }


        //i++;
        //strncpy(word_buffer, line_buffer + i, strlen(line_buffer + i) - 1);    //The " - 1" is just to get rid of the newline char.

        unsigned int colon_pos = i;
        for (++i; i < BUFFER_SIZE; ++i)
        {
            if (line_buffer[i] == '\r' || line_buffer[i] == '\n')
            {
                strncpy(word_buffer, line_buffer + colon_pos + 1, i - colon_pos - 1);
                break;
            }
        }


        //printf("line_buffer: \"%s\", type_buffer: \"%s\", word_buffer: \"%s\"\n", line_buffer, type_buffer, word_buffer);
        //printf("type_buffer: \"%s\", word_buffer: \"%s\"\n", type_buffer, word_buffer);


        unsigned int type_len = colon_pos;
        unsigned int word_len = strlen(word_buffer);


        char *temp_obj = malloc(type_len);
        memcpy(temp_obj, type_buffer, type_len);


        bool found = false;

        LL_node *current_node = TypeWord_list->start;

        for (i = 0; i < TypeWord_list->size; ++i)
        {
            if (strcmp(temp_obj, ((TypeWords*)current_node->data)->type) == 0)
            {
                found = true;
                break;
            }

            current_node = current_node->right;
        }


        if (!found)
        {
            TypeWords *new_node = malloc(sizeof(TypeWords));
            new_node->type = temp_obj;    //This will be a memory leak without a dispose method. We'll get to it...
            new_node->words = malloc(sizeof(LinkedList));

            ll_add_end(TypeWord_list, new_node);
            current_node = TypeWord_list->end;
        }


        char *temp_obj2 = malloc(word_len);    //This is ok because we no longer own the memory.
        memcpy(temp_obj2, word_buffer, word_len);

        ll_add_end(((TypeWords*)current_node->data)->words, temp_obj2);


        memset(type_buffer, 0, BUFFER_SIZE);
        memset(word_buffer, 0, BUFFER_SIZE);
    }


    srand(time(NULL));

    //char word_buffer[BUFFER_SIZE];
    char edited_line_buffer[BUFFER_SIZE * 2];


    while (fgets(line_buffer, BUFFER_SIZE, madlib_file))
    {
        char replace_key[256];
        
        for (unsigned int i = 0; i < BUFFER_SIZE; ++i)
        {
            if (i == BUFFER_SIZE - 1 && line_buffer[i] != '\0')
            {
                fprintf(stderr, "The line (%s) was either malformed or the BUFFER_SIZE (%d) was too small for the type.\n", line_buffer, BUFFER_SIZE);

                return 2;
            }


            if (line_buffer[i] == '\0')
            {
                break;
            }


            if (line_buffer[i] == '[')
            {
                unsigned int first_wordChar_index = i;

                for (i++; i < BUFFER_SIZE; ++i)
                {
                    if (i == BUFFER_SIZE - 1 && line_buffer[i] != '\0')
                    {
                        fprintf(stderr, "The line (%s) was either malformed or the BUFFER_SIZE (%d) was too small for the type.\n", 
                            line_buffer, BUFFER_SIZE);

                        return 2;
                    }


                    if (line_buffer[i] == '\0')
                    {
                        break;
                    }

                    
                    if (line_buffer[i] == ']')
                    {
                        replace_key[i - first_wordChar_index] = '\0';

                        break;
                    }

                    replace_key[i - first_wordChar_index] = line_buffer[i];
                }
            }


            LL_node *current_node = TypeWord_list->start;

            while (current_node != NULL)
            {
                TypeWords *type_words = current_node->data;

                if (strcmp(type_words->type, replace_key))
                {
                    //Place a random word from the node here.
                }
            }
        }
    }


    //Just printing out what we have now.
    LL_node *current_node = TypeWord_list->start;

    for (unsigned int i = 0; i < TypeWord_list->size; ++i)
    {
        printf("%s:\n", ((TypeWords*)current_node->data)->type);


        LL_node *inner_node = ((TypeWords*)current_node->data)->words->start;

        for (unsigned int j = 0; j < ((TypeWords*)current_node->data)->words->size; ++j)
        {
            printf("\t%s\n", inner_node->data);

            inner_node = inner_node->right;
        }

        current_node = current_node->right;
    }


    fclose(words_file);
    fclose(madlib_file);

    return 0;
}
