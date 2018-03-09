// Q101 2018/1/25

#include <stdio.h>

typedef struct{
    int stack[25],tall;  //編號位置的堆疊方式 高度 編號方塊的位置
}BlockStack;

typedef struct{
    int number,stack;  //編號 位置
}Block;

Block FindBlockStack(BlockStack bk[],int a);

void Push(BlockStack bk[],Block a,Block b);
void Pop(BlockStack bk[],Block a);
void SeeBlockStack(BlockStack bk[],int n);

void MoveOnto(BlockStack bk[],int a,int b);
void MoveOver(BlockStack bk[],int a,int b);
void PileOnto(BlockStack bk[],int a,int b);
void PileOver(BlockStack bk[],int a,int b);


int main(){
    int n=0;
    while(scanf("%d",&n)!=EOF){
        char actionf[5],actionb[5];
        int a=0,b=0;
        BlockStack bk[25]={0};

        for(int i=0;i<n;i++){
            bk[i].stack[0]=i;
            bk[i].tall=1;
        }

        while(scanf("%s",actionf),actionf[0]!='q'){
            scanf("%d %s %d",&a,actionb,&b);
            if(a==b)
                continue;
            else if(actionf[0]=='m'){
                if(actionb[3]=='o')
                    MoveOnto(bk,a,b);
                else if(actionb[3]=='r')
                    MoveOver(bk,a,b);
            }
            else if(actionf[0]=='p'){
                if(actionb[3]=='o')
                    PileOnto(bk,a,b);
                else if(actionb[3]=='r')
                    PileOver(bk,a,b);
            }
        }
        SeeBlockStack(bk,n);
    }
    return 0;
}

Block FindBlockStack(BlockStack bk[],int a){
    for(int i=0;i<25;i++){
        for(int j=0;j<bk[i].tall;j++){
            if(bk[i].stack[j]==a){
                Block where;
                where.number=i;
                where.stack=j;
                return where;
            }
        }
    }
}

void Push(BlockStack bk[],Block a,Block b){
    int tall=bk[a.number].tall;

    for(int i=a.stack ; i<tall;i++){
        bk[b.number].stack[bk[b.number].tall]=bk[a.number].stack[i];
        bk[b.number].tall+=1;
        bk[a.number].tall-=1;
    }
}

void Pop(BlockStack bk[],Block a){
    for(int i=bk[a.number].tall-1; i> a.stack  ;i--){ //從最高搬到a(不包含a)

        int move=bk[a.number].stack[i]; //正要搬走的那塊

        bk[move].stack[bk[move].tall]=move;
        bk[move].tall+=1;
        bk[a.number].tall-=1;
    }
}

void MoveOnto(BlockStack bk[],int a,int b){
    Pop(bk,FindBlockStack(bk,a));
    Pop(bk,FindBlockStack(bk,b));
    Push(bk,FindBlockStack(bk,a),FindBlockStack(bk,b));
}

void MoveOver(BlockStack bk[],int a,int b){
    Pop(bk,FindBlockStack(bk,a));
    Push(bk,FindBlockStack(bk,a),FindBlockStack(bk,b));
}

void PileOnto(BlockStack bk[],int a,int b){
    Pop(bk,FindBlockStack(bk,b));
    Push(bk,FindBlockStack(bk,a),FindBlockStack(bk,b));
}

void PileOver(BlockStack bk[],int a,int b){
    Push(bk,FindBlockStack(bk,a),FindBlockStack(bk,b));
    }

void SeeBlockStack(BlockStack bk[],int n){
    for(int i=0;i<n;i++){
        printf("%d:",i);
        for(int j=0;j<bk[i].tall;j++)
            printf(" %d",bk[i].stack[j]);
        printf("\n");
    }
}
