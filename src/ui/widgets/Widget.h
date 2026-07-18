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

namespace indigo
{

template<typename Derived>
class Widget
{
public:
    struct StyleEntry
    {
        const lv_style_t* style;
        lv_style_selector_t selector;
    };

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

    Derived& style(
        const lv_style_t* style,
        lv_style_selector_t selector = LV_PART_MAIN | LV_STATE_DEFAULT)
    {
        _styles.push_back({style, selector});
        return static_cast<Derived&>(*this);
    }

    virtual lv_obj_t* build() = 0;

protected:

    void applyCommonProps(
        lv_obj_t* obj);

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

    bool _isHidden = false;
    bool _isDisabled = false;
    bool _isClickable = false;

    std::vector<StyleEntry> _styles;
};

template<typename Derived> void
Widget<Derived>::applyCommonProps(lv_obj_t* obj)
{
    if (_hasPos) lv_obj_set_pos(obj, _x, _y);
    if (_hasAlign) lv_obj_set_align(obj, _align);
    if (_hasSize) lv_obj_set_size(obj, _width, _height);

    lv_obj_set_state(obj, LV_STATE_DISABLED, _isDisabled);
    lv_obj_set_flag(obj, LV_OBJ_FLAG_HIDDEN, _isHidden);
    lv_obj_set_flag(obj, LV_OBJ_FLAG_CLICKABLE, _isClickable);

    for (const auto& s : _styles)
    {
        lv_obj_add_style(obj, s.style, s.selector);
    }
}

}

#endif // WIDGET_H
