<h3>A3 requirements:</h3>
<ul>
  <li>Define FILE* with fopen(), fclose()</li>
  <li>Implement fprintf() by adding a buffer to printf</li>
  <li>Implement myprintf() which does not require the file descriptor, just simply give the output e.g. myprintf("%s\n",string)</li>
</ul>
<pre>
  1. change MakeFile to include the library
  2. fopen(), fclose(),fprintf(),myprintf() should be in "stdio.c"
  3. A test program mytest.c include "stdio.h"
</pre>

<p>
  <ul><h3>Notes about this assignment:</h3>
  <li>BUFF_SIZE should be defined</li>
  <li>FILE *fopen(const char *path, char mode)</li>
    <ul><li>mode: r for reading, w for writing</li></ul>
  <li>void fclose(FILE *fp)</li>
  <li>void fprintf(FILE* fp, const char* s, …);</li>
  <ul><li>works like the printf(...) implemented in xv6, plus the buffering</li></ul>
  <li>void myprintf(const char* s, …)</li>
  <ul><li>works like your fprintf(...) except that stdout can be omitted</li></ul>
<li>FILE *mystdout should be implicitly opened</li>
You can assume that the user programs always explicitly close all open streams upon termination.
<br>Not allowed to modify any existing xv6 source file except for Makefile.
<br>Submission: stdio.h, stdio.c, userprog.c, Makefile
</p>
