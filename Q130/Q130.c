// Q130 2018/1/31

#include <stdio.h>
#include <math.h>

int kill(int peo[],int k,int n,int start);
int change(int peo[],int k,int n,int start);
/*int move(int peo[],int n,int k,int start){

            for(int k=0;k<n;k++)
                printf("%d ",peo[k]);

            printf("\n");

    int kill=start+k>n-1?start+k-n:start+k;
    int bury=kill+k+1>n-1?kill+k+1-n:kill+k+1;

    printf("k [%d] b[%d]\n",kill,bury);

    peo[kill]=peo[bury];

    for(int i=bury;i<n;i++)
        peo[i]=peo[i+1];
    peo[n] =0;

    if(kill>=bury) //死在後面=
        kill-=1;
printf("Ns [%d] n [%d] k [%d]\n",((kill+1)>(n-2)?kill-n+2:kill+1),n,kill,bury);
    return (kill+1)>(n-2)?kill-n+2:kill+1;
}
*/

int main(){
    int n,k;
    while(scanf("%d %d",&n,&k),n!=0||k!=0){
        int peo[100]={0};



        for(int l=0;l<n;l++){
            for(int i=0;i<n;peo[i++]=i);
            int dead=l;

            for(int j=0;j<n-1;j++){
//----------------------------------------------------

//-------------------------------------------
                    dead=kill(peo,k,n-j,dead);
               // printf("kill %d\n",dead);

               for(int i=0;i<n;i++)
                   printf("%d ",peo[i]);
                printf("\n");

                    int b=change(peo,k,n-j,dead);
                //printf("take %d\n",b);

                    if(b>=dead)
                        dead+=1;
                    if(dead>=n-j-1)
                        dead=0;

                for(int i=0;i<n;i++)
                    printf("%d ",peo[i]);
                printf("\n");
               // printf("[%d] %d %d\n\n",dead,n,j);
            }



                if(peo[0]==1){
                    printf("[%d]\n",l+1);
                    break;
                    }
            printf("\n",l+2);
        }
    }

    return 0;
}

int kill(int peo[],int k,int n,int start){
    int where=start;
    for(int i=0;i<k-1;i++){
        where= where+1>=n?0:where+1;
    }

    for(int i=where;i<n;i++){
        peo[i]= peo[i+1];
    }

    //printf("kill [%d]\n",start);
    return where;
}

int change(int peo[],int k,int n,int start){
    int where=start;

    for(int i=0;i<k;i++){
        where= where+1>=n?0:where+1;
    }

    if(where>start)
        where+1;


    for(int i=n-1;i>start;i--)
        peo[i]= peo[i-1];



          //  for(int i=0;i<5;i++)
         //       printf("--%d ",peo[i]);
         //   printf("  [%d %d]\n",where,start);

    peo[start]=peo[where];

    for(int i=where;i<n;i++)
        peo[i]= peo[i+1];

     //   for(int i=0;i<5;i++)
      //      printf("--%d ",peo[i]);
      //  printf("\n");

    return where;
}
