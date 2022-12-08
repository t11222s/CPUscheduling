//check
#include<stdio.h>
#include<conio.h>
#define max 20
void main()
{
    int i,j,n,at[max],bt[max],wt[max],tat[max],temp[max];
    float awt=0, atat=0;

    printf("No. of processes-- ");
    scanf("%d",&n);
    printf("             BT -- ");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);

    printf("             AT -- ");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);


    temp[0]=0;
    printf("\nProcess\t BT \t AT\t WT \t TAT\n");

    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i+1]+bt[i];

        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]=bt[i];

        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d   \t%d \t%d \t%d \t%d \n",i+1,bt[i],at[i],wt[i],tat[i]);

    }
    awt=awt/n;
    atat=atat/n;
    printf("\nawt  -- %f",awt);
    printf("\natat -- %f\n",atat);

}
