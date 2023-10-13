#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef BUFFER
#define BUFFER		1

typedef struct byte {
	char a;
	char b;
	struct byte *next;

} byte;

byte *head = NULL; 

void show_buffer() { 
	byte *temp = head;

	while(temp != NULL) {
		printf("\nByte: %c%c\n", temp->a,temp->b);
		temp = temp->next;
	}	
}

bool add_byte(char *string) {

	byte *new = (byte *)malloc(sizeof(byte));

	new->a = string[0];
	new->b = string[1];
	new->next = NULL;


	if (head == NULL) {
		head = new;
		return true;
	} else {
		byte *trav = head;

		while(trav->next != NULL) {
			trav = trav->next;
		}

		trav->next = new;
		return false;
	}

}



#endif