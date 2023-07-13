#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char ** argv ){
    int fd, ch;
    for(int i = 1; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if(fd < 0)
        {
            perror(argv[i]);
            continue;
        }
        while(read(fd, &ch, 1) == 1)
        {
            write(STDOUT_FILENO, &ch,1);
        }
        close(fd);
    }
}