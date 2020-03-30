#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <string.h>

int main()
{

    if (fork() == 0)
    {
        execle( "/bin/ls", "ls", "-l", "/usr/include", 0 );

        if (fork() == 0)
        {
            execl( "/bin/ls", "ls", "-l", "/usr/include", 0 );

            if (fork() == 0)
            {
                execvp( "/bin/ls", 0 );
            }
            else
            {

                execvpe( "/bin/ls", "ls", "-l", "/usr/include", 0 );
            }
        }
        else
        {

            execv( "/bin/ls", 0 );
        }
    }
    else
    {
        execlp( "/bin/ls", "ls", "-l", "/usr/include", 0 );
    }

    return 0;
}