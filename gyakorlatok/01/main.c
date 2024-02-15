#include <stdio.h>
#include "brick.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char* argv[])
{
    Brick brick;

    set_brick_data(&brick);
    if((!isdigit(brick.a))||(!isdigit(brick.b))||(!isdigit(brick.c)))
    {
        return 0;
    };

    calc_surface(&brick);
    calc_volume(&brick);
    is_there_square(&brick);

    return 1;

}