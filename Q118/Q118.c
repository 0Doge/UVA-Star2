// Q118 2018/1/29

#include <stdio.h>
#include <string.h>

typedef struct{
    int x,y;
    char direction,fall;
}robot;

void Dir(robot *in,char turn);
char Forward(robot *in,int borderx,int bordery);

int main(){
    int  borderx,bordery;
    char land[51][51]={0};
    scanf("%d %d",&borderx,&bordery);

    robot in={0,0,'N','0'};
    char control[101];
    while(scanf("%d %d %c",&in.x,&in.y,&in.direction)!=EOF){
        in.fall='0';
        scanf("%s",control);
        for(int i=0;i<strlen(control);i++){
            if(control[i]=='L'||control[i]=='R')
                Dir(&in,control[i]);
            else{
                if(land[in.x][in.y]==in.direction)
                     continue;
                else if(land[in.x][in.y]!=in.direction){
                    land[in.x][in.y]=Forward(&in,borderx,bordery);
                    if(in.fall=='Y')
                        break;
                }
            }
        }

        printf("%d %d %c",in.x,in.y,in.direction);
        if(in.fall=='Y')
            printf(" LOST\n");
        else
            printf("\n");
    }
    return 0;
}

void Dir(robot *in,char turn){  //µ²ºc ¶Ç§} (*in).direction or in->direction
    if(((*in).direction=='N'&&turn=='R')||((*in).direction=='S'&&turn=='L'))
        (*in).direction='E';
    else if(((*in).direction=='E'&&turn=='R')||((*in).direction=='W'&&turn=='L'))
        (*in).direction='S';
    else if(((*in).direction=='S'&&turn=='R')||((*in).direction=='N'&&turn=='L'))
        (*in).direction='W';
    else if(((*in).direction=='W'&&turn=='R')||((*in).direction=='E'&&turn=='L'))
        (*in).direction='N';
}

char Forward(robot *in,int borderx,int bordery){
    if((*in).direction=='N'){
        if((*in).y+1<=bordery)
            (*in).y+=1;
        else
            (*in).fall='Y';
       }
    else if((*in).direction=='W'){
        if((*in).x-1>=0)
            (*in).x-=1;
        else
            (*in).fall='Y';
       }
    else if((*in).direction=='S'){
        if((*in).y-1>=0)
            (*in).y-=1;
        else
            (*in).fall='Y';
       }
    else if((*in).direction=='E'){
        if((*in).x+1<=borderx)
            (*in).x+=1;
        else
            (*in).fall='Y';
       }
    if((*in).fall=='Y')
            return (*in).direction;
    return '0';
}
