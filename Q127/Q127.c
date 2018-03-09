// Q127 2018/1/31

#include <stdio.h>

typedef struct{
    char color[2] ;
    int stack;
}cards;

void PaSb(cards cd[52][52],int a,int b); //pop a �P��stack ��b
int piles(cards cd[52][52]);  //�ưﲾ��
void move(cards cd[52][52],int a); //�űư�M�z

int main(){
    cards cd[52][52]={"  ",0}; //[�ĴX��][�ĴX�i�P]

    while(scanf("%s",cd[0][0].color),cd[0][0].color[0]!='#'){
        cd[0][0].stack=1;    //���|�i�ƲΤ@�s�b �P�諸�Ĥ@�i
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

        if((cd[i][0].color[0]==cd[i-3][0].color[0]||cd[i][0].color[1]==cd[i-3][0].color[1])&&i>=3){ //�P���TMatch
            PaSb(cd,i,i-3);

            if(cd[i][0].stack==0) //�P�אּ�Ů� ��L�P����
                move(cd,i);
            i-=4; //-3�~���ˬd�O�_�i�H�A���� �A-1�O�]���U��for�j��i++
        }

        else if((cd[i][0].color[0]==cd[i-1][0].color[0]||cd[i][0].color[1]==cd[i-1][0].color[1])&&i>=1){ //�P���@Match
            PaSb(cd,i,i-1);

            if(cd[i][0].stack==0)
                move(cd,i);
            i-=2; //-1�~���ˬd�O�_�i�H�A���� �A-1�O�]���U��for�j��i++
        }
        if(cd[i+1][0].stack==0)  //�k���w�S�P ����
            return i+1;
    }
}
void move(cards cd[52][52],int a){
    for(int i=a;i<51;i++){    //�P�索��
        for(int j=0;j<52;j++){
            cd[i][j].color[0]=cd[i+1][j].color[0];
            cd[i][j].color[1]=cd[i+1][j].color[1];
        }
     cd[i][0].stack=cd[i+1][0].stack;
    }

    cd[51][0].color[0]=' '; //�R������
    cd[51][0].color[1]=' ';
    cd[51][0].stack=0;
}
