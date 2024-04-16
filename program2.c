#include<stdio.h>
void main(){
int i,j,temp,n,bt[10],wt[10],tat[10],twt=0,ttat=0,pid[10],at[10],min,tbt=0,sum=0,tt[10],bench,h;
float awt=0.0,atat=0.0;
printf("enter number of processes:\n");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("enter burst time of process %d",i+1);
scanf("%d",&bt[i]);
printf("enter the arrival time of process\n");
scanf("%d",&at[i]);
pid[i]=i+1;
}
for(i=0;i<n;i++){
min=bt[i];
for(j=i+1;j<n;j++){
if(at[j]<at[i]){
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
temp=at[i];
at[i]=at[j];
at[j]=temp;
temp=pid[i];
pid[i]=pid[j];
pid[j]=temp;
}
}
}
for(i=0;i<n;i++){
sum+=bt[i];
tt[i]=sum;
if(sum<at[i+1]&&(i+1)!=n)
sum+=at[i+1]-sum;
}
while(h<n){
for(i=h;i<n;i++){
bench=tt[i];
for(j=i+1;j<n-1;j++){
if(at[j]<=bench){
if(bt[j+1]<bt[j]){
temp=bt[j+1];
bt[j+1]=bt[j];
bt[j]=temp;
temp=at[i];
at[i]=at[j];
at[j]=temp;
temp=pid[i];
pid[i]=pid[j];
pid[j]=temp;
temp=tt[i];
tt[i]=tt[j];
tt[j]=temp;
}
}
}
}
h++;
}
tbt=at[0];
wt[0]=0;
tat[0]=bt[0];
for(i=1;i<n;i++){
tbt+=bt[i-1];
if(at[i]<tbt){
wt[i]=tbt-at[i];
}
else{
if(tbt==at[i])
wt[i]=0;
else{
wt[i]=0;
tbt+=at[i]-tbt;
}
}
tat[i]=wt[i]+bt[i];
}
for(i=0;i<n;i++){
twt=twt+wt[i];
ttat=ttat+tat[i];
}
printf("|pid|\t|bt|\t|at|\t|wt|\t|tat|\n");
for(i=0;i<n;i++){
printf("|%d|\t|%d|\t|%d|\t|%d|\t|%d|\n",pid[i],bt[i],at[i],wt[i],tat[i]);
}
awt=(float)(twt/n);
atat=(float)(atat/n);
printf("average waiting time:%f\n",awt);
printf("average turn around time:%f\n",atat);
}






