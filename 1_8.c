/* Frequency calculation of the elements of a random 2D Matrix
Name: Souradip Nath
Enrollment No. : 510818009
Inputs Taken: The no of row and columns m,n
Outputs shown: The random matrix with elements in [0,255]
                The frequency of elements*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m,n,i,j;
    printf("Enter the no of rows and columns: ");
    scanf("%d %d",&m,&n);
    int a[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            a[i][j] = rand()%256;
            //random function to populate the matrix with [0,255]
    }
    printf("The random matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    int count[256]={0};
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            count[a[i][j]]++;
        }
    }
    printf("The frequency of occurrence:\n");
    for(i=0;i<256;i++)
    {
        if(count[i]!=0)
            printf("%d occurs %d time(s)!\n",i,count[i]);
    }
}
