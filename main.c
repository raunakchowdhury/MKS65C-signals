# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <string.h>

static void sighandler(int signo){
  if (signo == SIGUSR1){
    printf("Parent process: %d \n", getppid());
  }
  else if (signo == SIGINT){
    int fd = open("error.txt", O_CREAT | O_WRONLY | O_APPEND);
    char * string = "SIGINT received. Program terminated\n";
    write(fd, string, strlen(string));
    close(fd);
    printf("See error.txt for details.\n");
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
