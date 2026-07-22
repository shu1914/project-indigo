/**
 * @file Widget.h
 * @brief Widget base class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-18
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <optional>

#include "WidgetStyle.h"
#include "WidgetBehavior.h"

namespace indigo
{

template<typename Derived>
class Widget
{
public:
    explicit Widget(
        lv_obj_t* parent)
        : _parent(parent)
    {
    }

    virtual ~Widget() = default;

    Derived& pos(int32_t x, int32_t y)
    { _x = x; _y = y; _hasPos = true; return static_cast<Derived&>(*this); }

    Derived& align(lv_align_t align)
    { _align = align; _hasAlign = true; return static_cast<Derived&>(*this); }

    Derived& size(int32_t width, int32_t height)
    { _width = width; _height = height; _hasSize = true; return static_cast<Derived&>(*this); }

    Derived& enabled()
    { _isDisabled = false; return static_cast<Derived&>(*this); }

    Derived& disabled()
    { _isDisabled = true; return static_cast<Derived&>(*this); }

    Derived& hidden()
    { _isHidden = true; return static_cast<Derived&>(*this); }

    Derived& visible()
    { _isHidden = false; return static_cast<Derived&>(*this); }

    Derived& clickable()
    { _isClickable = true; return static_cast<Derived&>(*this); }

    Derived& nonClickable()
    { _isClickable = false; return static_cast<Derived&>(*this); }

    /**
     * @brief Applies a style to this widget.
     *
     * The Widget does not take ownership of @p widgetStyle.
     *
     * @param widgetStyle Style to apply.
     *
     * @pre widgetStyle must remain valid for as long as the
     *      built LVGL object uses the style.
     */
    Derived& style(
        const WidgetStyle& widgetStyle)
    {
        _widgetStyles.push_back(&widgetStyle);
        return static_cast<Derived&>(*this);
    }

    virtual const WidgetStyle* defaultStyle() const
    {
        return nullptr;
    }

    virtual const WidgetBehavior* defaultBehavior() const
    {
        return nullptr;
    }

    virtual lv_obj_t* build() = 0;

protected:

    void applyCommonProps(
        lv_obj_t* obj);

    template<typename InitFn>
    static const WidgetStyle* makeDefaultStyle(
        InitFn&& init)
    {
        static WidgetStyle style;

        static const bool initialized = [&] {
            init(style);
            return true;
        }();

        (void)initialized;
        return &style;
    }

    lv_obj_t* _parent;

private:

    int32_t _x = 0;
    int32_t _y = 0;
    bool _hasPos = false;

    lv_align_t _align = LV_ALIGN_TOP_LEFT;
    bool _hasAlign = false;
    
    int32_t _width = 0;
    int32_t _height = 0;
    bool _hasSize = false;

    std::optional<bool> _isHidden;
    std::optional<bool> _isDisabled;
    std::optional<bool> _isClickable;

    std::vector<const WidgetStyle*> _widgetStyles;

    WidgetBehavior behavior() const
    {
        WidgetBehavior result;

        if (auto* defaults = defaultBehavior())
            result = *defaults;

        if (_isHidden)
            result.flags.hidden = _isHidden;

        if (_isClickable)
            result.flags.clickable = _isClickable;

        if (_isDisabled)
            result.states.disabled = _isDisabled;

        return result;
    }
};

template<typename Derived> void
Widget<Derived>::applyCommonProps(lv_obj_t* obj)
{
    if (_hasPos) lv_obj_set_pos(obj, _x, _y);
    if (_hasAlign) lv_obj_set_align(obj, _align);
    if (_hasSize) lv_obj_set_size(obj, _width, _height);

    behavior().apply(obj);

    // Apply widget-level default styles
    if (const auto* style = defaultStyle())
    {
        lv_obj_add_style(
            obj,
            style->native(),
            style->getSelector());
    }

    // Apply overrided styles
    for(const auto* style : _widgetStyles)
    {
        lv_obj_add_style(
            obj,
            style->native(),
            style->getSelector());
    }
}

}

#endif // WIDGET_H
