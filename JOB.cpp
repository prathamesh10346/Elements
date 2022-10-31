#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000000

typedef struct Job
{
    int id;
    int deadline;
    int profit;
}   Job;


int min(int x, int y) 
{
    if(x < y) 
    {
        return x;
    }
    return y;
}

void sequence(Job jobs[], int n)
{
    int i, j, k, profit,times[MAX],totaltime = 0,maxtime = 0;
    for(i = 0; i < n; i++) 
    {
        if(jobs[i].deadline > maxtime) 
        {
            maxtime = jobs[i].deadline;
        }
    }
    for(i = 1; i <= maxtime; i++) 
    {
        times[i] = -1;
    }
    for(i = 1; i <= n; i++) 
    {
        k = min(maxtime, jobs[i - 1].deadline);
        while(k >= 1) 
        {
            if(times[k] == -1) 
            {
                times[k] = i-1;
                totaltime++;
                break;
            }
        k--;
        }
        if(totaltime == maxtime) 
        {
            break;
        }
    }
    printf("\nRequired Jobs: ");
    for(i = 1; i <= maxtime; i++) 
    {
        printf("%d", jobs[times[i]].id);
        if(i < maxtime) 
        {
        printf(" --> ");
        }
    }
    profit = 0;
    for(i = 1; i <= maxtime; i++) 
    {
        profit += jobs[times[i]].profit;
    }
    printf("\nMax Profit: %d\n", profit);
}

void main() 
{
    int i, j,s;
    printf("Enter the number of Jobs:");
    scanf("%d",&s);
    Job jobs[s];
    printf("Enter the Deadline and Profit of the Jobs:\n");
    for(int o=0;o<s;o++)
    {
        jobs[o].id=o+1;
        jobs[o].deadline=rand()%s;
        jobs[o].profit=rand()%200;
        //scanf("%d",&jobs[o].deadline);
        //scanf("%d",&jobs[o].profit);
        //printf("\n");
    }
  Job temp;
  for(i = 1; i < s; i++) 
  {
    for(j = 0; j < s - i; j++) 
    {
      if(jobs[j+1].profit > jobs[j].profit) 
      {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }
  printf("Job   Deadline    Profit\n");
  for(i = 0; i < s; i++) 
  {
    printf("%d        %d          %d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }
  sequence(jobs, s);
}