#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
// try thi too on the coveralls
//from 9506 test git link
void usage(char *prog_name, char *filename){
    printf("Usage: %s <data to add %s>\n", prog_name, filename);
    exit(0);
}

void fatal(char *);
void *ec_malloc(unsigned int);

int main(int argc, char *argv[]){
    int fd;
    char *buffer, *datafile;


    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);
    strcpy(datafile, "mynote.txt");
    if (argc<2)
       usage(argv[0],datafile);
    strcpy(buffer, argv[1]);
    strncat(buffer, "\n", 1);
    printf("[DEBUG] buffer  @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile  @ %p: \'%s\'\n", datafile, datafile);

    // open file

    fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
    if (fd == -1)
        fatal("in main() while opening file");
    printf("[DEBUG] file descriptor is %d\n", fd);
    //
    //Write data to file
    if(write(fd,buffer,strlen(buffer)) == -1)
        fatal("in main() while writing to file");

    //Close the file
    if(close(fd) == -1)
        fatal("in main() while closing  file");

    // success

    printf("Line added to the mynote.txt file successfully!");

    // free memory allocated
    free(buffer);
    free(datafile);

}

// A function to display an error message and then exit on fatal error
void fatal(char *message){
    char error_message[100];

    strcpy(error_message, "[!!] Fatal Error");
    strncat(error_message, message, 83);
    perror(error_message);
    exit(-1);

}

//A function to allocate memory block and check if it was done.
void *ec_malloc(unsigned int size){
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
            fatal("in ec_malloc() on memory allocation");
    return ptr;
}
