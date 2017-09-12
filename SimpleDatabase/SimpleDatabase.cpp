// SimpleDatabase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdbool>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[])
{
	// ok some doesnt work
	InputBuffer* input_buffer = new_input_buffer();

	while (true)
	{
		print_prompt();
		read_input(input_buffer);

		if (strcmp(input_buffer->buffer, ".exit") == 0) {
			exit(EXIT_SUCCESS);
		}
		else {
			printf("Unrecognized command %s. \n", input_buffer->buffer);
		}
	}
    return 0;
}

void print_prompt() {
	printf("db > ");
}


struct InputBuffer_t {
	char* buffer;
	size_t buffer_length;
	size_t input_length; // here must go ssize but doesnt. TODO: fix it
};

typedef InputBuffer_t InputBuffer;

InputBuffer* new_input_buffer() {
	// I doesnt know why, by it works
	// выделяем память ровно под размер буффера
	InputBuffer* input_buffer = (InputBuffer*) malloc(sizeof(InputBuffer));
	input_buffer->buffer = NULL;
	input_buffer->buffer_length = 0;
	input_buffer->input_length = 0;
	return input_buffer;
}

void read_input(InputBuffer* input_buffer) {
	
	// here must be fixed. it is simple getline, but doent work here
	size_t bytes_read = std::getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

	if (bytes_read <= 0) {
		printf("Error reading input");
		exit(EXIT_FAILURE);
	}

	// ignore trailing newline
	input_buffer->input_length = bytes_read - 1;
	input_buffer->buffer[bytes_read - 1] = 0;
}