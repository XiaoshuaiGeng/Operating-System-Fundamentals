#include "types.h"
#include "stat.h"
#include "user.h"
#include "stdio.h"
#include "fcntl.h"
int main(){
	FILE *fp = fopen("alpha.txt",'w');
	fprintf(fp,"This output is print by fprintf\n");
	//int fd = open("alpha.txt",O_RDWR | O_CREATE | O_WRONLY);
	//This open is for testing only
	//close(fd);
	myprintf("This output is print by myprintf\n");
        flush();
	fclose(fp);
	exit();
}
