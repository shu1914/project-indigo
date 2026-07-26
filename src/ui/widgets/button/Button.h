/**
 * @file Button.h
 * @brief Button widget class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-20
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <lvgl.h>

#include "../Widget.h"

namespace indigo
{

class Button : public Widget<Button>
{
public:

    using Widget::Widget;

    lv_obj_t* build() override;

    const std::vector<const WidgetStyle*>& defaultStyles() const override;

    // const WidgetBehavior* defaultBehavior() const override;

};

}

#endif // BUTTON_H 