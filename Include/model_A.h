#pragma once
#include "raylib.h"


extern Model floor_model;
extern Model model_A;
extern Model models[];

extern Image model_A_image;
extern Image model_A_image_copy;
extern Rectangle r_model_A;

void load_floor_model();
void load_model_A();
void update_r_model_A();
void update_model_A_texture();

