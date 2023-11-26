#include "draw.h"
#include "set_up.h"
#include "model_A.h"


void draw_ui()
{
    if(main_ui.visible)
    {
        DrawRectangle(main_ui.r.x, main_ui.r.y, main_ui.r.width, main_ui.r.height, main_ui.color);
        DrawRectangle(main_ui_menu_bar.r.x, main_ui_menu_bar.r.y, main_ui_menu_bar.r.width, main_ui_menu_bar.r.height, main_ui_menu_bar.color);
        DrawText(main_ui_menu_bar.ddm[0].name, 
                main_ui_menu_bar.ddm[0].r.x,
                main_ui_menu_bar.ddm[0].r.y,
                font_size,
                main_ui_menu_bar.ddm[0].font_color);

    }
    if (file_ddm.visible)
    {
        DrawRectangle(file_ddm.r.x, 30, file_ddm.r.width, file_ddm.r.height, file_ddm.color);
        DrawText(file_ddm.ddm[0].name, file_ddm.ddm[0].r.x, file_ddm.ddm[0].r.y, font_size, file_ddm.ddm[0].font_color);
    }
}

void draw_floor_model()
{
    DrawModel(models[0], {0.0f, 0.0f, 0.0f}, 1.0f, WHITE);
}

void draw_model_A()
{
    DrawModel(models[1], {0.0f, 0.0f, 10.0f}, 1.0f, WHITE);
}

void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    //---------------------
    BeginMode3D(cam);

    draw_floor_model();
    draw_model_A();
    
    EndMode3D();
    //---------------------

    draw_ui();
    DrawFPS(S_W - 80, 10);
    DrawText(TextFormat("mousePosX: %02i", mousePosX), 100, 100, 30, GREEN);
    DrawText(TextFormat("mousePosY: %02i", mousePosY), 100, 150, 30, GREEN);
    DrawText(TextFormat("test1: %02i", int(test1)), 100, 180, 30, GREEN);
    DrawText(TextFormat("main_ui.visible: %02i", int(main_ui.visible)), 100, 210, 30, GREEN);
    DrawText(TextFormat("x: %02i", main_ui_menu_bar.ddm.at(0).r.x), 100, 240, 30, GREEN); 
    DrawText(TextFormat("y: %02i", main_ui_menu_bar.ddm.at(0).r.y), 100, 270, 30, GREEN); 
    DrawText(TextFormat("width: %02i", main_ui_menu_bar.ddm.at(0).r.width), 100, 300, 30, GREEN); 
    DrawText(TextFormat("height: %02i", main_ui_menu_bar.ddm.at(0).r.height), 100, 330, 30, GREEN); 
    DrawText(TextFormat("test2: %02i", int(test2)), 100, 360, 30, GREEN);
    DrawText(TextFormat("test3: %02i", int(test3)), 100, 390, 30, GREEN);
    
    //if (info_tab_visible)
    //{
        //DrawText(TextFormat("player.colliding: %02i", int(player.colliding)), 50, 220, 30, {255, 255, 255, 100});
        //DrawText(TextFormat("player.grounded: %02i", int(player.grounded)), 50, 250, 30, {255, 255, 255, 100});
        //DrawText(TextFormat("player.time_not_grounded: %02i", int(player.time_not_grounded)), 50, 280, 30, {255, 255, 255, 100});
        //DrawText(TextFormat("player.pos: %01f, %01f, %01f", player.pos.x, player.pos.y, player.pos.z), 50, 310, 30, {255, 255, 255, 100});
        //DrawText(TextFormat("player.prev_pos: %01f, %01f, %01f", player.prev_pos.x, player.prev_pos.y, player.prev_pos.z), 50, 340, 30, {255, 255, 255, 100});
        //DrawText(TextFormat("player.theta: %01f", player.theta*180/PI), 50, 460, 30, {255, 255, 255, 100});
        //DrawText(TextFormat("player.speed: %01f", player.speed), 50, 490, 30, {255, 255, 255, 100});
    //}
    //----------------------------------------------------------
    EndDrawing();
}



