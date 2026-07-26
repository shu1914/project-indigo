/**
 * @file Container.h
 * @brief Container widget class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-20
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include <lvgl.h>
#include <optional>

#include "../Widget.h"
#include "../WidgetStyle.h"

namespace indigo
{

class Container : public Widget<Container>
{
public:

    using Widget::Widget;

    lv_obj_t* build() override;

    Container& layout(
        lv_layout_t layout)
    {
        _layout = layout;
        return *this;
    }

    const WidgetStyle* defaultStyle() const override;

private:
    lv_layout_t _layout = LV_LAYOUT_NONE;
};

}

#endif // CONTAINER_H 