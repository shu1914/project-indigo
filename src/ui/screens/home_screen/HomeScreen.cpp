/**
 * @file HomeScreen.cpp
 * @brief Home screen class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-19
 * 
 * @copyright Copyright (c) 2026
 */

#include "HomeScreen.h"
#include "common/logger/LogMacro.h"
#include "../../widgets/WidgetBuilder.h"

namespace indigo
{

void
HomeScreen::onCreate()
{
    _screenObj = lv_obj_create(nullptr);

    lv_obj_set_style_bg_color(_screenObj, lv_color_white(), 0);

    WidgetBuilder builder;

    _topContStyle.bgColor(lv_color_hex(0xEE1515))
        .bgOpa(LV_OPA_COVER);

    _bottomContStyle.bgColor(lv_color_hex(0xF0F0F0))
        .bgOpa(LV_OPA_COVER);
    
    builder.container(_screenObj)
        .style(_topContStyle)
        .align(LV_ALIGN_TOP_MID)
        .size(LV_PCT(100), LV_PCT(50))
        .build();

    builder.container(_screenObj)
        .style(_bottomContStyle)
        .align(LV_ALIGN_BOTTOM_MID)
        .size(LV_PCT(100), LV_PCT(50))
        .build();

    static lv_point_precise_t points[] = {
            {0, LV_PCT(50)},
            {LV_PCT(100), LV_PCT(50)}
        };

    _centerDividerStyle.lineColor(lv_color_black())
        .lineWidth(30);

    builder.line(_screenObj)
        .size(
            lv_obj_get_width(_screenObj),
            lv_obj_get_height(_screenObj))
        .style(_centerDividerStyle)
        .points(points, 2)
        .build();

    _centerContStyle.bgColor(lv_color_hex(0xF0F0F0))
        .bgOpa(LV_OPA_COVER)
        .borderWidth(30)
        .borderColor(lv_color_black())
        .radius(LV_RADIUS_CIRCLE);

    lv_obj_t* centerCont = builder.container(_screenObj)
        .style(_centerContStyle)
        .align(LV_ALIGN_CENTER)
        .size(220, 220)
        .build();

    _centerButtonStyle.bgColor(lv_color_hex(0xF0F0F0))
        .borderWidth(5)
        .borderColor(lv_color_black())
        .radius(LV_RADIUS_CIRCLE);

    lv_obj_t* btn = builder.button(centerCont)
        .style(_centerButtonStyle)
        .align(LV_ALIGN_CENTER)
        .size(120, 120)
        .build();

    lv_obj_add_event_cb(
        btn,
        [](lv_event_t* e){
            USER("Clicked!");
        },
        LV_EVENT_CLICKED,
        nullptr);
}

void
HomeScreen::onHide()
{
}

}
