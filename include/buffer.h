#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#ifndef BUFFER
#define BUFFER		1

int byte_step = 2;

typedef struct byte { 
	struct byte *next;
	char word[];
} byte;

byte *head = NULL; 

byte *byter() { 
	byte *new = malloc(sizeof(*new) + byte_step);
	return new;
}


void show_buffer() { 
	byte *temp = byter();
	temp = head;

	while(temp != NULL) {
		for(int i = 0; i < byte_step; i++) {
			if(temp->word[i] == '\0') {
				break;
			}
			printf("\nByte: %c", temp->word[i]);
		}
		printf("\n");
		temp = temp->next;
	}	
}

bool add_byte(char *string) { 

	byte *new = byter();

	for (int i = 0; i < strlen(string); i++) {
		new->word[i] = string[i];
		new->next = NULL;
	}

	if (head == NULL) {
		head = new;
		return true;
	} else {
		byte *trav = byter();
		trav = head;

		while(trav->next != NULL) {
			trav = trav->next;
		}

		trav->next = new;
		return false;
	}

}



#endif