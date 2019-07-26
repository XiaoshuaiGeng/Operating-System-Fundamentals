Xiaoshuai Geng 104845608

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
