/*
Punto 1 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int x = 100;
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d) y x al inicio:%d\n", (int) getpid(),x);
        x=x+1;
        printf("x al aumentarse en 1 en proceso hijo: %d",x);
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
           rc, (int) getpid());
       x=x+2;
        printf("x al aumentarse en 2 en proceso padre: %d",x);    
    }
    return 0;
}