#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Brick
{
    double a;
    double b;
    double c;

} Brick;


void set_size(Brick* brick,double a,double b, double c)
{
    brick->a = a;
    brick->b = b;
    brick->c = c;
    return ;
}

double calc_volume(const Brick* brick)
{
    double volume = brick->a * brick->b * brick->c ;
    return volume;
}

double calc_surface(const Brick* brick)
{
    double surface=( 2*(brick->a * brick->b )+2*(brick->a * brick->c ) + 2*(brick->b * brick->c ));
    return surface;
}

int  check_square_side(const Brick* brick)
{

    if(brick->a == brick->b)
    {
        return 1;
    }
    else if(brick->a == brick->c)
    {
        return 1;
    }
    else if(brick->b == brick->c)
    {
        return 1;
    }
    return 0;


}



int main()
{
    Brick brick;
    double volume;
    double surface;
    int squareside;

    set_size(&brick,2,5,3);
    volume = calc_volume(&brick);
    surface = calc_surface(&brick);
    squareside=check_square_side(&brick);

    if(squareside)
    {
        printf("van negyzet alaku oldala\n");
    }
    else
    {
        printf("nincs negyzet alaku oldala\n");
    }

    printf("volume:%lf\n surface:%lf",volume,surface);

    return 0;
}
