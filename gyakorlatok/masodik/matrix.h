#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

void init_identity_matrix(float matrix[3][3]);

void multiply_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

void transform_point(const float a[3][3],float b[3]);

void scale(float b[3][3],float num);

void copy(float b[3][3],float c[3][3]);

void push(float b[3][3],float x,float y);

void rotate(float b[3][3],float num);

#endif // MATRIX_H

