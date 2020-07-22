#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
using namespace std;

char decimal[100];

int recursive_itoa(int arg)
{
    int div = arg / 10;
    int mod = arg % 10;
    int index = 0;
    if (div > 0)
    {
        index = recursive_itoa(div);
    }
    decimal[index] = mod + '0';
    return ++index;
}

char *itoa(const int arg)
{
    bzero(decimal, 100);
    int order = recursive_itoa(arg);
    char *new_decimal = new char[order + 1];
    bcopy(decimal, new_decimal, order + 1);
    return new_decimal;
}

int printf(const void *format, ...)
{
    va_list list;
    va_start(list, format);

    char *msg = (char *)format;
    char buf[1024];
    int nWritten = 0;

    int i = 0, j = 0, k = 0;
    while (msg[i] != '\0')
    {
        if (msg[i] == '%' && msg[i + 1] == 'd')
        {
            buf[j] = '\0';
            nWritten += write(1, buf, j);
            j = 0;
            i += 2;

            int int_val = va_arg(list, int);
            char *dec = itoa(abs(int_val));
            if (int_val < 0)
            {
                nWritten += write(1, "-", 1);
            }
            nWritten += write(1, dec, strlen(dec));
            delete dec;
        }
        else
        {
            buf[j++] = msg[i++];
        }
    }
    if (j > 0)
    {
        nWritten += write(1, buf, j);
    }
    va_end( list );
    return nWritten;
}

int setvbuf(FILE *stream, char *buf, int mode, size_t size)
{
    if (mode != _IONBF && mode != _IOLBF && mode != _IOFBF)
    {
        return -1;
    }
    stream->mode = mode;
    stream->pos = 0;
    if (stream->buffer != (char *)0 && stream->bufown == true)
    {
        delete stream->buffer;
    }

    switch ( mode )
    {
        case _IONBF:
            stream->buffer = (char *)0;
            stream->size = 0;
            stream->bufown = false;
            break;
        case _IOLBF:
        case _IOFBF:
            if (buf != (char *)0)
            {
                stream->buffer = buf;
                stream->size   = size;
                stream->bufown = false;
            }
            else
            {
                stream->buffer = new char[BUFSIZ];
                stream->size = BUFSIZ;
                stream->bufown = true;
            }
            break;
    }
    return 0;
}

void setbuf(FILE *stream, char *buf)
{
    setvbuf(stream, buf, ( buf != (char *)0 ) ? _IOFBF : _IONBF , BUFSIZ);
}

FILE *fopen(const char *path, const char *mode)
{
    FILE *stream = new FILE();
    setvbuf(stream, (char *)0, _IOFBF, BUFSIZ);

    // fopen( ) mode
    // r or rb = O_RDONLY
    // w or wb = O_WRONLY | O_CREAT | O_TRUNC
    // a or ab = O_WRONLY | O_CREAT | O_APPEND
    // r+ or rb+ or r+b = O_RDWR
    // w+ or wb+ or w+b = O_RDWR | O_CREAT | O_TRUNC
    // a+ or ab+ or a+b = O_RDWR | O_CREAT | O_APPEND

    switch(mode[0])
    {
        case 'r':
            if (mode[1] == '\0')            // r
            {
                stream->flag = O_RDONLY;
            }
            else if ( mode[1] == 'b' )
            {
                if (mode[2] == '\0')          // rb
                {
                    stream->flag = O_RDONLY;
                }
                else if (mode[2] == '+')      // rb+
                {
                    stream->flag = O_RDWR;
                }
            }
            else if (mode[1] == '+')        // r+  r+b
            {
                stream->flag = O_RDWR;
            }
            break;
        case 'w':
            if (mode[1] == '\0')            // w
            {
                stream->flag = O_WRONLY | O_CREAT | O_TRUNC;
            }
            else if (mode[1] == 'b')
            {
                if (mode[2] == '\0')          // wb
                {
                    stream->flag = O_WRONLY | O_CREAT | O_TRUNC;
                }
                else if (mode[2] == '+')      // wb+
                {
                    stream->flag = O_RDWR | O_CREAT | O_TRUNC;
                }
            }
            else if (mode[1] == '+')        // w+  w+b
            {
                stream->flag = O_RDWR | O_CREAT | O_TRUNC;
            }
            break;
        case 'a':
            if (mode[1] == '\0')            // a
            {
                stream->flag = O_WRONLY | O_CREAT | O_APPEND;
            }
            else if (mode[1] == 'b')
            {
                if (mode[2] == '\0')          // ab
                {
                    stream->flag = O_WRONLY | O_CREAT | O_APPEND;
                }
                else if (mode[2] == '+')      // ab+
                {
                    stream->flag = O_RDWR | O_CREAT | O_APPEND;
                }
            }
            else if (mode[1] == '+')        // a+  a+b
            {
                stream->flag = O_RDWR | O_CREAT | O_APPEND;
            }
            break;
    }

    mode_t open_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    if ((stream->fd = open(path, stream->flag, open_mode)) == -1)
    {
        delete stream;
        printf("fopen failed\n");
        stream = NULL;
    }

    return stream;
}

