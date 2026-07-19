/**
 * @file ScreenManager.h
 * @brief Screen Manager
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-19
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include <memory>
#include <utility>
#include "IScreen.h"

namespace indigo
{

class ScreenManager
{
public:
    ScreenManager() = default;
    ~ScreenManager() = default;

    template<typename T, typename... Args>
    void show(Args&&... args);

    void clear()
    {
        if (_current)
        {
            _current->onHide();
            _current.reset();
        }
    }

    IScreen* current() const
    {
        return _current.get();
    }

private:
    std::unique_ptr<IScreen> _current;
};

template<typename T, typename... Args>
void ScreenManager::show(Args&&... args)
{
    auto newScreen = std::make_unique<T>(std::forward<Args>(args)...);
    newScreen->onCreate();

    if (_current)
    {
        _current->onHide();
    }

    lv_screen_load(newScreen->root());
    _current = std::move(newScreen);
    _current->onShow();
}

}

#endif // SCREEN_MANAGER_H
