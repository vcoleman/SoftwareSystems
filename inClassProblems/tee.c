/* implementation of tee. reads from standard input and write to standard output and files
tee [OPTION (-a append)] [FILENAME] */




#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//WRITE TO FILE\\
main(int argc, char *argv[]){

	char ch;

	while ((ch = getopt(argc, argv, "ae:")) != EOF){
		switch (ch):
			case 'a': 
				printf("arg %c", 'a')

	}

	FILE *f = fopen("file.txt", "w");

	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

	/* print some text */
	const char *text = "Write this to the file";
	fprintf(f, "Some text: %s\n", text);

	/* print integers and floats */
	int i = 1;
	float py = 3.1415927;
	fprintf(f, "Integer: %d, float: %f\n", i, py);

	/* printing single chatacters */
	char c = 'A';
	fprintf(f, "A character: %c\n", c);

	fclose(f);
}