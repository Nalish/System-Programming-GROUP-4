#include <stdio.h>
#include <string.h>

#define SIZE 1
#define NUMELEM 5

//Notes at the bottom.

int main(void)
{
    FILE *fd = NULL;
    char buff[100];
    memset(buff, 0, sizeof(buff));

    fd = fopen("test.txt", "rw+");

    if (NULL == fd)
    {
        printf("\n Error, unable to open file\n");
        return 1;
    }

    printf("\n File opened successfully through fopen()\n");

    if (SIZE * NUMELEM != fread(buff, SIZE, NUMELEM, fd))
    {
        printf("\n fread() failed\n");
        return 1;
    }

    printf("\n Some bytes successfully read through fread()\n");

    printf("\n The bytes read are [%s]\n", buff);

    if (0 != fseek(fd, 11, SEEK_CUR))
    {
        printf("\n fseek() failed\n");
        return 1;
    }

    printf("\n fseek() successful\n");

    if (SIZE * NUMELEM != fwrite(buff, SIZE, strlen(buff), fd))
    {
        printf("\n fwrite() failed\n");
        return 1;
    }

    printf("\n fwrite() successful, data written to text file\n");

    fclose(fd);

    printf("\n File stream closed through fclose()\n");

    return 0;
}

/*
NOTE!!!
1.) fopen() is used to open a file. Takes a pointer and mode as parameter.Returns a FILE pointer on success or null on faliure.
Modes:
    • ‘r’    :  Open text file for reading. The stream is positioned at the beginning of the file.
    • ‘r+’ :  Open for reading and writing. The stream is positioned at the beginning of the file.
    • ‘w’   :  Truncate file to zero length or create text file for writing. The stream is positioned at the beginning of the file.
    • ‘w+’ : Open for reading and writing. The file is created if it does not exist, otherwise it is truncated. The stream is positioned at the beginning of the file.
    • ‘a’    : Open for appending (writing at end of file). The file is created if it does not exist. The stream is positioned at the end of the file.
    • ‘a+’ : Open for reading and appending (writing at end of file). The file is created if it does not exist. The initial file position for reading is at the beginning of the file, but output is always appended to the end of the file.

2.) fread() & fwrite() are used for reading/writing data from/to the file opened by fopen function.
Takes the arguments:
  • pointer to buffer used for reading/writing the data.
  • data read/written is in the form of ‘nmemb’ elements each ‘size’ bytes long. 
  • the FILE stream pointer returned by the fopen() function
In case of success, fread/fwrite return the number of bytes actually read/written from/to the stream opened by fopen function. In case of failure, a lesser number of byes (then requested to read/write) is returned.

3.) fseek() function is used to set the file position indicator for the stream to a new position.
Takes the arguments:
  • the FILE stream pointer returned by the fopen() function.(Start of file)
  • 'offset' tells the amount of bytes to seek. (current postion)
  • ‘whence’ tells from where the seek of ‘offset’ number of bytes is to be done. The available values for whence are SEEK_SET, SEEK_CUR, or SEEK_END.(end of file).
Upon success, this function returns 0, otherwise it returns -1.

4.)f close() function first flushes the stream opened by fopen() and then closes the underlying descriptor.
Upon successful completion this function returns 0 else end of file (eof) is returned. In case of failure,undefined.

*/