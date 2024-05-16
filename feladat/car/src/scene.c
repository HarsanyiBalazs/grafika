#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>

void init_car(Car* car)
{
    load_model(&(car->model_car), "assets/models/Porsche_911_GT2.obj");
    car->texture_idcar = load_texture("assets/textures/cartexture.png");
    car->texture_idwheel = load_texture("assets/textures/wheelskin.png");
    load_model(&(car->wheel), "assets/models/wheel12.obj");
    car->position.x = 0.0;
    car->position.y = 0.0;
    car->position.z = 0.0;
    car->rotation.x = 0.0;
    car->rotation.y = 0.0;
    car->rotation.z = 0.0;
    car->speed.x = 0.0;
    car->speed.y = 0.0;
    car->speed.z = 0.0;
    car->angle=0;
    car->light=0;
    car->wheelrotation=0;
    car->frontwheelrotation=0.0;

    
}

void init_scene(Scene* scene)
{
    load_model(&(scene->enviroment), "assets/models/grass23.obj");
    
    scene->texture_enviroment = load_texture("assets/textures/grasstexture.png");

    load_model(&(scene->enviroment2), "assets/models/WoodHouse.obj");
    
    scene->texture_enviroment2 = load_texture("assets/textures/house2.png");

    scene->preview=0;

    scene->material.ambient.red = 0.2;
    scene->material.ambient.green = 0.2;
    scene->material.ambient.blue = 0.2;

    scene->material.diffuse.red = 0.8;
    scene->material.diffuse.green = 0.8;
    scene->material.diffuse.blue = 0.8;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 60.0;
}

void set_lighting2(const Car* car)
{
    float ambient_light[] = { 0,0 , 0, 0};
    float diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = {0, 0,0, 1.0f };
    float rotation[] = {1, 0, 0};
    float cutoff=60;
    //float exponent = 20.0;

    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,rotation);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, cutoff);
    //glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, exponent);
    

    if(car->light==0)
    {
        glDisable(GL_LIGHT1);
    }
    else
    {
        glEnable(GL_LIGHT1);
    }

}

void set_lighting3(const Car* car)
{
    float ambient_light[] = { 0,0 , 0, 0};
    float diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = {0, 0,0, 1.0f };
    float rotation[] = {1, 0, 0};
    float cutoff=60;
    //float exponent = 20.0;


    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT2, GL_POSITION, position);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION,rotation);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, cutoff);
    //glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, exponent);
    

    if(car->light==0)
    {
        glDisable(GL_LIGHT2);
    }
    else
    {
        glEnable(GL_LIGHT2);
    }

}

