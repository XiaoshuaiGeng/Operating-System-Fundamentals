# Bonus assignment

## mutex locks

- kernel level --- {busy waiting
- user level   --- {waiting queue

## Semaphore
- counting semaphore
- binary semaphore

- variable
- two operations P/V (wait/sys)
- possibly a queue

- empty:  block if no spot
- full: block if full

semaphore: rw_mutex controls entry of writer
                    first reader

int r_count: no. of readers
             initialize 0

semaphore r   mutual exclusion
              for 1.count
### Writer
while{
  P(rw_mutex);
  write...
  V(wr_writer);
}

### Reader
while{
  r_count++;
  if(r_count==1){
    P(wr_mutex);
  }
  read...
  r_count--;
  if(r_count==0){
    V(wr_mutex);
  }
}
