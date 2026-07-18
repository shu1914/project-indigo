/**
 * @file WidgetBuilder.h
 * @brief Widget Builder
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-18
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef WIDGET_BUILDER_H
#define WIDGET_BUILDER_H

#include <lvgl.h>

#include "label/Label.h"

namespace indigo
{

class WidgetBuilder
{

public:

    WidgetBuilder() {}

    inline Label label(lv_obj_t* parent)
    {
        return Label(
            parent);
    }

    // TODO: Add more widgets here

};

}

#endif // WIDGET_BUILDER_H
