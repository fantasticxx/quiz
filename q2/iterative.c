#include<stdlib.h>
#include<stdio.h>
char smallest_character(char str[],char c)
{
    for(int i=0; i<sizeof(str)-1; i++) {
        if(str[i]==c)
            return str[i];
    }
    return str[0];
}


int main()
{
    char c,result;
    scanf("%c",&c);
    static char str[]= {'a','b','c','d','e'};
    result=smallest_character(str,c);
    printf("%c\n",result);
    return 0;
}
