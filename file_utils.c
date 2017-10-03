#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

//Done By Adam Slifco

int read_file( char* filename, char **buffer ){

	//find size of file: Provided by Professor Woodring
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//Point the buffer to an allocated space of memory
	*buffer = (char*)malloc(size*sizeof(char));

	//points to the filename
	FILE* file;

	// attempts to read the filename passed into it
	file = fopen(filename, "r");

	//returns error code -1 if open was not successful and prints error message
	if(!file){
	  fprintf(stderr, "ERROR MESSAGE: FILE COULD NOT BE OPENED \n");
	return -1;	
	}

	size_t n = 0;
	int x;
	//temporary string to hold characters from file
	char* endOfString;
	//allocate memory to tempString
	endOfString = (char*)malloc(size*sizeof(char));
	//read characters into temporary string until end of file
	while ((x = fgetc(file)) != EOF){
        	endOfString[n++] = (char) x;
    	}
	//detects the end of string 
	endOfString[n] = '\0';

	//copies the string and pastes it into the buffer
	strcpy(*buffer, endOfString);
	//deallocate memory
	free(endOfString);

	//close the file
	fclose(file);
	//returns the file size 
	return size;
}


int write_file(char* filename, char *buffer, int size){

  	//Points to the file
	FILE *fileOut;

	//create file or overwrite existing file
	fileOut = fopen(filename, "w");

	//loop through buffer and print individual chars to file
	//-2 to compensate for empty space in string
	for(int i = size - 2; i >= 0;  i--){
	  fputc((int) buffer[i], fileOut);
	}

	//close file
	fclose(fileOut);

	return 0;
}
