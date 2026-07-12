/**
 * @file IUserInterface.h
 * @brief Defines the UI abstraction exposed to the application.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * This interface provides user interface shown to the user.
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef I_USER_INTERFACE_H
#define I_USER_INTERFACE_H

#include "pokedex/IPokedex.h"

namespace indigo
{

class IUserInterface
{

public:

    virtual bool initialize() = 0;

    virtual void shutdown() = 0;

}; // end class IUserInterface

} // end namespace indigo

#endif // end I_USER_INTERFACE_H
