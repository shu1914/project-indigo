/**
 * @file Line.h
 * @brief Line widget class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-20
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef LINE_H
#define LINE_H

#include <lvgl.h>

#include "../Widget.h"

namespace indigo
{

class Line : public Widget<Line>
{
public:

    using Widget::Widget;

    lv_obj_t* build() override;

    Line& points(
        const lv_point_precise_t* points,
        uint32_t count)
    {
        _points = points;
        _count = count;
        return *this;
    }

private:

    const lv_point_precise_t* _points = nullptr;
    uint32_t _count = 0;
};

}

#endif // LINE_H 