#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include <math.h>
#include "utils.h"

#include <obj/model.h>

typedef struct Scene
{
    Model enviroment;
    GLuint texture_enviroment;
    Model enviroment2;
    GLuint texture_enviroment2;
    Material material;
    int preview;

} Scene;

typedef struct Car
{
    Model model_car;
    GLuint texture_idcar;
    Model wheel;
    GLuint texture_idwheel;
    float movex_car;
    vec3 position;
    vec3 rotation;
    vec3 speed;
    int angle;
    int light;

    int wheelrotation;
    float frontwheelrotation;
    int stop;
} Car;



/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);


/**
 * Load car model and initialize its variables .
 */
void init_car(Car* car);

/**
 * Set the cars speed.
 */

void set_car_speedy(Car* car, float speed);

/**
 * Set the cars rotation around the z axis.
 */

void set_car_rotationz(Car* car, float angle);

/**
 * Set the cars left front light.
 */

void set_lighting2(const Car* car);

/**
 * Set the cars right front light.
 */

void set_lighting3(const Car* car);

/**
 * Set the lighting of the scene.
 */
void set_lighting(const Car* car);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene,Car* car,double time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene,const Car* car);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
