#include <stdlib.h>
#include <stdio.h>

char smallest_character(char str[],int left,int right,char c)
{
    if(right < left) {
        return str[0];
    } else {
        int mid=(int)(left+right)/2;

        if(str[mid] > c) {
            return smallest_character(str,left,mid-1,c);
        } else if(str[mid] < c) {
            return smallest_character(str,mid+1,right,c);
        } else return str[mid+1];
    }
}

int main()
{
    char key=NULL;
    char result=NULL;
    char str[5]= {'c','f','j','p','v'};
    scanf("%c",&key);
    result=smallest_character(str,0,4,key);
    printf("%c\n",result);
    return 0;
}
