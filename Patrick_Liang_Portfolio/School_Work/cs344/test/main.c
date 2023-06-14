#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int swap(int val1, int *val2){
  int temp = val1;
  val1 = *val2;
  *val2 = temp;
  return val1;
}

int main(void) {
pid_t spawnpid = fork();
  switch (spawnpid){
    case -1: exit(1); break;
    case 0: break;
    default: break;
  }
  printf("XYZZY\n");
}