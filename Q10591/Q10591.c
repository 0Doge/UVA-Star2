#include<stdio.h>

int main(){

long sum=0,in=0,cpyin=0,num=0;
int n=0;
scanf("%d",&n);

for(int i=0;i<n;i++){
    scanf("%ld",&in);
    sum=0;
    while(in>0){
        sum+=(in%10)*(in%10);
        in/=10;
       //printf("%ld  %ld \n",in,sum);
        if(in==0&&sum==4){
            printf("Case #%ld: %ld is an Unhappy number.\n",i+1,cpyin);
            break;
        }
        if(sum==1&&in==0){
            printf("Case #%ld: %ld is a Happy number.\n",i+1,cpyin);
            break;
        }
        if(in==0){
        in=sum;
        sum=0;
        }
    }
}
return 0;
}
