#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define MODE  0666
#define BUF_SIZE 8192

int main(int argc, char * argv[]){

        int source, destination, in, out;
        char buf[BUF_SIZE];

        if(argc!=3){
                printf("Usage: mycp src target\n");
                _exit(1);
        }

        printf("mycp %s %s\n", argv[1], argv[2]);

        // 1. Make system call open to open source file to read
        source = open(argv[1], O_RDONLY);
        if(source < 0){ exit(2); }

        // 2. Open argv[2], target file to write
        destination = creat(argv[2], MODE);
        if(destination < 0){ exit(3); }

        // 3. Loop to read chars from source file and write
        // into target file
        while(1){
                in = read(source, buf, BUF_SIZE);
                if(in <=0){ break; }

                out = write(destination, buf, in);
                if(out <= 0){ break; }
        }
        // 4. Close both files
        close(source);
        close(destination);
        exit(0);
