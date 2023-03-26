#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Point
{
    double x;
    double y;
} Point;

void set_point_data(Point* point,double i,double j)
{
    point->x = i;
    point->y = j;
    return;
}

void shift_point(Point* point,double i,double j)
{
    point->x = i + point->x;
    point->y = j + point->y;
    return;
}

void rotate_point(Point* point,double alpha)
{
    double i = point->x;
    double j = point->y;
    point->x = i*cos(alpha) + j*(-sin(alpha));
    point->y = i*sin(alpha) + j*cos(alpha);
    return;
}

void scale_point(Point* point,double i,double j)
{
    point->x = point->x * i;
    point->y = point->y * j;
    return;

}

int main()
{
    Point point;
    set_point_data(&point,4,4);

    printf("x:%lf y:%lf \n",point.x,point.y);

    shift_point(&point,1,2);

    printf("x:%lf y:%lf \n",point.x,point.y);

    scale_point(&point,2,1);

    printf("x:%lf y:%lf \n",point.x,point.y);


    rotate_point(&point,0);

    printf("x:%lf y:%lf \n",point.x,point.y);

    return 0;
}
