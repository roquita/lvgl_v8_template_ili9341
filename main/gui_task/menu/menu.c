#include "menu.h"
#include "copy.h"
#include "stdint.h"
#include "stdio.h"
#define TAG "MENU_SCREEN"
#define HEIGH 240
#define WIDTH 320

LV_FONT_DECLARE(icons_20)

lv_obj_t *menu_screen = NULL;

static void copy_button_cb(lv_event_t *event)
{
    printf("Clicked\n");
    lv_scr_load(new_screen);
    //lv_scr_load_anim(new_screen, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 400, 50, false);
}

void create_menu_background()
{
    menu_screen = lv_scr_act();

    static lv_style_t style_bg;
    lv_style_init(&style_bg);
    lv_style_set_radius(&style_bg, 0);
    lv_style_set_width(&style_bg, WIDTH);
    lv_style_set_height(&style_bg, HEIGH);
    lv_style_set_border_width(&style_bg, 0);

    /*Make a gradient*/
    lv_style_set_bg_color(&style_bg, lv_color_make(40, 37, 61));
    lv_style_set_bg_grad_color(&style_bg, lv_color_make(217, 226, 255));
    lv_style_set_bg_grad_dir(&style_bg, LV_GRAD_DIR_VER);

    /*Shift the gradient to the bottom*/
    lv_style_set_bg_main_stop(&style_bg, HEIGH / 3);
    lv_style_set_bg_grad_stop(&style_bg, HEIGH / 3);

    /*Create an object with the new style*/
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj, &style_bg, 0);
    lv_obj_center(obj);
}
void create_menu_title()
{
    // tittle
    static lv_style_t style_fg;
    lv_style_init(&style_fg);
    lv_style_set_radius(&style_fg, 0);
    lv_style_set_width(&style_fg, WIDTH);
    lv_style_set_height(&style_fg, HEIGH / 5);
    lv_style_set_bg_color(&style_fg, lv_color_make(40, 37, 61));
    lv_style_set_border_width(&style_fg, 0);

    lv_obj_t *fg = lv_obj_create(lv_scr_act());
    lv_obj_add_style(fg, &style_fg, 0);
    lv_obj_set_pos(fg, 0, 0);

    // tittle-icon1
    static lv_style_t style_tittle_icons;
    lv_style_init(&style_tittle_icons);
    lv_style_set_text_font(&style_tittle_icons, &icons_20);

    lv_obj_t *icon1 = lv_label_create(fg);
    lv_obj_set_width(icon1, WIDTH / 8);
    lv_obj_add_style(icon1, &style_tittle_icons, 0);
    lv_obj_set_pos(icon1, 0 * WIDTH / 8, 0);
    lv_label_set_recolor(icon1, true);
    lv_label_set_text(icon1, "#f5f7f6 \uf1eb#");

    // tittle-icon2
    lv_obj_t *icon2 = lv_label_create(fg);
    lv_obj_set_width(icon2, WIDTH / 8);
    lv_obj_add_style(icon2, &style_tittle_icons, 0);
    lv_obj_set_pos(icon2, 1 * WIDTH / 8, 0);
    lv_label_set_recolor(icon2, true);
    lv_label_set_text(icon2, "#f5f7f6 \uf095#");

    // tittle-icon3
    lv_obj_t *icon3 = lv_label_create(fg);
    lv_obj_set_width(icon3, WIDTH / 8);
    lv_obj_add_style(icon3, &style_tittle_icons, 0);
    lv_obj_set_pos(icon3, 2 * WIDTH / 8, 0);
    lv_label_set_recolor(icon3, true);
    lv_label_set_text(icon3, "#f5f7f6 \uf06c#");

    // tittle-icon4
    lv_obj_t *icon4 = lv_label_create(fg);
    lv_obj_set_width(icon4, WIDTH / 8);
    lv_obj_add_style(icon4, &style_tittle_icons, 0);
    lv_obj_set_pos(icon4, 3 * WIDTH / 8, 0);
    lv_label_set_recolor(icon4, true);
    lv_label_set_text(icon4, "#f5f7f6 \uf109#");

    // tittle-text
    static lv_style_t style_tittle_text;
    lv_style_init(&style_tittle_text);
    lv_style_set_text_font(&style_tittle_text, &lv_font_montserrat_12);

    lv_obj_t *tittle_text = lv_label_create(fg);
    lv_obj_add_style(tittle_text, &style_tittle_text, 0);
    lv_obj_set_align(tittle_text, LV_ALIGN_RIGHT_MID);

    lv_label_set_long_mode(tittle_text, LV_LABEL_LONG_CLIP);
    lv_label_set_recolor(tittle_text, true);
    lv_label_set_text(tittle_text, "#f5f7f6 22 April 2020 15:36#");
}
void create_menu_body()
{
    // body
    static lv_style_t style_bd;
    lv_style_init(&style_bd);
    lv_style_set_radius(&style_bd, 5);
    lv_style_set_width(&style_bd, WIDTH * 0.95);
    lv_style_set_height(&style_bd, HEIGH * 0.6);
    lv_style_set_bg_color(&style_bd, lv_color_make(228, 235, 254));
    lv_style_set_border_width(&style_bd, 0);

    lv_obj_t *bd = lv_obj_create(lv_scr_act());
    lv_obj_add_style(bd, &style_bd, 0);
    lv_obj_set_align(bd, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(bd, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(bd, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    // body-copy
    static lv_style_t style_copy;
    lv_style_init(&style_copy);
    lv_style_set_radius(&style_copy, 8);
    lv_style_set_width(&style_copy, WIDTH * 0.19);
    lv_style_set_height(&style_copy, HEIGH * 0.40);
    lv_style_set_bg_color(&style_copy, lv_color_make(153, 94, 242));
    lv_style_set_border_width(&style_copy, 0);

    lv_obj_t *copy = lv_btn_create(bd);
    lv_obj_add_style(copy, &style_copy, 0);

    static lv_style_t style_btn_text;
    lv_style_init(&style_btn_text);
    lv_style_set_text_font(&style_btn_text, &lv_font_montserrat_10);

    lv_obj_t *copy_lb = lv_label_create(copy);
    lv_obj_add_style(copy_lb, &style_btn_text, 0);
    lv_obj_set_align(copy_lb, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(copy_lb, "COPY");

    lv_obj_t *copy_icon = lv_label_create(copy);
    lv_label_set_text(copy_icon, LV_SYMBOL_PAUSE);
    lv_obj_set_align(copy_icon, LV_ALIGN_TOP_RIGHT);

    lv_obj_add_event_cb(copy, copy_button_cb, LV_EVENT_CLICKED, NULL);

    // body-scan
    static lv_style_t style_scan;
    lv_style_init(&style_scan);
    lv_style_set_radius(&style_scan, 8);
    lv_style_set_width(&style_scan, WIDTH * 0.19);
    lv_style_set_height(&style_scan, HEIGH * 0.40);
    lv_style_set_bg_color(&style_scan, lv_color_make(40, 109, 248));
    lv_style_set_border_width(&style_scan, 0);

    lv_obj_t *scan = lv_btn_create(bd);
    lv_obj_add_style(scan, &style_scan, 0);

    lv_obj_t *scan_lb = lv_label_create(scan);
    lv_obj_add_style(scan_lb, &style_btn_text, 0);
    lv_obj_set_align(scan_lb, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(scan_lb, "SCAN");

    lv_obj_t *scan_icon = lv_label_create(scan);
    lv_label_set_text(scan_icon, LV_SYMBOL_VOLUME_MAX);
    lv_obj_set_align(scan_icon, LV_ALIGN_TOP_RIGHT);

    // body-print
    static lv_style_t style_print;
    lv_style_init(&style_print);
    lv_style_set_radius(&style_print, 8);
    lv_style_set_width(&style_print, WIDTH * 0.19);
    lv_style_set_height(&style_print, HEIGH * 0.40);
    lv_style_set_bg_color(&style_print, lv_color_make(57, 138, 1));
    lv_style_set_border_width(&style_print, 0);

    lv_obj_t *print = lv_btn_create(bd);
    lv_obj_add_style(print, &style_print, 0);

    lv_obj_t *print_lb = lv_label_create(print);
    lv_obj_add_style(print_lb, &style_btn_text, 0);
    lv_obj_set_align(print_lb, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(print_lb, "PRINT");

    lv_obj_t *print_icon = lv_label_create(print);
    lv_label_set_text(print_icon, LV_SYMBOL_POWER);
    lv_obj_set_align(print_icon, LV_ALIGN_TOP_RIGHT);

    // body-setup
    static lv_style_t style_setup;
    lv_style_init(&style_setup);
    lv_style_set_radius(&style_setup, 8);
    lv_style_set_width(&style_setup, WIDTH * 0.19);
    lv_style_set_height(&style_setup, HEIGH * 0.40);
    lv_style_set_bg_color(&style_setup, lv_color_make(213, 50, 8));
    lv_style_set_border_width(&style_setup, 0);

    lv_obj_t *setup = lv_btn_create(bd);
    lv_obj_add_style(setup, &style_setup, 0);

    lv_obj_t *setup_lb = lv_label_create(setup);
    lv_obj_add_style(setup_lb, &style_btn_text, 0);
    lv_obj_set_align(setup_lb, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(setup_lb, "SETUP");

    lv_obj_t *setup_icon = lv_label_create(setup);
    lv_label_set_text(setup_icon, LV_SYMBOL_LOOP);
    lv_obj_set_align(setup_icon, LV_ALIGN_TOP_RIGHT);
}
void create_menu_footer()
{
    // footer
    static lv_style_t style_footer;
    lv_style_init(&style_footer);
    lv_style_set_width(&style_footer, WIDTH);
    lv_style_set_height(&style_footer, HEIGH * 0.2);
    lv_style_set_bg_color(&style_footer, lv_color_make(217, 226, 255));
    lv_style_set_border_width(&style_footer, 0);
    lv_style_set_pad_all(&style_footer, 0);

    lv_obj_t *footer = lv_obj_create(lv_scr_act());
    lv_obj_add_style(footer, &style_footer, 0);
    lv_obj_set_flex_flow(footer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(footer, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_align(footer, LV_ALIGN_BOTTOM_MID);

    // footer-text
    static lv_style_t style_footer_text;
    lv_style_init(&style_footer_text);
    lv_style_set_width(&style_footer_text, WIDTH * 0.56);
    lv_style_set_radius(&style_footer_text, 5);
    lv_style_set_height(&style_footer_text, HEIGH * 0.16);
    lv_style_set_bg_color(&style_footer_text, lv_color_make(228, 235, 254));
    lv_style_set_border_width(&style_footer_text, 0);
    lv_style_set_outline_width(&style_footer_text, 0);
    lv_style_set_pad_all(&style_footer_text, 0);

    lv_obj_t *footer_text = lv_obj_create(footer);
    lv_obj_add_style(footer_text, &style_footer_text, 0);

    static lv_style_t style_footer_lb;
    lv_style_init(&style_footer_lb);
    lv_style_set_text_font(&style_footer_lb, &lv_font_montserrat_10);

    lv_obj_t *footer_lb = lv_label_create(footer_text);
    lv_obj_add_style(footer_lb, &style_footer_lb, 0);
    lv_obj_set_align(footer_lb, LV_ALIGN_CENTER);
    lv_label_set_text(footer_lb, "What do you want to do today?");

    // footer chart
    static lv_style_t style_footer_chart;
    lv_style_init(&style_footer_chart);
    lv_style_set_width(&style_footer_chart, WIDTH * 0.35);
    lv_style_set_radius(&style_footer_chart, 5);
    lv_style_set_height(&style_footer_chart, HEIGH * 0.16);
    lv_style_set_bg_color(&style_footer_chart, lv_color_make(228, 235, 254));
    lv_style_set_border_width(&style_footer_chart, 0);
    lv_style_set_outline_width(&style_footer_chart, 0);
    lv_style_set_pad_all(&style_footer_chart, 0);

    lv_obj_t *footer_chart = lv_obj_create(footer);
    lv_obj_add_style(footer_chart, &style_footer_chart, 0);
    lv_obj_set_flex_flow(footer_chart, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(footer_chart, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    // footer-bar1
    static lv_style_t style_indic1;
    lv_style_init(&style_indic1);
    lv_style_set_bg_opa(&style_indic1, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic1, lv_color_make(101, 183, 215));

    lv_obj_t *bar1 = lv_bar_create(footer_chart);
    lv_obj_add_style(bar1, &style_indic1, LV_PART_INDICATOR);
    lv_obj_set_size(bar1, 15, HEIGH * 0.12);
    lv_bar_set_range(bar1, 0, 100);
    lv_bar_set_value(bar1, 50, LV_ANIM_OFF);

    // footer-bar2
    static lv_style_t style_indic2;
    lv_style_init(&style_indic2);
    lv_style_set_bg_opa(&style_indic2, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic2, lv_color_make(188, 133, 255));

    lv_obj_t *bar2 = lv_bar_create(footer_chart);
    lv_obj_add_style(bar2, &style_indic2, LV_PART_INDICATOR);
    lv_obj_set_size(bar2, 15, HEIGH * 0.12);
    lv_bar_set_range(bar2, 0, 100);
    lv_bar_set_value(bar2, 25, LV_ANIM_OFF);

    // footer-bar3
    static lv_style_t style_indic3;
    lv_style_init(&style_indic3);
    lv_style_set_bg_opa(&style_indic3, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic3, lv_color_make(203, 203, 39));

    lv_obj_t *bar3 = lv_bar_create(footer_chart);
    lv_obj_add_style(bar3, &style_indic3, LV_PART_INDICATOR);
    lv_obj_set_size(bar3, 15, HEIGH * 0.12);
    lv_bar_set_range(bar3, 0, 100);
    lv_bar_set_value(bar3, 70, LV_ANIM_OFF);

    // footer-bar4
    static lv_style_t style_indic4;
    lv_style_init(&style_indic4);
    lv_style_set_bg_opa(&style_indic4, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic4, lv_color_make(26, 29, 70));

    lv_obj_t *bar4 = lv_bar_create(footer_chart);
    lv_obj_add_style(bar4, &style_indic4, LV_PART_INDICATOR);
    lv_obj_set_size(bar4, 15, HEIGH * 0.12);
    lv_bar_set_range(bar4, 0, 100);
    lv_bar_set_value(bar4, 10, LV_ANIM_OFF);
}
