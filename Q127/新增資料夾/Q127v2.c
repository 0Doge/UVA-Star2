// Q127 2018/1/30

#include <stdio.h>

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


        int l=0,ll;
        for(int i=0;i<52;i++){
            printf("[%s] ",cd[i].color);
            ll=piles(cd,i);
            i-=ll;
            l++;
            move(cd);
            if(l==55)
                break;


            for(int i=0;i<52;i++)
                printf("%s ",cd[i].color);
           printf("\n");
        //    for(int i=0;i<52;i++)
        //        printf("%02d ",cd[i].stack);
         //  printf(" [%d]  \n",i);


        }

    }
    return 0;
}


int piles(cards cd[],int now){
    int i=now,time=0;

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
    return time;
}

void move(cards cd[]){
    for(int i=1;i<51;i++){
        if(cd[i].stack==0){
            for(int j=i;j<52;j++){
                cd[j].color[0]=cd[j+1].color[0];
                cd[j].color[1]=cd[j+1].color[1];
                cd[j].stack=cd[j+1].stack;

                cd[52].color[0]=' ';
                cd[52].color[1]=' ';
                cd[52].stack=-1;
            }
        i-=1;
        }
    }
}
