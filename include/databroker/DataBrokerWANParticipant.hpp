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
 * @file DataBrokerWANParticipant.hpp
 *
 */

#ifndef EPROSIMA_DATABROKER_DATABROKERWANPARTICIPANT_HPP
#define EPROSIMA_DATABROKER_DATABROKERWANPARTICIPANT_HPP

#include <databroker/DataBrokerParticipant.hpp>

namespace eprosima {
namespace databroker {

class DataBrokerWANParticipant : public DataBrokerParticipant
{
public:

    DataBrokerWANParticipant(
            eprosima::fastdds::dds::DomainParticipantListener* listener,
            eprosima::fastrtps::rtps::GuidPrefix_t server_guid,
            uint32_t domain = 0,
            std::string name = "DataBroker Participant")
        : DataBrokerParticipant(listener, domain, name)
        , guid_(server_guid)
    {
    }

    eprosima::fastrtps::rtps::GuidPrefix_t guid() override
    {
        return guid_;
    }

protected:

    eprosima::fastrtps::rtps::GuidPrefix_t guid_;

};

} /* namespace databroker */
} /* namespace eprosima */

#endif /* EPROSIMA_DATABROKER_DATABROKERWANPARTICIPANT_HPP */
