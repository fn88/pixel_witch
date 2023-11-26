#include "utils.h"
#include "ui.h"



bool cursor_on(rect r)
{
    bool on = false;
    if ((mousePosX >= r.x) && (mousePosX <= (r.x + r.width)) && (mousePosY >= r.y) && (mousePosY <= (r.y + r.height)))
    {
        on = true;
    }
    return on;
}

