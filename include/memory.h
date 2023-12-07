#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"

#ifndef MEMORY
#define MEMORY	1

int no_of_lines; 
byte **memory; 

static inline void line_calc(FILE *file_pointer) { 
	int newline_count = 0;
	char ch;

	while ((ch = fgetc(file_pointer)) != EOF) {
		if (ch == '\n') {
			newline_count++;
		}
	}

	no_of_lines = newline_count;
}

static inline void init_table(FILE *file_pointer) { 
	line_calc(file_pointer);

	byte *temp = byter();
	memory = malloc((sizeof(&temp) + byte_step) * no_of_lines); 

	for(int i = 0; i <= no_of_lines; i++) {
		memory[i] = NULL;
	}
} 

static inline void display_table() {
	for(int i = 0; i <= no_of_lines; i++) {
		printf("%s\n", memory[i]->word);
	}
}

static inline void create_entry(int current_line_number) {
	int index = current_line_number;

	if (memory[index] == NULL) {
		memory[index] = tail; //Modified
	} else {
		create_entry(current_line_number);
	}
}

#endif