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
 * @file VoidParticipant.cpp
 */

#include <ddsrouter/participant/implementations/auxiliar/VoidParticipant.hpp>
#include <ddsrouter/reader/implementations/auxiliar/VoidReader.hpp>
#include <ddsrouter/writer/implementations/auxiliar/VoidWriter.hpp>
#include <ddsrouter/types/ParticipantType.hpp>

namespace eprosima {
namespace ddsrouter {

VoidParticipant::VoidParticipant(
        ParticipantConfiguration participant_configuration)
    : configuration_(participant_configuration)
{
}

VoidParticipant::~VoidParticipant()
{
}

ParticipantId VoidParticipant::id() const
{
    return configuration_.id();
}

ParticipantType VoidParticipant::type() const
{
    return ParticipantType::VOID;
}

std::shared_ptr<IWriter> VoidParticipant::create_writer(
        RealTopic topic)
{
    return std::make_shared<VoidWriter>();
}

std::shared_ptr<IReader> VoidParticipant::create_reader(
        RealTopic topic)
{
    return std::make_shared<VoidReader>();
}

} /* namespace ddsrouter */
} /* namespace eprosima */