void set_lighting(const Car* car)
{
    
    float ambient_light[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    float diffuse_light[] = { 0.3f, 0.3f, 0.5f, 1.0f };
    float specular_light[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    float position[] = { 10.0f, 10.0f, 100.0f, 1.0f };
    
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

void update_scene(Scene* scene,Car* car,double time)
{
    double angle;
    //double side_angle;

    angle = degree_to_radian(car->rotation.z);
    //side_angle = degree_to_radian(car->rotation.z + 90.0);
    
    int previousrotation=0;

    if(car->speed.y>0)
    {
        car->speed.y -= 0.6*time ;
    }
    else if (car->speed.y<0)
    {   
        car->speed.y +=0.6*time;
    }

    if(car->stop==1)
    {
        if(car->speed.y>0)
        {
            car->speed.y -= 20*time ;
        }
        else if (car->speed.y<0)
        {   
            car->speed.y +=2*time;
        }
        if(car->speed.y<1 && car->speed.y>-1)
        {
            car->speed.y=0;
        }
    }

    if(car->speed.y>=0.4 || car->speed.y<=-0.4)
    {
        if (car->angle==1)
        {
            car->rotation.z += 30*time;
            car->frontwheelrotation = 150*time;
            previousrotation=1;
        }
        else if (car->angle==-1)
        {
            car->rotation.z -= 30*time;
            car->frontwheelrotation = -150*time;
            previousrotation=-1;
        }
    }


    if (car->angle==0)
    {

        car->frontwheelrotation = 1*time;
        
    }



    if (car->rotation.z < 0) {
        car->rotation.z += 360.0;
    }

    if (car->rotation.z > 360.0) {
        car->rotation.z -= 360.0;
    }
    
    car->position.x += cos(angle) * car->speed.y * time;
    car->position.y += sin(angle) * car->speed.y * time;
    /*car->position.x += cos(side_angle) * car->speed.x * time;
    car->position.y += sin(side_angle) * car->speed.x * time;*/


    car->wheelrotation += car->speed.y*time*100;
    
    
    
}



void render_scene(const Scene* scene,const Car* car)
{
    

    set_material(&(scene->material));
    
    set_lighting(car);


    draw_origin();


    /*
    Draw the field
    */
    glPushMatrix();
    glTranslatef(0, 0, -1);
    glBindTexture(GL_TEXTURE_2D, scene->texture_enviroment);
    draw_model(&(scene->enviroment));
    glPopMatrix(); 


    /*
    Draw a house
    */
    glPushMatrix();
    glRotatef(90 , 1, 0, 0);
    glTranslatef(0, -1, -8);
    glScalef(1.2, 1.2, 1.2);
    glBindTexture(GL_TEXTURE_2D, scene->texture_enviroment2);
    draw_model(&(scene->enviroment2));
    glPopMatrix();


    /*
    Draw the car and its movement
    */
    glPushMatrix();
    glTranslatef(car->position.x,car->position.y,car->position.z);
    
    glRotatef(car->rotation.z , 0, 0, 1.0);

    glRotatef(-90 , 0, 0, 1.0);
    glRotatef(90 , 1, 0, 0);

    glBindTexture(GL_TEXTURE_2D, car->texture_idcar);
    draw_model(&(car->model_car));
    glPopMatrix(); 



    /*
    Draw the lamps
    */
    glPushMatrix();
    glTranslatef(car->position.x,car->position.y,car->position.z);
    glRotatef(car->rotation.z , 0, 0, 1.0);
    

    glTranslatef(1.9, 0.63, 0.1);
    set_lighting2(car);
    glTranslatef(0, -1.26, 0);
    set_lighting3(car);
    glPopMatrix();


    /*
    Draw frontleft wheel
    */
    glPushMatrix();
    
    glTranslatef(car->position.x,car->position.y,car->position.z);
    glRotatef(car->rotation.z , 0, 0, 1.0);
    
    glRotatef(90 , 0, 0, 1.0);
    glScalef(0.059, 0.059, 0.059);
    glTranslatef(14,-20,-5);
    glRotatef(car->frontwheelrotation , 0, 0, 1);
    glRotatef(car->wheelrotation , 1, 0, 0);


    glBindTexture(GL_TEXTURE_2D, car->texture_idwheel);
    draw_model(&(car->wheel));
    
    glPopMatrix();

    /*
    Draw frontright wheel
    */
    glPushMatrix();
    glTranslatef(car->position.x,car->position.y,car->position.z);
    glRotatef(car->rotation.z , 0, 0, 1.0);

    glRotatef(-90 , 0, 0, 1.0);
    glScalef(0.059, 0.059, 0.059);
    glTranslatef(14,20,-5);
    glRotatef(car->frontwheelrotation , 0, 0, 1);
    glRotatef(-car->wheelrotation , 1, 0, 0);
    

    glBindTexture(GL_TEXTURE_2D, car->texture_idwheel);
    draw_model(&(car->wheel));
    glPopMatrix();

    /*
    Draw backleft wheel
    */
    glPushMatrix();
    glTranslatef(car->position.x,car->position.y,car->position.z);
    glRotatef(car->rotation.z , 0, 0, 1.0);

    glRotatef(90 , 0, 0, 1.0);
    glScalef(0.059, 0.059, 0.059);
    glTranslatef(14,20,-5);
    glRotatef(car->wheelrotation , 1, 0, 0);

    glBindTexture(GL_TEXTURE_2D, car->texture_idwheel);
    draw_model(&(car->wheel));
    glPopMatrix();

    /*
    Draw backright wheel
    */
    glPushMatrix();
    glTranslatef(car->position.x,car->position.y,car->position.z);
    glRotatef(car->rotation.z , 0, 0, 1.0);
    
    glRotatef(270 , 0, 0, 1.0);
    glScalef(0.059, 0.059, 0.059);
    glTranslatef(14,-20,-5);
    glRotatef(-car->wheelrotation , 1, 0, 0);

    glBindTexture(GL_TEXTURE_2D, car->texture_idwheel);
    draw_model(&(car->wheel));
    glPopMatrix();



    if(scene->preview==1){
    show_texture_preview();}


}



void set_car_speedy(Car* car, float speed)
{

    if(car->speed.y<30 && speed>0 )
    {
        car->speed.y += speed;
    }
    else if (car->speed.y>-6 && speed<0 )
    {
        car->speed.y += speed;
    }
    
}

void set_car_rotationz(Car* car, float angle)
{

    car->angle = angle;
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
