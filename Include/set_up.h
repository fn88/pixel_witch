#pragma once
#include "raylib.h"
#include "raymath.h"
#include "ui.h"


extern int S_W;
extern int S_H;
extern int font_size;
extern int FPS;
extern int FPS_counter;

extern Camera cam;
extern float cam_theta;
extern float cam_phi;
extern float prev_cam_theta;
extern float prev_cam_phi;
extern float cam_speed;

extern bool mouse_mode_3D;
extern bool mouse_mode_ui;
extern float mouse_sensitivity;
extern int mousePosX;
extern int mousePosY;
extern int mouseDistX;
extern int mouseDistY;
extern float mouse_theta; 
extern float mouse_phi;


void set_up_window();
//void load_fonts();
void set_up_mouse();
void set_up_ui();
void set_up_cam();

void set_up();
