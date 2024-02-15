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
    scanf("%lf",&x);
    scanf("%lf",&y);
    scanf("%lf",&z);
    printf("%lf %lf %lf",x,y,z);
    if( !(isdigit(x)) || !(isdigit(y)) || !(isdigit(z)) )
    {
        printf("not a number");
        return;
    }
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
    printf("surface= %lf",surface);
    
}

void calc_volume(Brick* brick)
{
    double volume = 0;
    double x= brick->a;
    double y= brick->b;
    double z= brick->c;
    volume= x*z*y;
    printf("volume= %lf",volume);
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