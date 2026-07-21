/**
 * @file WidgetBehavior.cpp
 * @brief Widget behavior class helper implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-22
 * 
 * @copyright Copyright (c) 2026
 */

#include "WidgetBehavior.h"

namespace
{

void applyFlag(
    lv_obj_t* obj,
    lv_obj_flag_t flag,
    const std::optional<bool>& value)
{
    if (value)
        lv_obj_set_flag(obj, flag, *value);
}

void applyState(
    lv_obj_t* obj,
    lv_state_t state,
    const std::optional<bool>& value)
{
    if (value)
        lv_obj_set_state(obj, state, *value);
}

} // namespace

namespace indigo
{

void
WidgetBehavior::apply(
    lv_obj_t* obj) const
{
    applyFlag(obj, LV_OBJ_FLAG_HIDDEN, flags.hidden);
    applyFlag(obj, LV_OBJ_FLAG_CLICKABLE, flags.clickable);
    applyState(obj, LV_STATE_DISABLED, states.disabled);
}

}
