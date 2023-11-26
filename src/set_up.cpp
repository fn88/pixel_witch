#include "set_up.h"
#include "time.h"


int S_W = 1920; // = GetMonitorWidth(0)/4;
int S_H = 1080; // = (GetMonitorHeight(0))/4;
int font_size = 20;
int FPS = 60;

Camera cam = { 0 };
float cam_theta;
float cam_phi;
float prev_cam_theta;
float prev_cam_phi;
float cam_speed;

bool mouse_mode_3D;
bool mouse_mode_ui;
float mouse_sensitivity;
int mousePosX;
int mousePosY;
int mouseDistX;
int mouseDistY;
float mouse_theta; 
float mouse_phi;

bool main_ui_open = true;


void set_up_window()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT); 
    InitWindow(S_W, S_H, "3DGIF");
    SetMousePosition(S_W/2.0f, S_H/2.0f);
    HideCursor();
    SetTargetFPS(FPS);
    //InitAudioDevice();
}

//void load_fonts()

void set_up_mouse()
{
    mouse_mode_3D = false;
    mouse_mode_ui = true;
    mouse_sensitivity = 3.0f;
    mousePosX = GetMouseX();
    mousePosY = GetMouseY();
    mouseDistX = mouse_sensitivity * (mousePosX - (S_W/2.0f));
    mouseDistY = mouse_sensitivity * (mousePosY - (S_H/2.0f));
    SetMousePosition(S_W/2, S_H/2);
    mouse_theta = mouseDistX/(S_W/2) * (cam.fovy/2) * DEG2RAD; 
    mouse_phi = mouseDistY/(S_H/2) * (cam.fovy/2) * DEG2RAD;
}

void set_up_cam()
{
    cam.fovy = 40.0f;
    cam.up = {0.0f, 0.0f, 1.0f};
    cam.projection = CAMERA_PERSPECTIVE;
    cam.position = {10.0f, 10.0f, 10.0f};
    cam.target = {0.0f, 0.0f, 0.0f};
    cam_theta = 0.0f;
    cam_phi = 0.0f;
    prev_cam_theta = 0.0f;
    prev_cam_phi = 0.0f;
    cam_speed = 1.0f;
}

void set_up_ui()
{
    set_up_main_ui();
    set_up_main_ui_menu_bar();
    set_up_file_ddm();
}


void set_up()
{
    set_up_window();
    //load_fonts();
    set_up_mouse();
    set_up_ui();
    set_up_cam();
}


