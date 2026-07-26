/**
 * @file Line.cpp
 * @brief Line widget class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-20
 * 
 * @copyright Copyright (c) 2026
 */

#include "Line.h"

namespace indigo
{

lv_obj_t*
Line::build()
{
    lv_obj_t* object = lv_line_create(_parent);

    applyCommonProps(object);

    if(_count > 0 && _points != nullptr)
    {
        lv_line_set_points(object, _points, _count);
    }

    return object;
}

}
