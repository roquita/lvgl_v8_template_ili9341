#include "menu.h"
#include "copy.h"
#include "lvgl.h"
#include "lvgl_helpers.h"

void gui_app()
{
    // first view
    create_menu_background();
    create_menu_title();
    create_menu_body();
    create_menu_footer();

    // second view
    create_copy_screen();
}