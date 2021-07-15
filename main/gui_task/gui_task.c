#include "lvgl.h"
#include "lvgl_helpers.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "gui_app.c"

void lvgl_tick(void)
{
    lv_tick_inc(portTICK_PERIOD_MS);
}
void gui_task(void *arg)
{
    // print some dummy text
    printf("lvgl version info: %s\n", lv_version_info());
    printf("lvgl version patch: %i\n", lv_version_patch());

    // init lvgl core
    lv_init();

    // init drivers for inputs and outputs
    lvgl_driver_init();

    // create draw buffers
    static lv_disp_draw_buf_t disp_buf;
    static lv_color_t buf_1[LV_HOR_RES_MAX * 40];
    static lv_color_t buf_2[LV_HOR_RES_MAX * 40];
    lv_disp_draw_buf_init(&disp_buf, buf_1, buf_2, LV_HOR_RES_MAX * 40);

    // link tft and lvgl
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.flush_cb = disp_driver_flush;
    lv_disp_drv_register(&disp_drv);

    // link touch and lvgl
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);          
    indev_drv.type = LV_INDEV_TYPE_POINTER; 
    indev_drv.read_cb = touch_driver_read;  
    lv_indev_drv_register(&indev_drv);

    // source tick for lvgl
    esp_register_freertos_tick_hook(lvgl_tick);

    // load user app
    gui_app();

    while (1)
    {
        // run lvgl task
        lv_timer_handler();
        vTaskDelay(1);
    }
}
