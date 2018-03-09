// Q127 2018/1/30

#include <stdio.h>

typedef struct{
    char color[2] ;
    int stack;
}cards;

int piles(cards cd[],int card);

int main(){
    cards cd[55]={"  ",0};

    while(scanf("%s",cd[0].color),cd[0].color[0]!='#'){
        cd[0].stack=1;
        for(int i=1;i<52;i++){
            scanf("%s",cd[i].color);
            cd[i].stack=1;
        }

        int pil=0;
        for(int i=52;i!=0;pil=i--){
            if(piles(cd,i)==0)
                break;


            for(int i=0;i<52;i++)
                printf("%s ",cd[i].color);
           printf("\n");
            for(int i=0;i<52;i++)
                printf("%02d ",cd[i].stack);
           printf("\n");


        }

    }
    return 0;
}


int piles(cards cd[],int card){
    int move=0;

    for(int i=0;i<card;i++){
        if((cd[i].color[0]==cd[i+3].color[0]||cd[i].color[1]==cd[i+3].color[1])&&move==0){
            move=1;
            cd[i+3].color[0]=cd[i].color[0];
            cd[i+3].color[1]=cd[i].color[1];
            cd[i+3].stack+=cd[i].stack;
        }

        else if((cd[i].color[0]==cd[i+1].color[0]||cd[i].color[1]==cd[i+1].color[1])&&move==0){
            move=1;
            cd[i+1].color[0]=cd[i].color[0];
            cd[i+1].color[1]=cd[i].color[1];
            cd[i+1].stack+=cd[i].stack;
        }
        if(move==1){
            cd[i].color[0]=cd[i+1].color[0];
            cd[i].color[1]=cd[i+1].color[1];
            cd[i].stack=cd[i+1].stack;
        }

    }
    if(move==1){
            cd[51].color[0]=' ';
            cd[51].color[1]=' ';
            cd[51].stack=0;
    }
    return move;

}
