#include <stdio.h>
#include "syscall.h"


int main() {
         int i=0;

	i=spawn("./signal.so");
	printf("./signal.so lance 2: %d\n",i);	 
	while (1) {
	    mlk_wait();
	  }

}
