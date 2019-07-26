change ps() showing the priority of the processes
set_priority
userprog
priority scheduling
no starvation

readme.txt
	chagne of priority
	how to implement set priority
	starvation?
	how to test the program

Notes about this assignment:

- modify ps in Assignment #4 to include the display of priority values
- shell command to set priority
- user program (s) for testing
- the priority scheduling is non-preemptive
- no starvation
- (optional) special strategy to schedule processes with same priority
- readme file: up to one page of a plain-text file to explain
- range of your priority values
- how to set priority in your program
- how starvation is avoided
- how to test your solution
- maximum of 15 files can be submitted - penalty for unnecessary modification or addition to xv6
- no penalty for no use or improper use of locks 
- not required to modify sh.c


1. How to set priority?
	- setprior [pid] [priority] to set the process priority
	- e.g. setprior 2 5 means to set the process with pid 2's priority to 5 

2. How starvation is avoid?
	- Schedular has a variable called lastTick which record the CPU ticks
	- When there is 500 ticks passed, increase the priority for the
	  process that has lowest priority
	- However, no strategy to schedule process with the same priority

3. How to test the solution?
	- In shell, type "test &" for 3 or more times to let test running
	  in the background
	
	- In shell, according to processes' pid, use "setprior" to set priority for
	  each process
	
	- In shell, keep typing "ps" to keep track of the RUNNING and
	  RUNNABLE processes, the processes priority will change after
	  500 CPU ticks
