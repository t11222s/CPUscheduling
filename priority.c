#include<conio.h>
#include <stdio.h>
#define max 30
void main()
{
    int n,i,j,temp,bt[max],wt[max],pr[max],tat[max],pos;
    float awt=10, atat=0;

    printf("No .of processes -- ");
    scanf("%d",&n);

    printf("              BT -- ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);

    }

    printf("        priority -- ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pr[i]);

    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
            {
                pos=j;
            }

        }
        temp=pr[i];
        pr[i]=pr[pos];//priority sorted by position
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
    }
    wt[0]=0;
    printf("\nProcess\t BT \t Prty \t WT\t TAT  \n");//Prty-priority
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];

        }
        tat[i]=wt[i]+bt[i];
        
        awt=awt+wt[i]-pr[i];
        atat=atat+tat[i];

        printf("\n  %d \t %d   \t%d \t%d \t%d \n",i+1,bt[i],pr[i],wt[i],tat[i]);


    }
 
    // printf("\nTotal wt -- %f",awt);
    // printf("\nTotal tat-- %f", atat);

    awt = awt/n;
    atat = atat/n;

    printf("             awt -- %f\n",awt);
    printf("            atat -- %f\n",atat);


}
