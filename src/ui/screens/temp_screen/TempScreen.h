/**
 * @file HomeScreen.h
 * @brief Home screen class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-19
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef TEMP_SCREEN_H
#define TEMP_SCREEN_H

#include <lvgl.h>

#include "../IScreen.h"
#include "../../widgets/label/Label.h"

#include "pokedex/IPokedex.h"

namespace indigo
{

class TempScreen : public IScreen
{
public:
    explicit TempScreen(
        IPokedex& pokedex);

    ~TempScreen() override;

    TempScreen(const TempScreen&) = delete;

    TempScreen& operator=(const TempScreen&) = delete;

    void onCreate() override;

private:
    lv_obj_t* _screenObj = nullptr;
    IPokedex& _pokedex;

    // TODO: To be removed for actual implementation
    WidgetStyle _textStyle;

};

}

#endif // TEMP_SCREEN_H
