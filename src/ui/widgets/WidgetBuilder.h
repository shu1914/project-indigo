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
#include "container/Container.h"
#include "line/Line.h"
#include "button/Button.h"

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

    inline Container container(lv_obj_t* parent)
    {
        return Container(
            parent);
    }

    inline Line line(lv_obj_t* parent)
    {
        return Line(
            parent);
    }

    inline Button button(lv_obj_t* parent)
    {
        return Button(
            parent);
    }
    

    // TODO: Add more widgets here

};

}

#endif // WIDGET_BUILDER_H
