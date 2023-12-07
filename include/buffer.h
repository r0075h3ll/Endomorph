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

byte *tail = NULL; 

static inline byte *byter() { 
	byte *new = malloc(sizeof(*new) + byte_step);
	return new;
}


static inline void show_buffer() { 
	byte *temp = byter();
	temp = tail;

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

static inline void add_byte(char *string) { 

	byte *new = byter();

	for (int i = 0; i < strlen(string); i++) {
		new->word[i] = string[i];
	}

	new->next = tail;
	tail = new;

}



#endif