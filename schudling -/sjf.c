// CPU-Scheduling-Algorithm-In-C
// Shortest Job First(SJF) Scheduling Algorithm(Non Pre-emptive)

#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, pos, temp, *bt, *wt, *tat, *p;
	int *atarrival_time,*ar,bt_n;
	float avgwt = 0, avgtat = 0;
	printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    p = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
    atarrival_time  = (int*)malloc(n*sizeof(int)); 
    ar = (int*)malloc(n*sizeof(int));
 	
	printf("\n Enter the Arrival time for each process \n");
	for(i=0; i<n; i++)
	{
	    printf(" Arrival time for P%d : ", i);
        scanf("%d", &atarrival_time[i]);
	}
	
 	printf("\n Enter the burst time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        p[i] = i;
    }
    int z=1;
    for(int i=0;i<n;i++)
    {
		if(atarrival_time[i]>bt[0])
		{
			z++;
		}
    }
	
    for(i=z; i<n-(z-1); i++)
    {
    	pos = i;
    	for(j=i+1; j<n; j++)
    	{
    		if(bt[j] < bt[pos])
    		{
    			pos = j;
    		}
    	}
    	temp = bt[i];
    	bt[i] = bt[pos];
    	bt[pos] = temp;

    	temp = p[i];
    	p[i] = p[pos];
    	p[pos] = temp;
		
		temp = atarrival_time[i];
    	atarrival_time[i] = atarrival_time[pos];
    	atarrival_time[pos] = temp;
    }
	
    wt[0] = 0;
    tat[0] = bt[0];
    avgwt = wt[0];
    avgtat = tat[0];
	bt_n=bt[0];
	
    for(i=1; i<n; i++)
    {
        wt[i] = (bt_n)-atarrival_time[i]+atarrival_time[0];  //waiting time[p] = waiting time[p-1] + Burst Time[p-1]
        tat[i] = wt[i] + bt[i];           //Turnaround Time = Waiting Time + Burst Time
              
        bt_n+=bt[i];
        
        avgwt += wt[i];
        avgtat += tat[i];
    }

 
    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("____________________________________________________________\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", i, bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("__________________________\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], i, tat[i]);
    }
	
	
}
