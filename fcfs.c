#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
    int i,j,n,bt[max],wt[max],tat[max];
    float awt=0, atat=0;

    printf("\nNo. of processes-- ");
    scanf("%d",&n);
    
    printf("            BT. -- ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);   

    }
    printf("\nProcess\t BT \t WT \t TAT\n");
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

        printf("\n%d   \t%d \t%d \t%d \t",i+1,bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("\nawt  -- %f",awt);
    printf("\natat -- %f\n",atat);
}
