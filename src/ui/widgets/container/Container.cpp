/**
 * @file Container.cpp
 * @brief Container widget class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-20
 * 
 * @copyright Copyright (c) 2026
 */

#include "Container.h"

namespace indigo
{

const std::vector<const WidgetStyle*>&
Container::defaultStyles() const
{
    static const std::vector<const WidgetStyle*> styles = {
        makeStaticStyle([](WidgetStyle& s) {
            s.radius(0)
            .borderWidth(0);
        })
    };

    return styles;
}

lv_obj_t*
Container::build()
{
    lv_obj_t* object = lv_obj_create(_parent);

    applyCommonProps(object);

    lv_obj_set_layout(object, _layout);

    return object;
}

}
