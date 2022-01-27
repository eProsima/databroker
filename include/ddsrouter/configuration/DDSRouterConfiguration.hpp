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
 * @file DDSRouterConfiguration.hpp
 */

#ifndef _DDSROUTER_CONFIGURATION_DDSROUTERCONFIGURATION_HPP_
#define _DDSROUTER_CONFIGURATION_DDSROUTERCONFIGURATION_HPP_

#include <memory>
#include <set>

#include <ddsrouter/configuration/DDSRouterReloadConfiguration.hpp>
#include <ddsrouter/configuration/participant/ParticipantConfiguration.hpp>
#include <ddsrouter/types/topic/FilterTopic.hpp>
#include <ddsrouter/types/topic/RealTopic.hpp>

namespace eprosima {
namespace ddsrouter {
namespace configuration {

/**
 * This class joins every DDSRouter feature configuration and includes methods
 * to interact with this configuration.
 */
class DDSRouterConfiguration : public DDSRouterReloadConfiguration
{
public:

    /**
     * TODO
     */
    DDSRouterConfiguration(
            std::set<std::shared_ptr<FilterTopic>> allowlist,
            std::set<std::shared_ptr<FilterTopic>> blocklist,
            std::set<std::shared_ptr<RealTopic>> builtin_topics,
            std::set<std::shared_ptr<ParticipantConfiguration>> participants_configurations);

    /**
     * @brief Return a set with the different \c ParticipantConfigurations in the yaml
     *
     * Every participant configuration is an object of the specific class set in \c ParticipantKind .
     *
     * @return List of \c ParticipantConfigurations
     */
    std::set<std::shared_ptr<ParticipantConfiguration>> participants_configurations() const noexcept;

    bool is_valid(
            utils::Formatter& error_msg) const noexcept override;

    void reload(const DDSRouterReloadConfiguration& new_configuration);

protected:

    static bool check_correct_configuration_object_(
        const std::shared_ptr<ParticipantConfiguration> configuration);

    std::set<std::shared_ptr<ParticipantConfiguration>> participants_configurations_;
};

} /* namespace configuration */
} /* namespace ddsrouter */
} /* namespace eprosima */

#endif /* _DDSROUTER_CONFIGURATION_DDSROUTERCONFIGURATION_HPP_ */
