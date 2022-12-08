#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
    int i,j,n,t,p[max],bt[max],wt[max],tat[max];

    float awt=0, atat=0;
    printf("\nNo. of processes-- ");
    scanf("%d",&n);
    
    printf("    Process no. -- ");
    for(i=0;i<n;i++)
    { 
        scanf("%d",&p[i]);
    }

    printf("            BT. -- ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);   

    }

    //bubble sort
    for(i=0;i<n;i++)
    {
       for(j=0;j<n-1-i;j++){
        if(bt[j]>bt[j+1])
        {
            t=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=t;

            t=p[j];
            p[j]=p[j+1];
            p[j+1]=t;


        }
       }
    }
    printf("\nprocess\t BT \t WT \t TAT \n ");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];

        printf("\n%d\t %d\t %d\t %d\t ",p[i],bt[i],wt[i],tat[i]);

    }
    awt=awt/n;
    atat=atat/n;
    printf("\nawt  -- %f",atat);
    printf("\natat -- %f", awt);



}
