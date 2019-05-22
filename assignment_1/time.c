#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){
	int startTime = uptime();
	int pid = fork();
	if(pid < 0){
		printf(1,"Fork error\n");
		exit();
	} 
	if(pid > 0){		
		//parent process has to wait child process to finish
		wait();
	}else{	
		//this is child process
		/*
			Child process creates a temporary string array to hold the
			arguments passed from argv[1] to the end of the argument
			
			The temporary array has the maximum size of 5 
		*/
		char *temp[5];
		int i;

		//copy the arguments from start to end
		for(i = 1; i < argc; i++){
			temp[i - 1] = argv[i];
		}
		temp[i - 1] = "\0";	//put a null pointer at the end of the array
		exec(temp[0],temp);	
		exit();	
	}
	int endTime = uptime();
	printf(1,"Time used: %d time unit\n", endTime-startTime);
	exit();
}
