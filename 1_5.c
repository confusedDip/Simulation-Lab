/* 3x3 segmentation of a 2D Matrix
Name: Souradip Nath
Enrollment No. : 510818009
Inputs Taken: The no of row and columns m,n
Outputs shown: The 3x3 non overlapping blocks
                The 3x3 binary blocks*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m,n,i,j,k,l;
    printf("Enter the no of rows and columns: ");
    scanf("%d %d",&m,&n);
    int a[m][n];
    //printf("Enter the elements:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            //scanf("%d",&a[i][j]);
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
        for(i=0;i<num;i++)
        {
            int key = blocks[i][1][1];
            for(j=0;j<3;j++)
            {
                for(k=0;k<3;k++)
                {
                    if(blocks[i][j][k]>key)
                        blocks[i][j][k]=1;
                    else
                        blocks[i][j][k]=0;
                }
            }
        }
        printf("The binary blocks are:\n");
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
    }
}
