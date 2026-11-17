#include "types.h"
#include "user.h"

void
work(void)
{
  volatile int x = 0;
  for(int i = 0; i < 50000000; i++){
    x += i;
  }
}

int
main(void)
{
  int priorities[4] = {1, 5, 10, 15};

  for(int i = 0; i < 4; i++){
    int pid = fork();
    
    if(pid == 0){
    	work();
    	printf(1, "Child PID %d (priority %d) FINISHED\n", getpid(), priorities[i]);
    	exit();
    } 
    else{
      set_priority(pid, priorities[i]);
    }
  }
  
  for(int i = 0; i < 4; i++){
    wait();
  }

  exit();
}
