/*
Does card counting by taking in a 2 char input and adds one of the card is between
2 and 'J; and subtracts one if the card is a face card. The exceptions are if
the card is an 'A' or 2: nothing happens

An 'X' quits the program

Created by Victoria Coleman Feb. 2014
*/


#include <stdio.h>


/* 
   Prompts the user for input and puts the reply in the given buffer.

   User input is truncated to the first two characters.

   prompt: string prompt to display
   card_name: buffer where result is stored
*/
void get_card_name(char *card_name){
	puts("Enter the card_name: ");
	scanf("%2s", card_name);
}

/* 
   Prompts the user for input and puts the reply in the given buffer.

   User input is truncated to the first two characters.

   prompt: string prompt to display
   card_name: buffer where result is stored
*/
void assign_card_value(char *card_name, int *value){
	*value = 0;
	switch(card_name[0]){
		case 'K':
		case 'Q':
		case 'J':
			*value = 10;
			break;
		case 'A':
			*value = 11;
			break;
		case 'X':
			break;
		default:
			*value = atoi(card_name);
			if ((*value < 1) || (*value > 10)) {
				puts("I don't understand that value!");
			}
		}
}

/* 
   Increases the internal count by 1 if a numberd card 
   above 2 or below 10. Decreases internal count if a face
   card besides 'A' or 10

   count: internal count of cards
   val: numeric card value
*/
void increment_count(int *count, int *val){
	if ((*val > 2) && (*val < 10)){
		*count = *count + 1;
	} else if (*val == 10) {
		*count = *count - 1;
	}	
	printf("Current count: %i\n", *count);
}

/* 
   Main code, runs a loop looking for user input until
   a 'X' is typed, which terminates the code. 
*/
int main()
{
	char card_name[3];
	int count = 0;
	while (card_name[0] != 'X'){
		get_card_name(card_name);
		int val = 0;
		assign_card_value(card_name, &val);
		increment_count(&count, &val);
	}
	return 0;
}