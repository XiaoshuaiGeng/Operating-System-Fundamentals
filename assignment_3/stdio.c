#include "stdio.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

FILE* stdout;
static int stdout_isopen=0;

void initstdio()
{
	if(!stdout_isopen)
	{
		stdout=(FILE*)malloc(sizeof(FILE));
		stdout->fd = 1;
	        stdout_isopen = 1;
	}
}


FILE* fopen(const char* filepath,const char mode){
	FILE *tmp = (FILE*)malloc(sizeof(FILE));
	tmp->pos = 0;	//initialize file cursor
	tmp->buf_pos = 0;	//initialize buffer cursor
	//memset(tmp->buf,0,128);
	//initialize all the elements in buffer to null
	if(mode =='r')
		tmp->fd = open(filepath,O_RDONLY);
	if(mode == 'w')
		tmp->fd = open(filepath,O_RDWR | O_CREATE | O_WRONLY);
	return tmp;
}

void fclose(FILE *fp){
	write(fp->fd,fp->buf,fp->buf_pos);	//flush the buffer to ven file descriptor
	//write(1,fp->buf,BUFF_SIZE);
	close(fp->fd);	//close the file descriptor
	free(fp);	//free the raw disk space that the FILE element allocated
}

//clear the FILE buffer and output to STDOUT
void flush(){
	write(stdout->fd,stdout->buf,stdout->buf_pos);// write the buffer to file
	memset(stdout->buf,0,BUFF_SIZE);	//reinitialize the buffer
	stdout->buf_pos = 0;

}
//put one character into buffer
static void putc1(FILE* fp, char c){
	if(fp->buf_pos == BUFF_SIZE){
		write(fp->fd,fp->buf,BUFF_SIZE);// write the buffer to file
		memset(fp->buf,0,BUFF_SIZE);	//reinitialize the buffer
		fp->buf_pos = 0;
	}
	fp->buf[fp->buf_pos++] = c;
}


//print the integer in ASCII format
static void printint(FILE* fp, int xx, int base, int sgn){
	static char digits[] = "0123456789ABCDEF";
	char buf[16];
	int i,neg;
	uint x;

	neg = 0;
	if(sgn && xx < 0){
    		neg = 1;
    		x = -xx;
  	}else{
    		x = xx;
  	}

	i = 0;
  	do{
    		buf[i++] = digits[x % base];
	}while((x /= base) != 0);
  	if(neg)
    		buf[i++] = '-';

	while(--i >= 0)
    		putc1(fp, buf[i]);
}

//print the output to given stream
void fprintf(FILE* fp, const char* fmt, ...){
	char *s;
  	int c, i, state;
  	uint *ap;

	state = 0;
  	ap = (uint*)(void*)&fmt + 1;
  	for(i = 0; fmt[i]; i++){
    		c = fmt[i] & 0xff;
    		if(state == 0){
      			if(c == '%'){
        			state = '%';
      			}else{
        			putc1(fp, c);
      			}
    		} else if(state == '%'){
			if(c == 'd'){
        			printint(fp, *ap, 10, 1);
        			ap++;
      			} else if(c == 'x' || c == 'p'){
			        printint(fp, *ap, 16, 0);
			        ap++;
		      	} else if(c == 's'){
			        s = (char*)*ap;
			        ap++;
			        if(s == 0)
				        s = "(null)";
			        while(*s != 0){
			        	putc1(fp, *s);
				        s++;
        			}
      			} else if(c == 'c'){
        			putc1(fp, *ap);
        			ap++;
      			} else if(c == '%'){
        			putc1(fp, c);
      			} else {
        		// Unknown % sequence.  Print it to draw attention.
        			putc1(fp, '%');
			        putc1(fp, c);
      			}
      			state = 0;
    		}
  	}
}

//print the received input to STDOUT
void myprintf(const char* fmt, ...){

   initstdio();
   	char *s;
  	int c, i, state;
  	uint *ap;

	state = 0;
  	ap = (uint*)(void*)&fmt + 1;
  	for(i = 0; fmt[i]; i++){
    		c = fmt[i] & 0xff;
    		if(state == 0){
      			if(c == '%'){
        			state = '%';
      			}else{
        			putc1(stdout, c);
      			}
    		} else if(state == '%'){
			if(c == 'd'){
        			printint(stdout, *ap, 10, 1);
        			ap++;
      			} else if(c == 'x' || c == 'p'){
			        printint(stdout, *ap, 16, 0);
			        ap++;
		      	} else if(c == 's'){
			        s = (char*)*ap;
			        ap++;
			        if(s == 0)
				        s = "(null)";
			        while(*s != 0){
			        	putc1(stdout, *s);
				        s++;
        			}
      			} else if(c == 'c'){
        			putc1(stdout, *ap);
        			ap++;
      			} else if(c == '%'){
        			putc1(stdout, c);
      			} else {
        		// Unknown % sequence.  Print it to draw attention.
        			putc1(stdout, '%');
			        putc1(stdout, c);
      			}
      			state = 0;
    		}
  	}


}







