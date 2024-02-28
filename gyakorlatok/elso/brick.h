typedef struct Brick{
    double a;
    double b;
    double c;
} Brick;

void set_brick_data(Brick* brick);

void calc_volume(Brick* brick);

void calc_surface(Brick* brick);

void is_there_square(Brick* brick);