/*Hw05

Created by: Victoria Coleman

*/

#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>


/*
Appends a character to the end of a character array
*/
void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

/*
Prints the valules and keys of a GHashTable (helper function)
*/  
void print_key_value(char *word, uint *count)
  {   
    g_print("count: %u    word : %s\n", *count, word) ;
  }

/*
Prints the valules and keys of a GHashTable
*/  
void print_hash_table(GHashTable *hashTable){
    g_hash_table_foreach (hashTable, (GHFunc)print_key_value, NULL) ;  
}

/*Inserts a new value in the hashtable initialized with a frequency of one,
or increments the frequency of the value if already in the table

GHashTable hashTable: hashtable of key: word (GString), value: freq (gint)
*/
void add_to_hash_table(GHashTable *hashTable,gchar* g_string_new){

    gint *word_number = g_new0(int,1);

    word_number = g_hash_table_lookup(hashTable, g_string_new);

    if (word_number != NULL){     //if key exists in hash table

        gint *word_number_new = g_new(int,1);

        *word_number_new = (*word_number + 1); //Increment word_number
        g_hash_table_insert(hashTable, g_string_new, (gpointer *)(word_number_new));
        
        g_free(word_number);

    }
    else{ //put key in hash table and make value 1
        gint *one = g_new(int,1);
        *one = 1;
        g_hash_table_insert(hashTable, g_string_new, (gpointer *)one);
    }
}

/* Creates a GHashTable of all the words in the "AfricanMillionare.txt" file
and prints out the words and their frequencies
*/

int main ()
{
    int c;
    FILE *input_file;

    input_file = fopen("AfricanMillionaire.txt", "r");

    if (input_file == 0)
    {
        //fopen returns 0, the NULL pointer, on failure
        perror("Canot open input file\n");
        exit(-1);
    }

    else
    {
        int found_word = 0;
        char word_buffer[256];  //word string

        //Create hashtable to store word & frequency
        GHashTable *hashTable = g_hash_table_new(g_int_hash, g_int_equal);

        //If tile does not error
        while ((c =fgetc(input_file)) != EOF )
        {
            //if it's an alpha, convert it to lower case and add to word buffer
            if (isalpha(c))
            {
                found_word = 1;
                c = tolower(c);
                append(word_buffer, c);
            }
            else {
                //Check to see if it is a new word
                if (found_word & (c == ' ' | c == '\n')) {

                    gchar* g_string_new = g_strdup(word_buffer);

                    add_to_hash_table(hashTable, g_string_new);

                    found_word=0;
                    word_buffer[0] = '\0';  //clears word buffer for new word 
                }
            }
        }
        print_hash_table(hashTable);
    }
    fclose(input_file);
}