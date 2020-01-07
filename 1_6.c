/* 3x3 segmentation of a 2D Matrix and determining the average matrix
Name: Souradip Nath
Enrollment No. : 510818009
Inputs Taken: The no of row and columns m,n
Outputs shown: The 3x3 non overlapping blocks
                The average matrix*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m,n,i,j,k,l;
    printf("Enter the no of rows and columns: ");
    scanf("%d %d",&m,&n);
    int a[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=rand()%11;
        }
    }
    printf("The given matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    if(m<3 || n<3)
        printf("There are no 3x3 block!\n");
    else
    {
        int v_num = m/3;
        int h_num = n/3;
        int num = v_num*h_num;
        int blocks[num][3][3];
        int p=0;
        // segmentation in 3x3 non overlapping matrices
        for(i=0;i<h_num;i++)
        {
            for(j=0;j<v_num;j++)
            {
                for(k=j*3;k<(j+1)*3;k++)
                {
                    for(l=i*3;l<(i+1)*3;l++)
                    {
                        blocks[p][k%3][l%3]=a[k][l];
                    }
                }
                p++;
            }
        }
        printf("The blocks are:\n");
        for(i=0;i<num;i++)
        {
            for(j=0;j<3;j++)
            {
                for(k=0;k<3;k++)
                {
                    printf("%d ",blocks[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }
        float avergae_matrix [v_num][h_num];
        l=0,p=0;
        // determining the average matrix
        for(i=0;i<num;i++)
        {
            int sum=0;
            for(j=0;j<3;j++)
            {
                for(k=0;k<3;k++)
                {
                    sum+=blocks[i][j][k];
                }
            }
            avergae_matrix[l++][p]=(float)sum/9;
            if(l==v_num)
            {
                l=0;
                p++;
            }
        }
        printf("The average matrix:\n");
        for(i=0;i<v_num;i++)
        {
            for(j=0;j<h_num;j++)
            {
                printf("%4.2f ",avergae_matrix[i][j]);
            }
            printf("\n");
        }
        printf("Size of the average matrix: %d\n",num);
    }
}
