#include "ui.h"
#include "utils.h"


bool test1;
bool test2;
bool test3;
canvas main_ui {};
menu_bar main_ui_menu_bar {};
menu_bar file_ddm {};


void set_up_main_ui()
{
    main_ui.r  = {0, 0, S_W/2, S_H};
    main_ui.color = GRAY;
    main_ui.visible = true;
}

void set_up_main_ui_menu_bar()
{
    main_ui_menu_bar.r = {0, 0, S_W, 30};
    main_ui_menu_bar.color = DARKGRAY;
    main_ui_menu_bar.visible = true;
    main_ui_menu_bar.ddm.push_back({ 
                                    "Filee",
                                    {0, 0, 50, 30},
                                    RED, //bg
                                    BLACK });
}

void set_up_file_ddm()
{
    file_ddm.r = {0, 0, 100, 200};
    file_ddm.color = DARKGRAY;
    file_ddm.visible = false;
    file_ddm.ddm.push_back({
                            "New",
                            {0, 30, 100, 30},
                            RED,
                            BLACK });
}


void update_file_ddm()
{
    if (!cursor_on(file_ddm.r))
    {
        file_ddm.visible = false;
    }
    if (cursor_on(file_ddm.ddm[0].r))
    {
        file_ddm.ddm[0].font_color = WHITE;
        if (IsMouseButtonPressed(0))
        {
            test3 = true;
        }
    }
}


void update_main_ui_menu_bar()
{
    if (cursor_on(main_ui_menu_bar.ddm.at(0).r))
    {
        main_ui_menu_bar.ddm.at(0).font_color = WHITE;
        if (IsMouseButtonPressed(0))
        {
            file_ddm.visible = true;
            test2 = true;
        }
        test1 = true;
    }
    else
    {
        main_ui_menu_bar.ddm.at(0).font_color = BLACK;
        test1 = false;
    }


}
    