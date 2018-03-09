// Q107 2018/1/26

#include <stdio.h>

int powcheck(int n,int x); //n�O�_�Ox��y���� (�^�� 0���_ 1���O)
int powy(int n,int x);    //n�Ox��  y���� (�^��y)
int ipow(int x,int y);  //x��y����  (�^��x��y����)
int Ncat(int works,int tall); //��X�@���ͦ�N����  (�^��N)
int LongCats(int tall,int n); //(n���@���ͦ��h�ֿ�) �Ҧ��ͦ��������`��  (�^���`��)
int SleepCats(int tall,int n); //(n���@���ͦ��h�ֿ�) ���h�֨S�b���ƪ���  (�^�ǿ߼�)


int main(){
    int tall=0,works=0;
    while(scanf("%d %d",&tall,&works),tall!=0||works!=0){

       printf("%d %d\n",SleepCats(tall,Ncat(works,tall)),LongCats(tall,Ncat(works,tall)));
    }
    return 0;
}

int powy(int x,int n){
    int y=0;
    while(x/=n)
        y++;
    return y;
}

int powcheck(int x,int n){
    while(x){
        if(x!=1&&x%n!=0)
            return 0;
        x/=n;
    }
    return 1;
}

int ipow(int x,int y){
    if(y==0)
        return 1;
    return x*ipow(x,y-1);
}

int Ncat(int works,int tall){
    if(works==1)
        return 1;

    for(int i=2;i<=works;i++){
        if(powcheck(works,i)){
            if(powy(works,i)==powy(tall,i+1))
                return i;
        }
    }
     return 0;
}

int LongCats(int tall,int n){
    int sumlong=0,y=powy(tall,n+1);

    for(int i=0;i<=y;i++){
        sumlong+=ipow(n,i)*tall;
        tall/=(n+1);
    }
    return sumlong;
}

int SleepCats(int tall,int n){
    int sumsleep=0,y=powy(tall,n+1);

    for(int i=0;i<y;i++)
        sumsleep+=ipow(n,i);

    return sumsleep;
}
