#include "camera.h"

#include <GL/gl.h>

#include <math.h>

void init_camera(Camera* camera)
{
    camera->position.x = 0.0;
    camera->position.y = 0.0;
    camera->position.z = 0.0;
    camera->rotation.x = 45.0;
    camera->rotation.y = 0.0;
    camera->rotation.z = 180.0;
    camera->speed.x = 0.0;
    camera->speed.y = 0.0;
    camera->speed.z = 0.0;
    camera->rotation_movement.x = -30.0;
    camera->rotation_movement.y = 0.0;
    camera->rotation_movement.z = 0.0;
    camera->angle=0;
    camera->is_preview_visible = false;
}

void update_camera(Camera* camera, double time)
{
    double angle;
    double side_angle;

    angle = degree_to_radian(camera->rotation_movement.z);
    side_angle = degree_to_radian(camera->rotation_movement.z + 90.0);

    
    if(camera->speed.y>0)
    {
        camera->speed.y -= 0.6*time ;
    }
    else if (camera->speed.y<0)
    {   
        camera->speed.y +=0.6*time;
    }

    if(camera->stop==1)
    {
        if(camera->speed.y>0)
        {
            camera->speed.y -= 20*time ;
        }
        else if (camera->speed.y<0)
        {   
            camera->speed.y +=2*time;
        }
        if(camera->speed.y<1 && camera->speed.y>-1)
        {
            camera->speed.y=0;
        }
    }

    if(camera->speed.y>=0.4 || camera->speed.y<=-0.4)
    {
        if (camera->angle==1)
        {
            camera->rotation_movement.z += 30*time;
        }
        else if (camera->angle==-1)
        {
            camera->rotation_movement.z -= 30*time;
        }
    }

    if (camera->rotation_movement.z < 0) {
        camera->rotation_movement.z += 360.0;
    }

    if (camera->rotation_movement.z > 360.0) {
        camera->rotation_movement.z -= 360.0;
    }


    camera->position.x += cos(angle) * camera->speed.y * time;
    camera->position.y += sin(angle) * camera->speed.y * time;
    camera->position.x += cos(side_angle) * camera->speed.x * time;
    camera->position.y += sin(side_angle) * camera->speed.x * time;
}

void set_view(const Camera* camera)
{   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glRotatef(-(camera->rotation.x ), 1.0, 0, 0);

    glTranslatef(0, 6, -2.5);
    glRotatef(-(camera->rotation_movement.z - 90), 0, 0, 1.0);
    glRotatef(-(camera->rotation.z -180), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);

}

void rotate_camera(Camera* camera, double horizontal, double vertical)
{
    camera->rotation.z += horizontal;
    camera->rotation.x += vertical;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }
}

void set_camera_speed(Camera* camera, double speed)
{
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed)
{
    camera->speed.x = speed;
}

void show_texture_preview()
{
    GLuint texture_tutorial =load_texture("assets/textures/guide2.png");
    glBindTexture(GL_TEXTURE_2D,texture_tutorial );

    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1, 1, -3);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1, -3);
    glTexCoord2f(1, 1);
    glVertex3f(1, -1, -3);
    glTexCoord2f(0, 1);
    glVertex3f(-1, -1, -3);
    glEnd();
    
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

}

void set_camera_speedy(Camera* camera, float speed)
{
    
    if(camera->speed.y<30 && speed>0 )
    {
        camera->speed.y += speed;
    }
    else if (camera->speed.y>-6 && speed<0 )
    {
        camera->speed.y += speed;
    }
    
}

void set_camera_rotationz(Camera* camera, float angle)
{

    camera->angle = angle;
}