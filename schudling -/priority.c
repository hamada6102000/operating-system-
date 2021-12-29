// CPU-Scheduling-Algorithm-In-C
// Non Pre-emptive Priority Scheduling Algorithm

#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, pos, temp, *bt, *wt, *tat, *p, *pt;
	int *arrival_time,bt_n;
	float avgwt = 0, avgtat = 0;
	printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    p = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int));
    pt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
    arrival_time  = (int*)malloc(n*sizeof(int));
 	
 	printf("\n Enter the burst time and priority and Arrival time for each process ");
    for(i=0; i<n; i++)
    {
		printf("\n Arrival time for P%d : ", i);
        scanf("%d", &arrival_time[i]);    
        printf(" Burst time of P%d : ", i);
        scanf("%d", &bt[i]);
        printf(" Priority of P%d : ", i);
        scanf("%d", &pt[i]);
        p[i] = i;
    }
	bt_n=bt[0];
    int z=1;
    for(int i=0;i<n;i++)
    {
		if(arrival_time[i]>bt[0])      
		{
			z++;
		}
    }
	printf("x=%d",z);
    for(i=z; i<n; i++)
    {
    	pos = i;
    	for(j=i+1; j<n; j++)
    	{
    		if(pt[j] < pt[pos])
    		{
    			pos = j;
    		}
    	}
    	temp = pt[i];
    	pt[i] = pt[pos];
    	pt[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

    	temp = p[i];
    	p[i] = p[pos];
    	p[pos] = temp;
		
		temp = arrival_time[i];
    	arrival_time[i] = arrival_time[pos];
    	arrival_time[pos] = temp;
    }

    wt[0] = 0;
    tat[0] = bt[0];
    avgwt = wt[0];
    avgtat = tat[0];
	
     for(i=1; i<n; i++)
    {
 wt[i] = (bt_n)-arrival_time[i]+arrival_time[0]; //waiting time[p]=waiting time[p-1] + Burst Time[p-1]
        tat[i] = wt[i] + bt[i];           //Turnaround Time = Waiting Time + Burst Time
              
        bt_n+=bt[i];
        
        avgwt += wt[i];
        avgtat += tat[i];
    }
   
    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\n PROCESS \t PRIORITY \t BURST TIME \t Arrival TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i], pt[i], bt[i],arrival_time[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("---------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
}
