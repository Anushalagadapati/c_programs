#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int truckTour(int petrolpumps_rows, int petrolpumps_columns, int** petrolpumps) 
{
    /*
     * Write your code here.
     */
        int tank=0,pump=0,i;
     for (i = 0; i < petrolpumps_rows;i++)
      { tank += petrolpumps[i][0] - petrolpumps[i][1];
       if(tank<0)
       {
       tank=0;
       pump=i+1;
      }
      }
      return pump;

}

main()
{
int petrolpumps_rows, petrolpumps_columns,i,j;
printf("enter rows and colo\n");
scanf("%d%d",&petrolpumps_rows, &petrolpumps_columns);
int ** petrolpumps=(int **)malloc(petrolpumps_rows*sizeof(int*));
for(i=0;i<petrolpumps_rows;i++)
petrolpumps[i]=(int *)malloc(petrolpumps_columns*sizeof(int));
printf("enter 2d\n");
for(i=0;i<petrolpumps_rows;i++)
for(j=0;j<petrolpumps_columns;j++)
scanf("%d",&petrolpumps[i][j]);
int res=truckTour(petrolpumps_rows, petrolpumps_columns, petrolpumps);
if(res>=petrolpumps_rows)
printf("not possible\n");
else
printf("%d\n",res);
}

