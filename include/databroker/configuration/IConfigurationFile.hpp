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

#ifndef _DATABROKER_CONFIGURATION_ICONFIGURATION_HPP_
#define _DATABROKER_CONFIGURATION_ICONFIGURATION_HPP_

#include <string>

#include <databroker/types/constants.hpp>
#include <databroker/types/ReturnCode.hpp>

namespace eprosima {
namespace databroker {

class IConfigurationFile
{
public:

    IConfigurationFile()
        : file_name_(DEFAULT_CONFIGURATION_FILE_NAME)
    {}

    IConfigurationFile(const std::string& file_name)
        : file_name_(file_name)
    {}

    const std::string& file_name() const
    {
        return file_name_;
    }

    virtual ReturnCode load();

    virtual bool reload();

protected:

    std::string file_name_;
};

} /* namespace rtps */
} /* namespace databroker */

#endif /* _DATABROKER_CONFIGURATION_ICONFIGURATION_HPP_ */
