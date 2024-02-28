#include "matrix.h"
#include <math.h>
#include <stdio.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if(i==j)
            {
                matrix[i][j]=1.0;
            }else{
            matrix[i][j] = 0.0;
            }
        }
    }
}

void multiply_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;
    int k;
    float sum;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            sum=0;
            for(k=0;k<3;k++)
            {
                sum= sum+ a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }

    }
}

void transform_point(const float a[3][3],float b[3])
{
    int i;
    int k;
    float sum;
    float c[3];
    
    for(i=0;i<3;i++)
    {
        sum=0;
        for(k=0;k<3;k++)
        {
            sum= sum+ a[i][k]*b[k];
        }
        c[i]=sum;
    }
    for(i=0;i<3;i++)
    {
        b[i]=c[i];
    }
}

void scale(float b[3][3],float num)
{
    float a[3][3];
    float c[3][3];
    init_identity_matrix(a);

    a[0][0]=num;
    a[1][1]=num;

    multiply_matrices(a,b,c);
    copy(b,c);

}

void copy(float b[3][3],float c[3][3])
{
    int i;
    int j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            b[i][j]=c[i][j];
        }
    }
}

void push(float b[3][3],float x,float y)
{
    float a[3][3];
    float c[3][3];
    init_identity_matrix(a);

    a[0][2]=x;
    a[1][2]=y;

    multiply_matrices(a,b,c);
    copy(b,c);
}

void rotate(float b[3][3],float num)
{
    float a[3][3];
    float c[3][3];
    init_identity_matrix(a);

    a[0][0]=cos(num);
    a[0][1]=sin(num);
    a[1][0]=-sin(num);
    a[1][1]=cos(num);

    multiply_matrices(a,b,c);
    copy(b,c);

}