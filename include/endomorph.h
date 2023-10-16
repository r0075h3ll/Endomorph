#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

#ifndef ENDOMORPH
#define ENDOMORPH	1

int current_line_number;

void reverse_buffers() {
	for(int i = 0; i < no_of_lines; i++) {
		head = memory[i];

	    byte *temp = head->next;
	    head->next = NULL;
	    byte *next = NULL;

	    while (temp != NULL) {
	        next = temp->next;
	        temp->next = head;
	        head = temp;
	        temp = next;

	    }
	    memory[i] = head;
	}
}

void write_output(FILE *file) {
	for(int i = 0; i < no_of_lines; i++) {
		head = memory[i];

		while (head != NULL) {
			fprintf(file, "%c%c ", head->a, head->b);
			head = head->next;
		}
		fprintf(file, "\n");
	}

}

void writing_to_buffer(char *path) {
	init_table(fopen(path, "r"));

	char ch;
	int index = 0;
	int no_of_bytes = 0;
	FILE *file = fopen(path, "r");

	while((fgetc(file)) != EOF) {
		no_of_bytes++;
	}

	char *file_content = (char *)malloc(no_of_bytes * sizeof(char));
	rewind(file);

	for(int i = 0; i < no_of_bytes; i++) {
		file_content[i] = fgetc(file);
	}

	while(file_content[index] != '\0') {
		char *string = (char *)malloc(2);
		char a,b,w_n_eof;

		a = file_content[index++];
		b = file_content[index++];
		w_n_eof = file_content[index++];

		string[0] = a;
		string[1] = b;

		bool header = add_byte(string);

		if (header) {
			create_entry(current_line_number);
		}

		if (w_n_eof == '\n') {
			head = NULL;
			current_line_number++;
		}

	}

}

#endif
