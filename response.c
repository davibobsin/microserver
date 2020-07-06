#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "response.h"
#include "request.h"

#define CRLF "\r\n"


int routes(char * request)
{
    return 0;
}

int readImage(char * filename,char * output)
{
    char * ptr;
 
    sprintf(output,"HTTP/1.1 200 OK\r\n");
    strcat(output,"Content-Type: image/jpg\r\n");
    strcat(output,"Content-Length: 3785\r\n");
    strcat(output,"\r\n");

    FILE *fp = fopen(filename, "r");  // open the file in 'read' mode

    ptr = output+strlen(output);

    while (!feof(fp)){                        // while not end of file
        *ptr=fgetc(fp);                         // get a character/byte from the file
        ptr++;
        //printf("Read from file %02x\n\r",c); // and show it in hex format
    }
    fclose(fp);                               // close the file
    return 0;
}

int readHtml(char * filename,char * output)
{
    char * ptr;
 
    sprintf(output,"HTTP/1.1 200 OK\r\n");
    strcat(output,"Content-Type: text/html\r\n");
    strcat(output,"Content-Length: 3785\r\n");
    strcat(output,"\r\n");

    FILE *fp = fopen(filename, "r");  // open the file in 'read' mode

    ptr = output+strlen(output);

    while (!feof(fp)){                        // while not end of file
        *ptr=fgetc(fp);                         // get a character/byte from the file
        ptr++;
        //printf("Read from file %02x\n\r",c); // and show it in hex format
    }
    fclose(fp);                               // close the file
    return 0;
}