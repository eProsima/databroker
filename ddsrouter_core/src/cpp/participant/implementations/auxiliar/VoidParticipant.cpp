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

#include <participant/implementations/auxiliar/VoidParticipant.hpp>
#include <reader/implementations/auxiliar/VoidReader.hpp>
#include <ddsrouter_core/types/participant/ParticipantKind.hpp>
#include <writer/implementations/auxiliar/VoidWriter.hpp>

namespace eprosima {
namespace ddsrouter {
namespace core {

using namespace eprosima::ddsrouter::core::types;

VoidParticipant::VoidParticipant(
        const ParticipantId& id)
    : id_(id)
{
}

ParticipantId VoidParticipant::id() const noexcept
{
    return id_;
}

ParticipantKind VoidParticipant::kind() const noexcept
{
    return ParticipantKind::VOID;
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

void VoidParticipant::delete_writer(
        std::shared_ptr<IWriter> writer) noexcept
{
}

void VoidParticipant::delete_reader(
        std::shared_ptr<IReader> reader) noexcept
{
}

} /* namespace core */
} /* namespace ddsrouter */
} /* namespace eprosima */
