# Assignment 4
<h3>Notes abount this assignment: </h3>
<ul>
  <li>consider only those processes in SLEEPING, RUNNING, or RUNNABLE state</li>
  <li>process info. includes process id, process name, process state, and parent name</li>
  <li>use (init) for the parent name of the init process</li>
  <li>for total number of processes, count only those in SLEEPING, RUNNING, and RUNNABLE states</li>
  <li>cpu info. should be either idle or the name of the current process</li>
  <li>penalty for unnecessary modification or addition to xv6</li>
  <li>no penalty for no use or improper use of locks</li>
</ul>
<pre>
To add a system call that can be called in xv6's shell, you should so something with the five files

  <b>sysproc.c</b> add the real implementation of your method here
  <b>syscall.h</b> define the position of the system call vector that connect to your implementation
  <b>user.h</b> define the function that can be called through the shell
  <b>syscall.c</b> external define the function that connect the shell and the kernel, use the position defined in syscall.h to add the function to the system call vector
  <b>usys.S</b> use the macro to define connect the call of user to the system call function

  <b>defs.h</b> add a forward declaration for your new system call

  <b>sysfunc.h</b> add the new system call handler into this file too like "int sys_newsystemcall(void)"
</pre>
