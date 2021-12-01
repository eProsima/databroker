// Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file PeriodicEventHandler.hpp
 */

#ifndef _DDSROUTER_USERINTERFACE_PERIODICEVENTHANDLER_HPP_
#define _DDSROUTER_USERINTERFACE_PERIODICEVENTHANDLER_HPP_

#include <functional>
#include <thread>

#include <ddsrouter/types/Time.hpp>
#include <ddsrouter/user_interface/EventHandler.hpp>

namespace eprosima {
namespace ddsrouter {
namespace ui {

/**
 * It implements the functionality to raise callback periodically with
 * a specific time period.
 *
 * The callback is repeated indefinitely until the object is destroyed.
 */
class PeriodicEventHandler : public EventHandler<>
{
public:

    /**
     * @brief Construct a new Event Handler
     *
     * @param period_time : period time in miliseconds for Event to occur.
     */
    PeriodicEventHandler(
        Duration_ms period_time) noexcept;

    /**
     * @brief Construct a new Event Handler with specific callback
     *
     * @param callback : callback to call when period time comes
     * @param period_time : period time in miliseconds for Event to occur.
     */
    PeriodicEventHandler(
        std::function<void()> callback,
        Duration_ms period_time) noexcept;

    ~PeriodicEventHandler();

protected:

    /**
     * @brief Internal thread to wait for period and call callback
     *
     * @warning callback is called from this method, so until the
     * callback does not finish, the time will not restart again.
     */
    void period_thread_routine_() noexcept;

    /**
     * @brief Create thread and start period time
     *
     * Only called from constructor
     */
    void start_period_thread_() noexcept;

    /**
     * @brief Stop period time and detached thread
     *
     * Only called from constructor
     */
    void stop_period_thread_() noexcept;

    //! Period time in miliseconds
    Duration_ms period_time_;

    //! Period thread
    std::thread period_thread_;
};

} /* namespace ui */
} /* namespace ddsrouter */
} /* namespace eprosima */

#endif /* _DDSROUTER_USERINTERFACE_PERIODICEVENTHANDLER_HPP_ */
