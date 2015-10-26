#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

char smallest_character(char str[],int left,int right,char c)
{
    int mid=left+(int)((right-left)/2+0.5);
    if(str[mid]==c) {
        return str[mid];
    } else if(str[mid]>c>str[0]) {
        return smallest_character(str,left,mid-1,c);
    } else if(str[mid]<c&&c!='\0') {
        return smallest_character(str,mid+1,right,c);
    } else return str[0];
}


int main()
{
    char key=NULL;
    char result=NULL;
    char str[5]= {'c','f','j','p','v'};
    scanf("%c",&key);
    result=smallest_character(str,0,5,key);
    printf("%c\n",result);
    return 0;
}
