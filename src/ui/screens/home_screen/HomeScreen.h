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

namespace indigo
{

class HomeScreen : public IScreen
{
public:
    HomeScreen() = default;
    
    HomeScreen(const HomeScreen&) = delete;

    HomeScreen& operator=(const HomeScreen&) = delete;

    void onCreate() override;
    void onHide() override;
};

}

#endif // HOME_SCREEN_H
