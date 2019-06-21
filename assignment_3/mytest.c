#include "types.h"
#include "stat.h"
#include "user.h"
#include "stdio.h"
#include "fcntl.h"
int main(){
	FILE *fp = fopen("alpha.txt",'w');
	fprintf(fp,"this is a test");
	//int fd = open("alpha",O_CREATE | O_WRONLY);
	//write(fd,"this\n",5);
//	write(1,"this\n",5);
	//close(fd);
	myprintf("goes in");
        flush();
	fclose(fp);
	exit();
}
