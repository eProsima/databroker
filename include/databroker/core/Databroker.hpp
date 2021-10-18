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
 * @file Databroker.hpp
 */

#ifndef _DATABROKER_CORE_DATABROKER_HPP_
#define _DATABROKER_CORE_DATABROKER_HPP_

#include <string>
#include <map>

#include <databroker/types/ReturnCode.hpp>
#include <databroker/configuration/DatabrokerConfiguration.hpp>
#include <databroker/participant/IDatabrokerParticipant.hpp>

namespace eprosima {
namespace databroker {

class Databroker
{
public:

    ReturnCode init(const DatabrokerConfiguration& configuration);

    ReturnCode run();

    ReturnCode stop();

    ReturnCode reload_topics();

    ReturnCode on_entity_discovered(Entity new_entity);

protected:

    DatabrokerConfiguration configuration_;

    std::map<std::string, IDatabrokerParticipant> participants_;
};

} /* namespace rtps */
} /* namespace databroker */

#endif /* _DATABROKER_CORE_DATABROKER_HPP_ */
