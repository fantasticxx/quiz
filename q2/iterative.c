#include<stdlib.h>
#include<stdio.h>
char smallest_character(char str[],char c)
{
    for(int i=0; i<sizeof(str)-1; i++) {
        if(str[i]==c&&str[i+1]!='\0')
            return str[i+1];
    }
    return str[0];
}


int main(int argc, char* argv[])
{
    char *c,result;
    c=argv[1];
    static char str[]= {'c','f','j','p','v'};
    result=smallest_character(str,*c);
    printf("%c\n",result);
    return 0;
}
