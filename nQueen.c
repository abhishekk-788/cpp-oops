#include <stdio.h>
#include <string.h>

int N;
int cnt = 0;

int isSafe(char mat[][N], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (mat[i][c] == 'Q') {
            return 0;
        }
    }

    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j] == 'Q') {
            return 0;
        }
    }

    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
    {
        if (mat[i][j] == 'Q') {
            return 0;
        }
    }
 
    return 1;
}
 
void printSolution(char mat[][N])
{
	cnt++;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
 
void nQueen(char mat[][N], int r)
{
    if (r == N)
    {
        printSolution(mat);
        return;
    }
    
    for (int i = 0; i < N; i++)
    {
        if (isSafe(mat, r, i))
        {
            mat[r][i] = 'Q';
            nQueen(mat, r + 1);
            mat[r][i] = '-';
        }
    }
}
 
int main()
{
	while(1) 
	{
		cnt = 0;
		
		printf("Enter the value for N: ");
		scanf("%d", &N);
		
		char mat[N][N];
	    memset(mat, '-', sizeof mat);
	 
	    nQueen(mat, 0);
	    
	    printf("Total Number of Solutions: %d\n\n", cnt);
	    
	}
    
    return 0;
}

