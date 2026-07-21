/**
 * @file WidgetBehavior.h
 * @brief Widget behavior class helper
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-22
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef WIDGET_BEHAVIOR_H
#define WIDGET_BEHAVIOR_H

#include <lvgl.h>
#include <optional>

namespace indigo
{

class WidgetBehavior
{
public:
    struct
    {
        std::optional<bool> hidden;
        std::optional<bool> clickable;
    } flags;

    struct
    {
        std::optional<bool> disabled;
    } states;

    void apply(lv_obj_t* obj) const;
};

}

#endif // WIDGET_BEHAVIOR_H
