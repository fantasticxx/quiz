#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main()
{
    int card[52];
    int s;
    int t;
    srand(time(NULL));
    //generate deck
    for(int i=0; i<52; i++) {
        card[i]=i+1;
    }
    //shuffle
    for(int j=51; j>0; j--) {
        s=(int)(rand()%52);
        t=card[s];
        card[s]=card[j];
        card[j]=t;
    }

    for(int k=0; k<52; k++) {
        printf("%d\t",card[k]);
    }

    return 0;
}

