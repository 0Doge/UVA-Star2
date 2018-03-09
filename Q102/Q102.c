// Q102 2018/1/26

#include <stdio.h>

typedef struct{
    int Green,Brown,Clear;
    char Color;
}Bucket;

int move(Bucket bt[]);


int main(){
    Bucket bt[3];
    while(scanf("%d %d %d %d %d %d %d %d %d",&bt[0].Brown,&bt[0].Green,&bt[0].Clear,&bt[1].Brown,&bt[1].Green,&bt[1].Clear,&bt[2].Brown,&bt[2].Green,&bt[2].Clear)!=EOF){
        printf("%c%c%c %d\n",bt[0].Color,bt[1].Color,bt[2].Color,move(bt));
    }
    return 0;
}

int move(Bucket bt[]){
    int lessmove=bt[0].Green+bt[0].Clear+bt[1].Brown+bt[1].Green+bt[2].Brown+bt[2].Clear; //BCG
        bt[0].Color='B';
        bt[1].Color='C';
        bt[2].Color='G';

    if(bt[0].Green+bt[0].Clear+  bt[1].Brown+bt[1].Clear+    bt[2].Brown+bt[2].Green<lessmove){
        lessmove=bt[0].Green+bt[0].Clear+  bt[1].Brown+bt[1].Clear+    bt[2].Brown+bt[2].Green;
        bt[0].Color='B';
        bt[1].Color='G';
        bt[2].Color='C';
    } //BGC

    if(bt[0].Green+bt[0].Brown+  bt[1].Green+bt[1].Clear+    bt[2].Brown+bt[2].Clear<lessmove){
        lessmove=bt[0].Green+bt[0].Brown+  bt[1].Green+bt[1].Clear+    bt[2].Brown+bt[2].Clear;
        bt[0].Color='C';
        bt[1].Color='B';
        bt[2].Color='G';
    } //CBG
    if(bt[0].Green+bt[0].Brown+  bt[1].Brown+bt[1].Clear+    bt[2].Clear+bt[2].Green<lessmove){
        lessmove=bt[0].Green+bt[0].Brown+  bt[1].Brown+bt[1].Clear+    bt[2].Clear+bt[2].Green;
        bt[0].Color='C';
        bt[1].Color='G';
        bt[2].Color='B';
    } //CGB

    if(bt[0].Brown+bt[0].Clear+  bt[1].Green+bt[1].Clear+    bt[2].Brown+bt[2].Green<lessmove){
        lessmove=bt[0].Brown+bt[0].Clear+   bt[1].Green+bt[1].Clear+    bt[2].Brown+bt[2].Green;
        bt[0].Color='G';
        bt[1].Color='B';
        bt[2].Color='C';
    } //GBC

    if(bt[0].Brown+bt[0].Clear+  bt[1].Brown+bt[1].Green+    bt[2].Clear+bt[2].Green<lessmove){
        lessmove=bt[0].Brown+bt[0].Clear+ bt[1].Brown+bt[1].Green+    bt[2].Clear+bt[2].Green;
        bt[0].Color='G';
        bt[1].Color='C';
        bt[2].Color='B';
    } //GCB

    return lessmove;
}
