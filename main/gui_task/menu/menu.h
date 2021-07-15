#pragma once

#include "lvgl.h"
#include "lvgl_helpers.h"

extern lv_obj_t *menu_screen;

void create_menu_background();
void create_menu_title();
void create_menu_body();
void create_menu_footer();