#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

#ifndef ENDOMORPH
#define ENDOMORPH	1

int whitespace = 0;
int no_of_bytes = 0;
int current_line_number;

static inline void write_output(FILE *file) { 
	byte *temp_tail;

	for(int i = 0; i <= no_of_lines; i++) {
		temp_tail = memory[i];

		while (temp_tail != NULL) {
			for (int j = 0; j < byte_step; j++) {
				fprintf(file, "%c", temp_tail->word[j]); 
			}

			if(whitespace) {
				fprintf(file, " ");
			}

			temp_tail = temp_tail->next;
		}
		
		fprintf(file, "\n");
	}

}

static inline void writing_to_buffer(char *path) { 

	int index, offset = 0;
	char ch;
	char *file_content;

	FILE *file = fopen(path, "r");
	init_table(file);
	rewind(file); 


	while(fgetc(file) != EOF) { 
		no_of_bytes++;
	}


	file_content = (char *)malloc(no_of_bytes * sizeof(char)); 
	rewind(file);

	while((ch = fgetc(file)) != EOF) { 

		if(ch == ' ') {
			ch = fgetc(file);
		}

		file_content[index++] = ch;
	}

	while(file_content[offset] != '\0') { 
		char *string = (char *)malloc(byte_step);

		if(file_content[offset] == '\n') {
			create_entry(current_line_number);
			tail = NULL;
			current_line_number++;
			offset++;
			continue;
		}

		for(int i = 0; i < byte_step; i++) {
			string[i] = file_content[offset++];
		}

		add_byte(string);
	}


}

#endif