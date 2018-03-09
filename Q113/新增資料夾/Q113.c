// Q107 2018/1/2

#include <stdio.h>
#include <string.h>

int base(int n,char p[]); //x的n次方=p (回傳 x)
int ipow(int x,int y);
int ipowmodn(int x,int y,int n); //x的y次方 (回傳 第n位)



int main(){
    int n=0;
    char p[100];
    while(scanf("%d %s",&n,p)!=EOF){

       printf("%d \n",base(n,p));
    }
    return 0;
}


int ipow(int x,int y){
    if(y==0)
        return 1;
    return x*ipow(x,y-1);
}

int ipowmodn(int x,int y,int n){

    long long temp=1;
    for(int i=0;i<y;i++){
        temp=temp*x%ipow(10,n);
    }
    int get=temp%ipow(10,n)/ipow(10,n-1);
    return get;
}

int base(int n,char p[]){
    int x=0;   //v為現在所處理的位數

    /*for(;x<100;x++){
        if(ipow(x,n)%100==(p[strlen(p)-1]-48)*10+(p[strlen(p)-2]-48))
        break;

    }*/

    for(int i=0;i<10;i++){  //x 10^0~10^9
        if((strlen(p)-i)<1)
            break;
        x+=9*ipow(10,i);      //每個位數1~9
        for(int j=0;j<9;j++){
            printf("%d %d [%d]\n",x,ipowmodn(x,n,i+1),strlen(p)-i-1);
            if(ipowmodn(x,n,i+1)==p[strlen(p)-i-1]-48){
                break;
            }
            x-=ipow(10,i);

        }
    }
    return x;
}
