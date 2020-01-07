/* Mean calculation of a 2D Matrix and creation of a binary matrix
Name: Souradip Nath
Enrollment No. : 510818009
Inputs Taken: The no of row and columns m,n
Outputs shown: The mean of the elements and the binary matrix*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int m,n,i,j,N;
    printf("Enter the no of rows and columns: ");
    scanf("%d %d",&m,&n);
    printf("Enter the range 'n': ");
    scanf("%d",&N);
    int a[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            a[i][j] = rand()% ((int)pow(2,N)+1);
    }
    printf("The given matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    int sum=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            sum+=a[i][j];
    }
    float mean = (float)sum/(m*n);
    printf("The mean is: %4.2f\n",mean);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if((float)a[i][j] > mean)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    printf("The Binary matrix is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
