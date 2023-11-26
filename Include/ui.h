#pragma once
#include "raylib.h"
#include "set_up.h"
#include "utils.h"
#include <vector>
#include <string>
using namespace std;


struct rect {
                int x;
                int y;
                int width;
                int height;
};

bool cursor_on(rect r);

struct canvas { 
                rect r;
                Color color;
                bool visible;

};

struct button {
                const char *name;
                rect r;
                Color bg_color;
                Color font_color;
                bool visible;
};

struct menu_bar { 
                  rect r;
                  Color color;
                  bool visible;
                  vector<button> ddm;
};




extern bool test1;
extern bool test2;
extern bool test3;
extern canvas main_ui;
extern menu_bar main_ui_menu_bar;
extern menu_bar file_ddm;
extern menu_bar options_ddm;


void set_up_main_ui();
void set_up_main_ui_menu_bar();
void update_main_ui_menu_bar();
void set_up_file_ddm();
void update_file_ddm();

