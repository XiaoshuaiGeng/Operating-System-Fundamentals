#ifndef STDIO_H
#define STDIO_H
#include "string.h"
#define BUFF_SIZE 128

typedef struct {
	int fd;	//file descriptor
	int *ptr //file cursor
	char buf[BUFF_SIZE];	//file buffer
}FILE;


FILE* fopen(const char* filepath, const char* mode){
//INPUT: filepath of the file, open mode
//OUTPUT: return a FILE ptr has the file descriptor of the file

//open the file path using open
//open mode is given by char* mode
//
	File *tmp;
	temp->fd = open(...)
	return tmp
}

fprintf(FILE *fp, char *format,..){
	if(fp not exist){
		return -1;
	}
	if(ptr += strlen(format) < BUFF_SIZE){
		buf = format;
	}else{
		write(1,buf,128)
		ptr = 0;
		memset(buf,'\0',128);
	}
	return strlen(format);
}
