#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

#ifndef ENDOMORPH
#define ENDOMORPH	1

int whitespace = 0;
int no_of_bytes = 0;
int current_line_number;
byte *rev_head;

void reverse_buffers() { 
	for(int i = 0; i < no_of_lines; i++) {
		rev_head = memory[i];

	    byte *temp = rev_head->next;
	    rev_head->next = NULL;
	    byte *next = NULL;

	    while (temp != NULL) {
	        next = temp->next;
	        temp->next = rev_head;
	        rev_head = temp;
	        temp = next;

	    }
	    memory[i] = rev_head;
	}
}

void write_output(FILE *file) { 
	for(int i = 0; i <= no_of_lines; i++) {
		rev_head = memory[i];

		while (rev_head != NULL) {
			for (int j = 0; j < byte_step; j++) {
				fprintf(file, "%c", rev_head->word[j]); 
			}

			if(whitespace) {
				fprintf(file, " ");
			}

			rev_head = rev_head->next;
		}
		
		fprintf(file, "\n");
	}

}

void writing_to_buffer(char *path) { 

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
			head = NULL;
			current_line_number++;
			offset++;
			continue;
		}

		for(int i = 0; i < byte_step; i++) {
			string[i] = file_content[offset++];
		}

		if(add_byte(string)) { 
			create_entry(current_line_number);
		}

	}


}

#endif