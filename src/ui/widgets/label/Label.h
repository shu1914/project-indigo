/**
 * @file Label.h
 * @brief Label widget class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-18
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef LABEL_H
#define LABEL_H

#include <lvgl.h>
#include <string>
#include <fmt/format.h>

#include "../Widget.h"

namespace indigo
{

class Label : public Widget<Label>
{
public:

    using Widget::Widget;

    lv_obj_t* build() override;

    template<typename... Args>
    Label& text(
        fmt::format_string<Args...> fmtStr,
        Args&&... args)
    {
        _text = fmt::format(fmtStr, std::forward<Args>(args)...);
        return *this;
    }

private:

    std::string _text = "";

};

}

#endif // LABEL_H 