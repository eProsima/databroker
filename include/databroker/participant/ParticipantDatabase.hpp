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
 * @file ParticipantDatabase.hpp
 */

#ifndef _DATABROKER_PARTICIPANT_PARTICIPANTDATABASE_HPP_
#define _DATABROKER_PARTICIPANT_PARTICIPANTDATABASE_HPP_

#include <map>

#include <databroker/types/ParticipantId.hpp>
#include <databroker/writer/IDatabrokerWriter.hpp>

namespace eprosima {
namespace databroker {

using ParticipantDatabase = std::map<ParticipantId, std::shared_ptr<IDatabrokerParticipant>>

} /* namespace databroker */
} /* namespace eprosima */

#endif /* _DATABROKER_PARTICIPANT_PARTICIPANTDATABASE_HPP_ */
