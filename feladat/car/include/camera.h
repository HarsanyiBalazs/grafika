#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

#include <stdbool.h>

/**
 * Camera, as a moving point with direction
 */
typedef struct Camera
{
    vec3 position;
    vec3 rotation;
    vec3 speed;
    bool is_preview_visible;
    vec3 rotation_movement;
    int angle;
    
    int stop;
} Camera;

/**
 * Initialize the camera to the start position.
 */
void init_camera(Camera* camera);

/**
 * Update the position of the camera.
 */
void update_camera(Camera* camera, double time);

/**
 * Apply the camera settings to the view transformation.
 */
void set_view(const Camera* camera);

/**
 * Set the horizontal and vertical rotation of the view angle.
 */
void rotate_camera(Camera* camera, double horizontal, double vertical);

/**
 * Set the speed of forward and backward motion.
 */
void set_camera_speed(Camera* camera, double speed);

/**
 * Set the speed of left and right side steps.
 */
void set_camera_side_speed(Camera* camera, double speed);

/**
 * Show a texture on the screen.
 */
void show_texture_preview();

/**
 * Set the speed of forward and backward motion thats aligned with the cars.
 */
void set_camera_speedy(Camera* camera, float speed);

/**
 * Set the cameras rotation around the z axis.
 */
void set_camera_rotationz(Camera* camera, float angle);

#endif /* CAMERA_H */
