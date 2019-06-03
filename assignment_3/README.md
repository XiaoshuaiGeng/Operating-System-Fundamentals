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
