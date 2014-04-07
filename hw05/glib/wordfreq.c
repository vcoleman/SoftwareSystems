#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>


void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

void user_func(char *word, uint *count)
  {   

  	//gchar *words = (gchar)words ;
    //gint *count = (gint*) count ;
    g_print("count: %u    word : %s\n", *count, word) ;
  }

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
        char str[256];
        //gint *word_number = g_new(int,1);

        GHashTable *hashTable = g_hash_table_new(g_int_hash, g_int_equal);

        while ((c =fgetc(input_file)) != EOF )
        {

            //if it's an alpha, convert it to lower case
            if (isalpha(c))
            {
                found_word = 1;
                c = tolower(c);
                append(str, c);
            }
            else {
                if (found_word & c == ' ' | c == '\n') { /////////////wahoooo!
                    gchar* g_string_new = g_strdup(str);
                    gint *word_number = g_new0(int,1);
                    
                    word_number = g_hash_table_lookup(hashTable, g_string_new);

                    if (word_number != NULL){
                    	gint *one = g_new(int,1);
                    	*one = 1;
                        gint *word_number_new = g_new(int,1);
                        *word_number_new = (*word_number + *one);

                        //g_print("word_numer: %d \n", *word_number);

                    	g_hash_table_insert(hashTable, g_string_new, (gpointer *)(word_number_new));
                    	g_free(one);
                        g_free(word_number);

                    }
                    else{
                    	gint *one = g_new(int,1);
                    	*one = 1;
                    	g_hash_table_insert(hashTable, g_string_new, (gpointer *)one);
                    }

                    found_word=0;
                    str[0] = '\0';
                }
            }

        }
 
  		g_hash_table_foreach (hashTable, (GHFunc)user_func, g_string_new) ;  
    }

    fclose(input_file);

    printf("\n");

    return 0;
}