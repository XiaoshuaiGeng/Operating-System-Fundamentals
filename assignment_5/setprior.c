#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"
#include "spinlock.h"
//#include "defs.h"
#include "syscall.h"
#include "user.h"
#include "stdio.h"

int main(int argc,char* argv[]){
	if(argc <= 2){
		printf(1,"Not enough arguments\n");
		exit();
	}
	int pid = atoi(argv[1]);
	int priority = atoi(argv[2]);
	if(priority < 0 || priority > 20){
		printf(1,"Priority out of range");
		exit();
	}
	setprior(pid,priority);
	exit();
}
