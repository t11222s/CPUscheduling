#include<conio.h>
#include <stdio.h>
void main()
{
    float awt=10, atat=0;
	  int i,j,n, qt,p_count=0,temp,sq=0,bt[10],wt[10],tat[10],rem_bt[10];
    

    printf("No .of processes -- ");
    scanf("%d",&n);

    printf("              BT -- ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);

        rem_bt[i]=bt[i];

    }
    printf("    Time quantum -- ");
    scanf("%d",&qt);

    while(1)
    {
        for(i=0,p_count=0;i<n;i++)
        {
            temp=qt;

            if (rem_bt[i]==0)
            {
                p_count++;
                continue;

            }
            if(rem_bt[i]>qt)
            {
                rem_bt[i]=rem_bt[i]-qt;
            }
            else
            {
                if(rem_bt[i]>=0)
                {
                    temp=rem_bt[i];
                    rem_bt[i]=0;
                }
                sq=sq+temp;
                tat[i]=sq;
            }
        }
        if(n==p_count)
        {
            break;
        }

    }
    printf("\nProcess\t BT \t TAT \t WT \n");

    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        
        awt=awt+wt[i];
        atat=atat+tat[i];

        printf("\n  %d \t %d \t%d \t%d \n",i+1,bt[i],tat[i],wt[i]);
    }
    awt = awt/n;
    atat = atat/n;
    printf("             awt -- %f\n",awt);
    printf("            atat -- %f\n",atat);

}
