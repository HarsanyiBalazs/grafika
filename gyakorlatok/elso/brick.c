#include "brick.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void set_brick_data(Brick* brick)
{
    double x;
    double y;
    double z;
    int ok;
    char c;

    do{
        ok=1;
        printf("type 3 numbers\n");
        if(scanf("%lf %lf %lf",&x,&y,&z) !=3 )
        {
            printf("wrong data\n");
            while((c=getchar()) != '\n');
            ok=0;
        }else if(x<=0 || y<=0 || z<=0)
        {
            printf("wrong data\n");
            while((c=getchar()) != '\n');
            ok=0;
        }
    }while(!ok);

    brick->a = x;
    brick->b = y;
    brick->c = z;
}

void calc_surface(Brick* brick)
{
    double surface = 0;
    double x= brick->a;
    double y= brick->b;
    double z= brick->c;
    surface= 2*(x*y+x*z+y*z);
    printf("surface= %lf\n",surface);
    
}

void calc_volume(Brick* brick)
{
    double volume = 0;
    double x= brick->a;
    double y= brick->b;
    double z= brick->c;
    volume= x*z*y;
    printf("volume= %lf\n",volume);
}

void is_there_square(Brick* brick)
{
    double x= brick->a;
    double y= brick->b;
    double z= brick->c;
    if(x==y||x==z||y==z)
    {
        printf("there is a square side");
        return;
    }
    printf("there is no square side");
}