// Q127 2018/1/31

#include <stdio.h>

typedef struct{
    char color[2] ;
    int stack;
}cards;

void PaSb(cards cd[52][52],int a,int b); //pop a 同時stack 到b
int piles(cards cd[52][52]);  //排堆移動
void move(cards cd[52][52],int a); //空排堆清理

int main(){
    cards cd[52][52]={"  ",0}; //[第幾堆][第幾張牌]

    while(scanf("%s",cd[0][0].color),cd[0][0].color[0]!='#'){
        cd[0][0].stack=1;    //堆疊張數統一存在 牌堆的第一張
        for(int i=1;i<52;i++){
            scanf("%s",cd[i][0].color);
            cd[i][0].stack=1;
        }
        int pil=piles(cd);

        if(pil==1)
            printf("1 pile remaining:");
        else
            printf("%d piles remaining:",pil);

        for(int i=0;i<pil;i++)
            printf(" %d",cd[i][0].stack);
        printf("\n");
        }

    return 0;
}


void PaSb(cards cd[52][52],int a,int b){
    for(int i=cd[b][0].stack;i>0;i--){  //stack
        cd[b][i].color[0]=cd[b][i-1].color[0];
        cd[b][i].color[1]=cd[b][i-1].color[1];
    }
    cd[b][0].color[0]=cd[a][0].color[0];
    cd[b][0].color[1]=cd[a][0].color[1];
    cd[b][0].stack+=1;

    for(int i=0;i<cd[a][0].stack-1;i++){  //pop
        cd[a][i].color[0]=cd[a][i+1].color[0];
        cd[a][i].color[1]=cd[a][i+1].color[1];
    }
    cd[a][0].stack-=1;
}

int piles(cards cd[52][52]){
    for(int i=0;i<52;i++){

        if((cd[i][0].color[0]==cd[i-3][0].color[0]||cd[i][0].color[1]==cd[i-3][0].color[1])&&i>=3){ //與左三Match
            PaSb(cd,i,i-3);

            if(cd[i][0].stack==0) //牌堆為空時 其他牌左移
                move(cd,i);
            i-=4; //-3繼續檢查是否可以再左移 再-1是因為下次for迴圈i++
        }

        else if((cd[i][0].color[0]==cd[i-1][0].color[0]||cd[i][0].color[1]==cd[i-1][0].color[1])&&i>=1){ //與左一Match
            PaSb(cd,i,i-1);

            if(cd[i][0].stack==0)
                move(cd,i);
            i-=2; //-1繼續檢查是否可以再左移 再-1是因為下次for迴圈i++
        }
        if(cd[i+1][0].stack==0)  //右側已沒牌 結束
            return i+1;
    }
}
void move(cards cd[52][52],int a){
    for(int i=a;i<51;i++){    //牌堆左移
        for(int j=0;j<52;j++){
            cd[i][j].color[0]=cd[i+1][j].color[0];
            cd[i][j].color[1]=cd[i+1][j].color[1];
        }
     cd[i][0].stack=cd[i+1][0].stack;
    }

    cd[51][0].color[0]=' '; //刪除尾巴
    cd[51][0].color[1]=' ';
    cd[51][0].stack=0;
}
