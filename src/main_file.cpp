#include "raylib.h"
#include "set_up.h"
#include "model_A.h"
#include "update.h"
#include "draw.h"




int main()
{
    set_up();
    //load_fonts();
    load_floor_model();
    load_model_A();

    
    while (!WindowShouldClose())
    {
        update();
        update_r_model_A();
        update_model_A_texture();
        draw();

    }

    CloseWindow();
    return 0;

}