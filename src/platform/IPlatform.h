/**
 * @file IPlatform.h
 * @brief Defines the platform abstraction exposed to the application.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-12
 * 
 * This interface provides the public contract for platform services such as
 * initialization, event processing, and shutdown. Consumers depend on this
 * interface rather than a concrete implementation, enabling dependency
 * injection and unit testing.
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef I_PLATFORM_H
#define I_PLATFORM_H

#include "common/error/Result.h"

namespace indigo
{

class IPlatform
{

public:

    virtual ~IPlatform() {}

    virtual Result initialize() = 0;

    virtual void shutdown() = 0;

    virtual void run() = 0;

}; // end class IPlatform

} // end namespace indigo

#endif // end I_PLATFORM_H
