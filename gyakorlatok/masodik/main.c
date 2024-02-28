#include "matrix.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);
    print_matrix(b);
    
    add_matrices(a, b, c);

    print_matrix(c);

    printf("\n");

    float d[3][3];

    init_identity_matrix(d);

    print_matrix(d);

    float e[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
    float f[3][3] = {
        { -1.0f, 7.0f,  3.0f},
        { 5.0f, 2.4f,  -0.4f},
        {-2.0f,  1.0f, 2.0f}
    };

    float g[3][3];

    multiply_matrices(e,f,g);
    printf("\n");
    print_matrix(g);
    printf("\n");


    float h[3]={1.0f, -2.0f,  1.0f};
    float m[3][3] = {
        { 1.0f, 0.0f,  2.0f},
        { 0.0f, 1.0f,  2.0f},
        { 0.0f,  0.0f, 1.0f}
    };

    transform_point(m,h);

    for(i=0;i<3;i++){
        printf("%4.4f ",h[i] );
    }
    printf("\n\n");

    scale(m,3);
    print_matrix(m);
    printf("\n\n");

    push(m,-2,-1);
    print_matrix(m);
    printf("\n\n");

    rotate(m,30);
    print_matrix(m);
    printf("\n\n");

	return 0;

}

