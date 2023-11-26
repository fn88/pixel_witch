#include "input.h"



void check_keys_pressed()
{
    if (IsKeyPressed(KEY_TAB)) 
    {
        if (!main_ui.visible) 
        {
            main_ui.visible = true;
            mouse_mode_3D = false;
            mouse_mode_ui = true;
        }
        else if (main_ui.visible) 
        {
            main_ui.visible = false;
            mouse_mode_3D = true;
            mouse_mode_ui = false;
            SetMousePosition(S_W/2.0f, S_H/2.0f);
        }
    }
}
