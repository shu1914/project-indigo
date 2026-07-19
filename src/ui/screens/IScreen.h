/**
 * @file IScreen.h
 * @brief Screen abstract class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-19
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef I_SCREEN_H
#define I_SCREEN_H

namespace indigo
{

class IScreen
{
public:
    IScreen() = default;
    virtual ~IScreen() = default;

    IScreen(const IScreen&) = delete;
    IScreen& operator=(const IScreen&) = delete;

    virtual void onCreate() = 0;
    virtual void onShow() {}
    virtual void onHide() {}

    lv_obj_t* root() const
    {
        return _screenObj;
    }

protected:
    lv_obj_t* _screenObj = nullptr;

};

}

#endif // I_SCREEN_H
