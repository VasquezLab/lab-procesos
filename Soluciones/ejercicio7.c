#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
int rc = fork();


 if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("Soy el hijo de (pid:%d)\n", (int) getpid());
        fclose(stdout);
        printf("Soy el hijo 2(pid:%d)\n", (int) getpid());
    } else {
        // parent goes down this path (original process)
        printf("Soy el padre de %d (pid:%d)\n",
        rc, (int) getpid());

    }
 return 0;
}