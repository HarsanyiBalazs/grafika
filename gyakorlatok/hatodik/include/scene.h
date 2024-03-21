#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model cube;
    Material material;
    GLuint texture_id;
    double rot;
    float light_strength;
    float ambient_light_strength;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(float light_strength,float ambient_light_strength);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene,double time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void set_lighting_strength(Scene* scene,float light_strength);

#endif /* SCENE_H */
