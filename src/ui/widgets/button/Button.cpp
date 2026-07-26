/**
 * @file Button.cpp
 * @brief Button widget class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-20
 * 
 * @copyright Copyright (c) 2026
 */

#include "Button.h"

namespace indigo
{

const std::vector<const WidgetStyle*>&
Button::defaultStyles() const
{
    static const std::vector<const WidgetStyle*> styles = {
        makeStaticStyle([](WidgetStyle& s) {
            s.bgColor(lv_color_hex(0xFF0000))
             .transformWidth(0)
             .transformHeight(0)
             .selector(LV_STATE_PRESSED);
        })
    };

    return styles;
}


lv_obj_t*
Button::build()
{
    lv_obj_t* object = lv_button_create(_parent);

    applyCommonProps(object);

    return object;
}

}