int feof(FILE *stream)
{
    return stream->eof == true;
}

// Method to purge the file stream
int fpurge(FILE *stream)
{
    // complete it
    return 0;
}

// Method to flush out the buffer
int fflush(FILE *stream)
{
    // flush buffer
    write(stream->fd, stream->buffer, stream->actual_size);

    // purge buffer
    fpurge(stream);

    return (0);
}

// Method to read the buffer to stream
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    //return read(stream->fd, ptr, nmemb);

    int c;	// variable to hold return value

    c = read(stream->fd, ptr, size * nmemb);

    // return value
    return (c / size);
}

// Method to write the buffer to the stream
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    int c;	// initialize variable for return vluae

    // write to stream, store return value
    c = write (stream->fd, ptr, size * nmemb);

    return (c / size);
}

// read in character from the file
int fgetc(FILE *stream)
{
    char c;	// char to hold read value

    // check if buffer / pos is at the end, flush buffer is so
    if (stream->pos == stream->size) {
        fflush(stream);
    }

    // read from file into char, if = 0 then EOF
    if (read (stream->fd, &c, 1) == 0)
    {
        stream->eof = true;	// set eof to true
        return (EOF);
    }

    // increment pos then return c
    stream->pos++;
    return (c);
}

// Method to put char to stream
int fputc(int c, FILE *stream)
{
    // put c to stream
    write(stream->fd, &c, 1);

    return 0;
}

// Method to get a string from the FILE stream
char *fgets(char *str, int size, FILE *stream)
{
    int n; // store return value
    char *c;	// store char

    // loop through string and get each char
    for (c = str, size--; size > 0; size--)
    {
        // get char and check for end of file
        if ((n = fgetc (stream)) == EOF)
        {
            stream->eof = true;	// set eof to true
            break;	// exist
        }

        // move pointer
        *c++ = n;

        // if new line then break
        if ( n == '\n')
        {
            break;	// exit
        }
    }

    // set char to 0
    *c = 0;

    // check if char is equal to str and return 0 if so or return char
    if (c == str)
    {
        return 0;
    }
    else
    {
        // return char
        return (c);
    }
}

// Method to put the string to the stream
int fputs(const char *str, FILE *stream)
{
    int len = strlen(str);	// hold length of string

    // write string to stream
    write (stream->fd, str, len);

    return 0;
}

// Method used to reposition the stream
int fseek(FILE *stream, long offset, int whence)
{
    int n;	// hold return value

    // reposition
    n = lseek(stream->fd, offset, whence);
    return (n);
}

int fclose(FILE *stream)
{
    // close stream
    close(stream->fd);

    // delete buffer
    delete stream;
    stream->buffer = NULL;

    return 0;
}
