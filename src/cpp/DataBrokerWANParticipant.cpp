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
 * @file DataBrokerParticipant.cpp
 *
 */

#include <databroker/DataBrokerWANParticipant.hpp>

namespace eprosima {
namespace databroker {

DataBrokerWANParticipant::DataBrokerWANParticipant(
        eprosima::fastdds::dds::DomainParticipantListener* listener,
        eprosima::fastrtps::rtps::GuidPrefix_t server_guid,
        uint32_t domain /* = 0 */,
        std::string name /* = "DataBroker Participant" */)
    : DataBrokerParticipant(listener, domain, name)
    , guid_(server_guid)
{
}

eprosima::fastrtps::rtps::GuidPrefix_t DataBrokerWANParticipant::guid()
{
    return guid_;
}

eprosima::fastdds::dds::DataWriterQos DataBrokerWANParticipant::default_datawriter_qos()
{
    eprosima::fastdds::dds::DataWriterQos datawriter_qos = DataBrokerParticipant::default_datawriter_qos();

    datawriter_qos.publish_mode().kind = eprosima::fastdds::dds::PublishModeQosPolicyKind::ASYNCHRONOUS_PUBLISH_MODE;
    datawriter_qos.reliability().kind = eprosima::fastdds::dds::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
    datawriter_qos.durability().kind = eprosima::fastdds::dds::DurabilityQosPolicyKind::TRANSIENT_LOCAL_DURABILITY_QOS;

    return datawriter_qos;
}

eprosima::fastdds::dds::DataReaderQos DataBrokerWANParticipant::default_datareader_qos()
{
    eprosima::fastdds::dds::DataReaderQos datareader_qos = DataBrokerParticipant::default_datareader_qos();

    datareader_qos.reliability().kind = eprosima::fastdds::dds::ReliabilityQosPolicyKind::RELIABLE_RELIABILITY_QOS;
    datareader_qos.durability().kind = eprosima::fastdds::dds::DurabilityQosPolicyKind::TRANSIENT_LOCAL_DURABILITY_QOS;

    return datareader_qos;
}

} /* namespace databroker */
} /* namespace eprosima */
