#include <stdio.h>
#include <getopt.h>
#include "../include/endomorph.h"


void main(int argc, char *argv[]) {
	FILE *output_file_pointer;
	char args;

	while((args = getopt(argc, argv, "i:o:")) != -1) {
		switch(args) {
			case 'i':
				writing_to_buffer(optarg);
				reverse_buffers();
				break;
			case 'o':
				output_file_pointer = fopen(optarg, "w");
				write_output(output_file_pointer);
				break;
		}
	}
}