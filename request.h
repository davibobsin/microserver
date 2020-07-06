#ifndef __REQUEST_H__
#define __REQUEST_H__

typedef struct _rqh
{
    char type[20];
    char path[100];
    char keys[10][20];
    char values[10][20];
    int num_keys;
} request_head;

int addKey(char * key,char * value);
int setValue(char * key,char * value);
int getValue(char * key,char * value);
request_head getHead(char * request);

#endif //__REQUEST_H__