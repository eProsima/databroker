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
 * @file IConfigurationFile.hpp
 */

#ifndef _DDS_ROUTER_CONFIGURATION_ICONFIGURATION_HPP_
#define _DDS_ROUTER_CONFIGURATION_ICONFIGURATION_HPP_

#include <ddsrouter/types/constants.hpp>
#include <ddsrouter/types/ReturnCode.hpp>
#include <ddsrouter/types/RawConfiguration.hpp>
#include <ddsrouter/types/topic/FilterTopic.hpp>

namespace eprosima {
namespace ddsrouter {

/**
 * TODO
 */
class IConfigurationHandler
{
public:

    virtual ReturnCode load();

    virtual const RawConfiguration& get_raw() const;

    virtual ReturnCode reload(); // NO_DATA in case it has not been updated
};

} /* namespace ddsrouter */
} /* namespace eprosima */

#endif /* _DDS_ROUTER_CONFIGURATION_ICONFIGURATION_HPP_ */
