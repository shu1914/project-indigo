/**
 * @file HomeScreen.h
 * @brief Home screen class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-19
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef HOME_SCREEN_H
#define HOME_SCREEN_H

#include <lvgl.h>

#include "../IScreen.h"
#include "../../widgets/WidgetStyle.h"

namespace indigo
{

class HomeScreen : public IScreen
{
public:
    HomeScreen() = default;

    // Delete the LVGL tree before the style members are destroyed.
    ~HomeScreen() override
    {
        if (_screenObj)
        {
            lv_obj_delete(_screenObj);
            _screenObj = nullptr;
        }
    }

    HomeScreen(const HomeScreen&) = delete;

    HomeScreen& operator=(const HomeScreen&) = delete;

    void onCreate() override;
    void onHide() override;

private:
    WidgetStyle _topContStyle;
    WidgetStyle _bottomContStyle;
    WidgetStyle _centerDividerStyle;
    WidgetStyle _centerContStyle;
    WidgetStyle _centerButtonStyle;

};

}

#endif // HOME_SCREEN_H
