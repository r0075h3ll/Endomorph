#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"

#ifndef MEMORY
#define MEMORY	1

int no_of_lines; 
byte **memory;

void line_calc(FILE *file_pointer) { 
	int newline_count = 0;
	char ch;

	while ((ch = fgetc(file_pointer)) != EOF) {
		if (ch == '\n') {
			newline_count++;
		}
	}

	no_of_lines = newline_count;
}

void init_table(FILE *file_pointer) { 
	line_calc(file_pointer);
	memory = (byte **)malloc(no_of_lines * sizeof(byte));

	for(int i = 0; i < no_of_lines; i++) {
		memory[i] = NULL;
	}
} 

void display_table() {
	for(int i = 0; i <= no_of_lines; i++) {
		printf("\n%c%c\n", memory[i]->a, memory[i]->b);
	}
}

void create_entry(int current_line_number) {
	int index = current_line_number;

	if (memory[index] == NULL) {
		memory[index] = head;
	} else {
		create_entry(current_line_number);
	}
}

#endif
