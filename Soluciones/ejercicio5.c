#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <string.h>

int main()
{
    // if file does not have in directory
    // then file foo.txt is created.
    int fd[2];
    //int fd = open("file.txt", O_RDONLY | O_CREAT);
    char buf1[12] = "hello world";
    fd[0] = open("file.txt", O_RDWR);

    if (fd[0] == -1)
    {
        // print which type of error have in a code
        printf("Error Number\n");
    }

    
        if (fork() == 0)
        {   
            int cpid = wait(NULL); 
            printf("Empezando proceso hijo %d\n", getpid());
            write(fd[0], "Escribiendo desde el hijo\n", strlen("Escribiendo desde el hijo\n"));
        }
        else
        {
            
            printf("Empezando proceso padre %d\n", getpid());

            write(fd[0], "Escribiendo desde el padre\n", strlen("Escribiendo desde el padre\n"));
        }

        close(fd[0]);

    return 0;
}