#include "copy.h"
#include "menu.h"
#include "stdint.h"
#include "stdio.h"
#define TAG "COPY_SCREEN"

lv_obj_t *new_screen = NULL;

static void switch_btn_cb(lv_event_t *event)
{
    printf("Clicked\n");
    lv_scr_load(menu_screen);
    //lv_scr_load_anim(menu_screen, LV_SCR_LOAD_ANIM_FADE_ON, 400, 50, false);
}
void create_copy_screen(void)
{
    new_screen = lv_obj_create(NULL);
    lv_obj_t *swish = lv_switch_create(new_screen);

    static lv_style_t style_bg;
    lv_style_init(&style_bg);
    lv_style_set_bg_color(&style_bg, lv_color_make(40, 37, 61));

    /*Create an object with the new style*/
    lv_obj_add_style(new_screen, &style_bg, 0);
    lv_obj_add_event_cb(swish, switch_btn_cb, LV_EVENT_CLICKED, NULL);

    //lv_scr_load_anim(menu_screen, LV_SCR_LOAD_ANIM_FADE_ON, 400, 50, false);
}