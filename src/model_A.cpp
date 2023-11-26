#include "model_A.h"
#include "raymath.h"


Model floor_model;
Model model_A;
Model models[2] = {};

Image model_A_image = LoadImage("resources/textures/icot2.png");
//Image model_A_imageINV = LoadImage("resources/textures/icot2INV.png");
Image model_A_image_copy = ImageCopy(model_A_image);
//Image model_A_image_copyINV = ImageCopy(model_A_imageINV);
//int inv = 1;

int h = 256;
int w = 256;
Rectangle r_model_A = {222, 222, w, h};
int counter = 1;



void load_floor_model()
{
    floor_model = LoadModel("resources/models/floor.obj");
    Texture2D floor_texture = LoadTexture("resources/textures/t4.png");
    floor_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = floor_texture;
    models[0] = floor_model;
}

void load_model_A()
{
    model_A = LoadModel("resources/models/octo1.obj");
    Texture2D model_A_texture = LoadTexture("resources/textures/icot2.png");
    //Texture2D model_A_texture = LoadTextureFromImage(model_A_image_cropped);
    model_A.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = model_A_texture;
    models[1] = model_A;
}

void update_r_model_A()
{
    counter++; 
    r_model_A.x += sin(counter/57);
    r_model_A.y += sin(counter/34);
}


void update_model_A_texture()
{

    model_A_image_copy = ImageCopy(model_A_image);
    ImageCrop(&model_A_image_copy, r_model_A);
    Texture2D model_A_texture = LoadTextureFromImage(model_A_image_copy);
    model_A.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = model_A_texture;
    models[1] = model_A;

    /*inv += 1;
    if (inv%2 == 0)
    {
        model_A_image_copy = ImageCopy(model_A_image);
        ImageCrop(&model_A_image_copy, r_model_A);
        Texture2D model_A_texture = LoadTextureFromImage(model_A_image_copy);
        model_A.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = model_A_texture;
        models[1] = model_A;
    }
    else
    {
        Image model_A_image_copyINV = ImageCopy(model_A_imageINV);
        ImageCrop(&model_A_image_copyINV, r_model_A);
        Texture2D model_A_texture = LoadTextureFromImage(model_A_image_copyINV);
        model_A.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = model_A_texture;
        models[1] = model_A;
    }*/
}

