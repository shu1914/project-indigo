/**
 * @file Platform.h
 * @brief Implements the IUserInterface interface.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * UserInterface creates UI elements, widgets and screens.
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "IUserInterface.h"

namespace indigo
{

class UserInterface : public IUserInterface
{

public:

    explicit UserInterface(
            IPokedex& pokedex);

    bool initialize() override;

    void shutdown() override;

    IPokedex& _pokedex;

}; // end class UserInterface

} // end namespace indigo

#endif // end USER_INTERFACE_H
