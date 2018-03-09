// Q127 2018/1/30

#include <stdio.h>

typedef struct{
    char color[2] ;
    int stack;
}cards;

void piles(cards cd[]);
void move(cards cd[],int i);

int main(){
    cards cd[55]={"  ",0};

    while(scanf("%s",cd[0].color),cd[0].color[0]!='#'){
        cd[0].stack=1;
        for(int i=1;i<52;i++){
            scanf("%s",cd[i].color);
            cd[i].stack=1;
        }

        piles(cd);


        for(int i=0;i<52;i++)
            printf("%02d ",cd[i].stack);
        printf("\n");
    }
    return 0;
}


void piles(cards cd[]){
    for(int i=0;i<52;i++){

        if((cd[i].color[0]==cd[i-3].color[0]||cd[i].color[1]==cd[i-3].color[1])&&i>=3){
            cd[i-3].color[0]=cd[i].color[0];
            cd[i-3].color[1]=cd[i].color[1];
            cd[i-3].stack+=cd[i].stack;

            move(cd,i);
            i-=4;
        }

        else if((cd[i].color[0]==cd[i-1].color[0]||cd[i].color[1]==cd[i-1].color[1])&&i>=1){
            cd[i-1].color[0]=cd[i].color[0];
            cd[i-1].color[1]=cd[i].color[1];
            cd[i-1].stack+=cd[i].stack;

            move(cd,i);
            i-=2;
        }
        if(cd[i].stack==0)
            break;


    for(int i=0;i<52;i++)
        printf("%s ",cd[i].color);
    printf("\n");

    }
}

void move(cards cd[],int i){
        for(int j=i;j<53;j++){
            cd[j].color[0]=cd[j+1].color[0];
            cd[j].color[1]=cd[j+1].color[1];
            cd[j].stack=cd[j+1].stack;
        }
}
