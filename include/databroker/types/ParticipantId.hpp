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
 * @file ParticipantId.hpp
 */

#ifndef _DATABROKER_TYPES_PARTICIPANTID_HPP_
#define _DATABROKER_TYPES_PARTICIPANTID_HPP_

#include <string>

namespace eprosima {
namespace databroker {

//! Unique Id for each Databroker Participant
class ParticipantId
{
public:

    ParticipantId();

    ParticipantId(const std::string& id);

    virtual ~ParticipantId();

    bool is_valid() const;

    static ParticipantId invalid();

    static bool is_valid_id(const std::string& id);

    // OPERATOR OVERLOAD
    bool operator==(const ParticipantId& other) const;

    bool operator<(const ParticipantId& other) const;

protected:

    static const std::string INVALID_ID; // __invalid_databroker_participant__

    std::string id_;
};

} /* namespace databroker */
} /* namespace eprosima */

#endif /* _DATABROKER_TYPES_PARTICIPANTID_HPP_ */
