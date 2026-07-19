/**
 * @file WidgetStyle.h
 * @brief Widget Style
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-19
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef WIDGET_STYLE_H
#define WIDGET_STYLE_H

#include <lvgl.h>

namespace indigo
{

class WidgetStyle
{
public:

    WidgetStyle()
    {
        lv_style_init(&_style);
    }

    ~WidgetStyle()
    {
        lv_style_reset(&_style);
    }

    WidgetStyle(const WidgetStyle&) = delete;
    WidgetStyle& operator=(const WidgetStyle&) = delete;

    WidgetStyle(WidgetStyle&&) = delete;
    WidgetStyle& operator=(WidgetStyle&&) = delete;

    WidgetStyle& bgColor(
        lv_color_t color)
    {
        lv_style_set_bg_color(&_style, color);
        return *this;
    }

    WidgetStyle& bgOpa(
        lv_opa_t opa)
    {
        lv_style_set_bg_opa(&_style, opa);
        return *this;
    }

    WidgetStyle& textColor(
        lv_color_t color)
    {
        lv_style_set_text_color(&_style, color);
        return *this;
    }

    // TODO: Add more styles function here based on what is required

    const lv_style_t* native() const
    {
        return &_style;
    }

private:
    lv_style_t _style;
};

}

#endif // WIDGET_STYLE_H
