#include <stdio.h>
#include <string.h>
#include "request.h"

#define CRLF "\r\n"

void print_head(request_head head)
{
    int i;
    printf("type: %s\n",head.type);
    printf("path: %s\n",head.path);
    printf("vars:\n{");
    for(i=0;i<head.num_keys;i++)
        printf("    %s: %s\n",head.keys[i],head.values[i]);
    printf("}\n");
}

int _split(char * line,char * delim,char * list[])
{
    int qtd = 0;
    char *ptr;
    
    ptr = strtok(line, delim);
    
    while(ptr != NULL)
    {
        printf(":%s:",ptr);
        qtd++;
        ptr = strtok(NULL, delim);
    }

    return qtd;
}

request_head getHead(char * request)
{
    request_head output;
    char line[128];
    char list[16][128];
    char *ptr;
    output.num_keys = 0;

    _split(request, CRLF,list);

    // if(_split(line," ",list) > 2)
    // {
    //     strcpy(output.type,"list[0]");
    //     strcpy(output.path,"list[1]");
    //     print_head(output);
    // }


    // strcpy(output.type,strtok(first, " "));
    // ptr = strtok(NULL, " ");
    
    // strcpy(output.path,strtok(ptr, "?"));
        
    // vars = strtok(NULL, "?");
    // if(vars)
    // {
    //     ptr = strtok(vars, "&");
    //     while(ptr)
    //     {
    //         printf("...%s",ptr);
    //         _get_key_and_value(ptr,
    //             output.keys[output.num_keys],
    //             output.values[output.num_keys]);
    //         output.num_keys++;

    //         ptr = strtok(NULL, "&");
    //     }
    // }

    
    return output;
}
