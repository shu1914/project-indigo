/**
 * @file HomeScreen.cpp
 * @brief Home screen class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-19
 * 
 * @copyright Copyright (c) 2026
 */

#include "HomeScreen.h"

namespace indigo
{

HomeScreen::~HomeScreen()
{
    if (_screenObj != nullptr)
    {
        lv_obj_del(_screenObj);
        _screenObj = nullptr;
    }
}

void
HomeScreen::onCreate()
{
    _screenObj = lv_obj_create(nullptr);

    lv_obj_set_style_bg_color(_screenObj, lv_color_hex(0x8888FF), 0);

    lv_screen_load(_screenObj);
}

void
HomeScreen::onHide()
{
}

}
