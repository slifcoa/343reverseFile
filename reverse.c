#include <stdlib.h>
#include <stdio.h>
#include "file_utils.h"

//Done by Adam Slifco'

int main(int argc, char** args){

       	//read file
	char* fileIn = args[1];
	//write file
	char* fileOut = args[2];
	//char pointer for the buffer
	char* buffer;
	
	//check to see that 3 arguments were passed into the main
	if(argc != 3){
	  fprintf( stderr, "ERROR MESSAGE: INVALID COMMAND \n");
	  return -1;
	}

	//assign the size of the file by calling the read file method
	int fileSize = read_file(fileIn, &buffer);

	//Cancel Program if the read file was invalid
	if(fileSize == -1){
	  return -1;  
	}

	//overrite and existing file or create a new one from scratch
	write_file(fileOut, buffer,fileSize);

	//deallocate memory
	free(buffer);

	return 0;
}
