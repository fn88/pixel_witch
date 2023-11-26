#include "update.h"



void update_mouse()
{
    if (mouse_mode_3D)
    {
        HideCursor();
        mousePosX = GetMouseX();
        mousePosY = GetMouseY();
        mouseDistX = mouse_sensitivity * (mousePosX - (S_W/2));
        mouseDistY = mouse_sensitivity * (mousePosY - (S_H/2));
        SetMousePosition(S_W/2, S_H/2);
        mouse_theta = mouseDistX/(S_W/2.0f) * (cam.fovy/2.0f) * DEG2RAD; 
        mouse_phi = mouseDistY/(S_H/2.0f) * (cam.fovy/2.0f) * DEG2RAD;
    }

    if (mouse_mode_ui)
    {
        ShowCursor();
        mousePosX = GetMouseX();
        mousePosY = GetMouseY();
    }
}



void update_cam_pos()
{
    if (IsKeyDown(KEY_W))
    {
        cam.position.x += cam_speed * cos(cam_theta);
        cam.position.y += cam_speed * sin(cam_theta);
    }
    if (IsKeyDown(KEY_S))
    {
        cam.position.x -= cam_speed * cos(cam_theta);
        cam.position.y -= cam_speed * sin(cam_theta);
    }
    if (IsKeyDown(KEY_A))
    {
        cam.position.x += cam_speed * cos(cam_theta + PI/2);
        cam.position.y += cam_speed * sin(cam_theta + PI/2);
    }
    if (IsKeyDown(KEY_D))
    {
        cam.position.x += cam_speed * cos(cam_theta - PI/2);
        cam.position.y += cam_speed * sin(cam_theta - PI/2);
    }
    if (IsKeyDown(KEY_R))
    {
        cam.position.z += cam_speed;
    }

    if (IsKeyDown(KEY_F))
    {
        cam.position.z -= cam_speed;
    }
}

void update_cam_dir()
{ 
    prev_cam_theta = cam_theta;
    prev_cam_phi = cam_phi;
    cam_theta -= mouse_theta;
    cam_phi -= mouse_phi;

    if (cam_phi >  PI/2.2f) cam_phi =  PI/2.2f;
    if (cam_phi < -PI/2.2f) cam_phi = -PI/2.2f;

    cam.target.y = cam.position.y + (cos(cam_phi) * sin(cam_theta));
    cam.target.z = cam.position.z + sin(cam_phi);
    cam.target.x = cam.position.x + (cos(cam_phi) * cos(cam_theta));
}




void update()
{
    check_keys_pressed();
    update_mouse();
    if (mouse_mode_3D)
    {
        update_cam_pos();
        update_cam_dir();
    }
    if (main_ui.visible)
    {
        update_main_ui_menu_bar();
        update_file_ddm();
    }
}