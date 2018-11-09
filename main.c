# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

static void sighandler(int signo){
  if (signo == SIGUSR1){
    printf("No u \n");
  }
  else if (signo == SIGINT){
    printf("Still no u\n");
    exit(0);
  }
}


int main(int argc, char const *argv[]) {
  signal(SIGUSR1, sighandler);
  signal(SIGINT, sighandler);
  while(1){
    printf("Current process: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
