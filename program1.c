#include<stdio.h>
void main(){
int i,n,bt[10],wt[10],tat[10],twt=0,ttat=0;
float awt=0.0,atat=0.0;
printf("enter number of processes:\n");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("enter burst time of process %d",i+1);
scanf("%d",&bt[i]);
}
printf("|pid|\t|bt|\t|wt|\t|tat|\n");
for(i=0;i<n;i++){
if(i==0){
wt[i]=0;
tat[i]=bt[i];
}
else{
wt[i]=wt[i-1]+bt[i-1];
tat[i]=wt[i]+bt[i];
}
printf("|%d|\t|%d|\t|%d|\t|%d|\n",i+1,bt[i],wt[i],tat[i]);
twt=twt+wt[i];
ttat=ttat+tat[i];
}
awt=(float)(twt/n);
atat=(float)(ttat/n);
printf("average waiting time:%f",awt);
printf("average turn around time:%f",atat);
}
