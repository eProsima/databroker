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
 * @file SpecificWriterQoS.cpp
 *
 */

#include <ddsrouter_core/types/dds/SpecificWriterQoS.hpp>
#include <ddsrouter_utils/utils.hpp>

namespace eprosima {
namespace ddsrouter {
namespace core {
namespace types {

bool SpecificWriterQoS::operator< (const SpecificWriterQoS& other) const noexcept
{
    // Ownership
    if (this->ownership_strength.value < other.ownership_strength.value)
    {
        return true;
    }
    else if (this->ownership_strength.value > other.ownership_strength.value)
    {
        return false;
    }

    // NOTE: PartitionQosPolicy operator< out of class implementation, this should be in Fast DDS file.
    if(this->partitions.size() < other.partitions.size())
    {
        return true;
    }
    else if(this->partitions.size() > other.partitions.size())
    {
        return false;
    }

    auto const this_names = this->partitions.getNames();
    auto const other_names = other.partitions.getNames();

    for (int i=0; i<this_names.size(); ++i)
    {
        if (this_names[i] < other_names[i])
        {
            return true;
        }
        else if (this_names[i] > other_names[i])
        {
            return false;
        }
    }

    return false;
}

bool SpecificWriterQoS::operator== (const SpecificWriterQoS& other) const noexcept
{
    return this->partitions == other.partitions && this->ownership_strength == other.ownership_strength;
}

std::ostream& operator <<(
        std::ostream& os,
        const PartitionQosPolicy& qos)
{
    os << "Partitions{";
    for (auto const& p : qos)
    {
        os << p.name() << ";";
    }
    os << "}";
    return os;
}

std::ostream& operator <<(
        std::ostream& os,
        const OwnershipStrengthQosPolicy& qos)
{
    os << "OwnershipStrength{" << qos.value << "}";
    return os;
}

std::ostream& operator <<(
        std::ostream& os,
        const SpecificWriterQoS& qos)
{
    os <<
        "SpecificWriterQoS{" << qos.partitions <<
        ";" << qos.ownership_strength <<
        "}";

    return os;
}

} /* namespace types */
} /* namespace core */
} /* namespace ddsrouter */
} /* namespace eprosima */
