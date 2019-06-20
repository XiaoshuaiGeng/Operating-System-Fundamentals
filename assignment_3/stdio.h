#ifndef STDIO_H
#define STDIO_H
#include "string.h"
#define BUFF_SIZE 128

typedef struct {
	int fd;	//file descriptor
	int position //(file cursor) indicating the current file cursor position
	char buf[BUFF_SIZE];	//file buffer
	int buf_pos;//indicating the current buffer position
}FILE;


//INPUT: filepath of the file, open mode
//OUTPUT: return a FILE ptr has the file descriptor of the file

//open the file path using open
//open mode is given by char* mode
FILE* fopen(const char* filepath, const char mode);
/*
	File *tmp;
	tmp->position = 0;
	tmp->fd = open(...)
	return tmp;
*/

void fclose(FILE *fp);

void fprintf(FILE *fp, char *format);
/*	if(fp not exist){
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
*/

void myprintf(const char* s);
