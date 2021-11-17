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
 * @file ParticipantFactory.cpp
 *
 */

#include <ddsrouter/configuration/ParticipantConfiguration.hpp>
#include <ddsrouter/exceptions/ConfigurationException.hpp>
#include <ddsrouter/participant/implementations/auxiliar/VoidParticipant.hpp>
#include <ddsrouter/participant/ParticipantFactory.hpp>
#include <ddsrouter/types/utils.hpp>

namespace eprosima {
namespace ddsrouter {

// TODO: Add logs

std::shared_ptr<IParticipant> ParticipantFactory::create_participant(
        ParticipantConfiguration participant_configuration,
            std::shared_ptr<PayloadPool> payload,
            std::shared_ptr<DiscoveryDatabase> discovery_database)
{
    // Create a new Participant depending on the ParticipantType specified by the configuration
    switch (participant_configuration.type())
    {
    case ParticipantType::VOID:
        // VoidParticipant
        return std::make_shared<VoidParticipant>(participant_configuration.id());
        break;

    case ParticipantType::INVALID:
        // TODO: Add warning log
        throw ConfigurationException(utils::Formatter() << "Type: " << participant_configuration.type()
            << " is not a valid" << " participant type name.");
        break;

    default:
        // This should not happen as every type must be in the switch
        assert(false);
        break;
    }
}

} /* namespace ddsrouter */
} /* namespace eprosima */
