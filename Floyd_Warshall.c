#include <stdio.h>
#define INF 999

int n = 3;
void floydWarshall(int graph[][3]) 
{
  
  	int matrix[n][n], i, j, k;
  
  	printf("Given Array\n");
  	for (i = 0; i < n; i++) 
	{
    	for (j = 0; j < n; j++)
    	{
      		matrix[i][j] = graph[i][j];
      		
			if (matrix[i][j] == INF) printf("%4s", "INF");
	      	else printf("%4d", matrix[i][j]);
  		}
  		printf("\n");
	}

	int x = 1;
  	for (k = 0; k < n; k++) 
	{
		printf("A%d Step\n", x++);
    	for (i = 0; i < n; i++) 
		{
      		for (j = 0; j < n; j++) 
			{
        		if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          		matrix[i][j] = matrix[i][k] + matrix[k][j];
          	}
        }
        for (int i = 0; i < n; i++) 
		{
	    	for (int j = 0; j < n; j++) 
			{
	      		if (matrix[i][j] == INF) printf("%4s", "INF");
	      		
				else printf("%4d", matrix[i][j]);
	    	}
	    	printf("\n");
	  	}
    }  	
}

int main() {
  
  int graph[n][n] = 
  			{{0, 4, 11},
             {6, 0, 2},
             {3, INF, 0}};
  
  floydWarshall(graph);
}
