#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

typedef struct dataset
{
    float x, y;
    int cluster;
}data;

float distance(data a, data b)
{
    float d = pow(a.x-b.x,2)+pow(a.y-b.y,2);
    return sqrt(d);
}

data calculateNewMean(data point[], int c, int n)
{
    data sum, avg;
    
	sum.x = sum.y = 0;
    avg.x = avg.y = 0;
    
	int len = 0, i;
    for(i = 0; i < n; i++)
	{
        if(point[i].cluster == c)
		{
            len++;
            sum.x += point[i].x;
            sum.y += point[i].y;
        }
    }
    if(len>0)
	{
        avg.x = sum.x/len;
        avg.y = sum.y/len;
    }
    return avg;
}

int main()
{
    data point[10];
    data centroid1, centroid2;
    data mean1, mean2;
    int itr = 0, i, j;
    int n;
    srand(time(0));

    printf("Enter the size of data points: ");
    scanf("%d",&n);

    printf("\nEnter data points\n");
    for(i=0;i<n;i++)
        scanf("%f %f",&point[i].x,&point[i].y);


    float thres;
    printf("\nEnter the threshold: ");
    scanf("%f", &thres);


    printf("\nGiven Points are\n");
    for(i=0;i<n;i++)
	{
        printf("%d -> (%0.2f , %0.2f) \n", (1 + i),  point[i].x, point[i].y);
    }

    int random1 = rand() % n;
    int random2= rand() % n;
    
	while(random2 == random1)
        random2 = rand() % n;

    centroid1.x=point[random1].x;
    centroid1.y=point[random1].y;
    centroid2.x=point[random2].x;
    centroid2.y=point[random2].y;
    
	float prev_c_x = centroid1.x;
    mean1.x=0.0; mean1.y=0.0;
    mean2.x=0.0; mean2.y=0.0;

    printf("\n------- Given Centroids are -------- \n");
    printf("C1 -> (%0.2f, %0.2f)\n", centroid1.x, centroid1.y);
    printf("C2 -> (%0.2f, %0.2f)\n", centroid2.x, centroid2.y);

    float diff = 1000000.0;
    while(diff > thres)
	{
        prev_c_x = centroid1.x;
        
		mean1 = centroid1;
        mean2 = centroid2;
        
		for(j=0;j<n;j++)
		{

            if(distance(mean1,point[j])<distance(mean2,point[j]))
            {
                point[j].cluster=0;
            }
            else{
                point[j].cluster=1;
            }
        }
        
		centroid1=calculateNewMean(point,0,n);
        centroid2=calculateNewMean(point,1,n);
        
        if(prev_c_x >= centroid1.x)
        {
        	diff = prev_c_x - centroid1.x;
		}
		else diff = centroid1.x - prev_c_x;
        
        itr++;
    }
    printf("\nTotal Number of Iterations : %d\n\n", itr);

    printf("Centroid of Cluster 1 are: ( %0.2f , %0.2f )\n",centroid1.x,centroid1.y);

    printf("\n----- Points Belonging to cluster 1 -----\n");
    for(i = 0; i < n; i++)
    {
        if(point[i].cluster == 0)
            printf("(%0.2f , %0.2f) \n", point[i].x, point[i].y);
    }

    printf("\nCentroid of Cluster 2 are: (%0.2f , %0.2f)\n\n",centroid2.x,centroid2.y);

    printf("----- Points Belonging to cluster 2 -----\n");
    for(i = 0; i < n; i++)
    {
        if(point[i].cluster == 1) printf("(%0.2f , %0.2f) \n", point[i].x, point[i].y);
    }
    
    return 0;
}

/*

1.5 2.0
3.9 5.1
3.0 4.0
1000.9 1011.7
4.5 4.7
4.2 4.3
1.2 1.4
25.4 45.6
24.8 41.3
14.7 25.9

*/
