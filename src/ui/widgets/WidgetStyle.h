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
        // _style was initialized in the constructor and always remains
        // valid; no move/ copy allowed; so reset is safe.
        lv_style_reset(&_style);
    }

    void reset()
    {
        lv_style_reset(&_style);
        lv_style_init(&_style);
        _selector = LV_STATE_DEFAULT | LV_PART_MAIN;
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

    WidgetStyle& radius(
        int32_t radius)
    {
        lv_style_set_radius(&_style, radius);
        return *this;
    }

    WidgetStyle& lineWidth(
        int32_t lineWidth)
    {
        lv_style_set_line_width(&_style, lineWidth);
        return *this;
    }

    WidgetStyle& lineColor(
        lv_color_t lineColor)
    {
        lv_style_set_line_color(&_style, lineColor);
        return *this;
    }

    WidgetStyle& borderWidth(
        int32_t borderWidth)
    {
        lv_style_set_border_width(&_style, borderWidth);
        return *this;
    }

    WidgetStyle& borderColor(
        lv_color_t borderColor)
    {
        lv_style_set_border_color(&_style, borderColor);
        return *this;
    }

    WidgetStyle& borderOpa(
        lv_opa_t opa)
    {
        lv_style_set_border_opa(&_style, opa);
        return *this;
    }

    WidgetStyle& transformWidth(
        int32_t width)
    {
        lv_style_set_transform_width(&_style, width);
        return *this;
    }

    WidgetStyle& transformHeight(
        int32_t height)
    {
        lv_style_set_transform_height(&_style, height);
        return *this;
    }

    WidgetStyle& selector(
        lv_style_selector_t selector)
    {
        _selector = selector;
        return *this;
    }


    // TODO: Add more styles function here based on what is required

    const lv_style_t* native() const
    {
        return &_style;
    }

    const lv_style_selector_t getSelector() const
    {
        return _selector;
    }

private:
    lv_style_t _style;
    lv_style_selector_t _selector = LV_STATE_DEFAULT | LV_PART_MAIN;
};

}

#endif // WIDGET_STYLE_H
