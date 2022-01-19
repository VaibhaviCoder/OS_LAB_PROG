#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int sze_p,sze_r,i,j,idx,k;

int main(){

    printf("Bankers Algorithm\n");
    
    printf("Enter Number of Process:\n");
    
    scanf("%d",&sze_p);

    printf("Enter Number of Resources:\n");

    scanf("%d",&sze_r);  

    int alc[sze_p][sze_r],max_r[sze_p][sze_r],need[sze_p][sze_r]; 

    printf("Enter Allocation of Instances of Resources per Process: \n");

  for(i=0;i<sze_p;i++)
    for(j=0;j<sze_r;j++)
        scanf("%d",&alc[i][j]);

  printf("Allocation Matrix:-\n");

  for(i=0;i<sze_p;i++){
    for(j=0;j<sze_r;j++)
        printf("%d ",alc[i][j]);
    printf("\n");
}
  printf("Enter Max_rimum Allocation Instances of Resources per Process: \n");

  for(i=0;i<sze_p;i++)
    for(j=0;j<sze_r;j++)
        scanf("%d",&max_r[i][j]);

  printf("Maximum Matrix:-\n");

  for(i=0;i<sze_p;i++){
    for(j=0;j<sze_r;j++)
        printf("%d ",max_r[i][j]);
    printf("\n");
}

  for(i=0;i<sze_p;i++)
    for(j=0;j<sze_r;j++)
        need[i][j]=max_r[i][j]-alc[i][j];

  printf("Need Matrix:\n");

  for(i=0;i<sze_p;i++){
    for(j=0;j<sze_r;j++)
        printf("%d ",need[i][j]);
  printf("\n");
}

  int avl[sze_r];

  printf("Enter Available Instances Resources: \n");

  for(i=0;i<sze_r;i++)
    scanf("%d",&avl[i]);

  int taken[sze_p];

  for(int i=0;i<sze_p;i++)
    taken[i]=0;

  int work[sze_r];
  
  for(i=0;i<sze_r;i++)work[i]=avl[i];
  
  int ans[sze_p]; 

  printf("Available Resources:");

  for(k=0;k<sze_r;k++)
    printf("%d ",avl[k]);
 
  printf("\n");
 
  for(k=0;k<sze_p;k++){
      for(i=0;i<sze_p;i++){
         if(!taken[i]){
               int find_p=1;
               for(j=0;j<sze_r;j++){
                   if(need[i][j]>avl[j])
                   {
                     find_p=0;
                     break;
                   }
               }
               if(find_p){
                 ans[idx++]=i;  
                 int v=0; 
                 for(v=0;v<sze_r;v++)
                 avl[v]+=alc[i][v];
                 taken[i]=1;
               }
               
        }

    }
}
  int s_state=1;
 
  for(i=0;i<sze_p;i++){
    if(!taken[i]){
        s_state=0;
        break;
    }
}

  if(!s_state){
    printf("NOT IN SAFE STATE\n");
}
  
  else{
    printf("SAFE SEQUENCE:- ");
    for(j=0;j<sze_p;j++){
        printf("P%d ",ans[j]);
    }
    printf("\n");
}

  printf("Enter Request: \n");
  
  int Req_r[sze_r];
  
  for(i=0;i<sze_r;i++)
    scanf("%d",&Req_r[i]);
  
  int flag=1;
  
  for(i=0;i<sze_r;i++){
    if(work[i]<Req_r[i])
    {
      flag=0;
      break;
    }
}
  
  if(flag && s_state){
    printf("Granted\n");
}
 
  else 
    printf("No\n");

  return 0;

}
