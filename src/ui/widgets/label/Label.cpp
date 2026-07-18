/**
 * @file Label.cpp
 * @brief Label widget class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-18
 * 
 * @copyright Copyright (c) 2026
 */

#include "Label.h"

namespace indigo
{

lv_obj_t*
Label::build()
{
    lv_obj_t* object = lv_label_create(_parent);

    applyCommonProps(object);

    lv_label_set_text(object, _text.c_str());

    return object;
}

}
