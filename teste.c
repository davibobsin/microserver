#include<stdio.h>

#define VA_NARGS2(...)               \
    char test[][20] = {__VA_ARGS__};\
    ((int)(sizeof((char*){ __VA_ARGS__})/sizeof(int)))

// #define LOOP(start,end,args...)                 \
//   char strs[10][20] = {args}; \
//   for (int i = (start); i < (end); i++) {       \
//     printf("%s\n", args[i]);                    \
//   }

int main(int argc,char * argv[])
{
    // LOOP(1,3,a,"b","c","d","e");
    printf(">%d args...",VA_NARGS2("b","c","d","e"));
    return 0;
}