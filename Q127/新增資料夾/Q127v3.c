// Q127 2018/1/30

#include <stdio.h>

int totall=52;

typedef struct{
    char color[2] ;
    int stack;
}cards;

int piles(cards cd[],int card);
void move(cards cd[]);




int main(){
    cards cd[53]={"  ",0};
    while(scanf("%s",cd[0].color),cd[0].color[0]!='#'){
        cd[0].stack=1;
        for(int i=1;i<52;i++){
            scanf("%s",cd[i].color);
            cd[i].stack=1;
        }


        for(int j=0;j<52;j++){

            int i=j;
            while(1){
                if((cd[i].color[0]==cd[i-3].color[0]||cd[i].color[1]==cd[i-3].color[1])&&i>=3){
                    cd[i-3].color[0]=cd[i].color[0];
                    cd[i-3].color[1]=cd[i].color[1];
                    cd[i-3].stack+=cd[i].stack;

                    cd[i].color[0]=' ';
                    cd[i].color[1]=' ';
                    cd[i].stack=0;

                    i=i-3;
                    time++;
        }

        else if((cd[i].color[0]==cd[i-1].color[0]||cd[i].color[1]==cd[i-1].color[1])&&i>=1){
            cd[i-1].color[0]=cd[i].color[0];
            cd[i-1].color[1]=cd[i].color[1];
            cd[i-1].stack+=cd[i].stack;

            cd[i].color[0]=' ';
            cd[i].color[1]=' ';
            cd[i].stack=0;

            i=i-1;
            time++;
        }
        else
            break;


        }

    }
    return 0;
}
