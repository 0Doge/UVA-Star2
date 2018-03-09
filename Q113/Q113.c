// Q107 2018/1/28

#include <stdio.h>
#include <math.h>

int main(){
    double n,p;
    while(scanf("%lf %lf",&n,&p)!=EOF){
       printf("%.0f\n",pow(p,1.0/n));
    }
    return 0;
}

