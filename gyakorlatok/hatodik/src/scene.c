#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "assets/models/duck.obj");
    scene->texture_id = load_texture("assets/textures/duck.jpg");

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 0.2;
    scene->material.ambient.green = 0.2;
    scene->material.ambient.blue = 0.2;

    scene->material.diffuse.red = 0.0;
    scene->material.diffuse.green = 0.9;
    scene->material.diffuse.blue = 0.9;

    scene->material.specular.red = 0.4;
    scene->material.specular.green = 0.4;
    scene->material.specular.blue = 0.4;

    scene->material.shininess = 0.4;

    scene->rot=0;
    scene->light_strength=0.5;
    scene->ambient_light_strength=0;
}

void set_lighting(float light_strength,float ambient_light_strength)
{
    float ambient_light[] = { 0.0f, 0.0f, ambient_light_strength, 1.0f };
    float diffuse_light[] = { light_strength, light_strength, light_strength, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene,double time)
{
    scene->rot += time*5;
    static float increase_light =0.1;
    scene->ambient_light_strength += time*increase_light;
    printf("%f\n",scene->ambient_light_strength);
    if( scene->ambient_light_strength>1 || scene->ambient_light_strength<0)
    {
        increase_light= increase_light*(-1);
    }
}

void set_lighting_strength(Scene* scene,float light_strength)
{
    if(!((light_strength>0 && scene->light_strength >= 1.0)||(light_strength<0 && scene->light_strength <= 0)))
    {scene->light_strength+=light_strength; }
}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting(scene->light_strength,scene->ambient_light_strength);
    draw_origin();
    glScalef(0.1,0.1,0.1);
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {

            glPushMatrix();
            glTranslatef(i*2,j*2,0);
            if((i+j)%2)
            {
                glRotatef(scene->rot,0,0,1);
            }else
            {
                glRotatef(-(scene->rot),0,0,1);
            }
            draw_model(&(scene->cube));
            glPopMatrix();
        }
        
    }

}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
