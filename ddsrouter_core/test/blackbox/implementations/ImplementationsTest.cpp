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

#include <algorithm>
#include <iostream>

#include <gtest_aux.hpp>
#include <gtest/gtest.h>
#include <test_utils.hpp>
#include <TestLogHandler.hpp>

#include <ddsrouter_core/core/DDSRouter.hpp>
#include <ddsrouter_utils/exception/ConfigurationException.hpp>
#include <ddsrouter_core/configuration/DDSRouterConfiguration.hpp>
#include <ddsrouter_core/configuration/participant/ParticipantConfiguration.hpp>
#include <ddsrouter_core/configuration/participant/SimpleParticipantConfiguration.hpp>
#include <ddsrouter_core/configuration/participant/DiscoveryServerParticipantConfiguration.hpp>
#include <ddsrouter_utils/exception/InitializationException.hpp>
#include <ddsrouter_core/types/dds/DomainId.hpp>
#include <ddsrouter_core/types/dds/GuidPrefix.hpp>
#include <ddsrouter_core/types/topic/Topic.hpp>
#include <ddsrouter_core/types/participant/ParticipantId.ipp>
#include <ddsrouter_utils/utils.hpp>
#include <ddsrouter_utils/Log.hpp>

using namespace eprosima::ddsrouter;
using namespace eprosima::ddsrouter::core;
using namespace eprosima::ddsrouter::core::types;

/**
 * Test that tries to create a DDSRouter with only one Participant.
 *
 * It expects to receive an exception
 */
TEST(ImplementationsTest, solo_participant_implementation)
{
    // For each Participant Kind
    for (ParticipantKind kind : ALL_VALID_PARTICIPANT_KINDS)
    {
        ParticipantKeySet<std::shared_ptr<configuration::ParticipantConfiguration>> participant_configurations;
        participant_configurations.insert(test::random_participant_configuration(kind));

        // Generate configuration
        ASSERT_THROW(
            configuration::DDSRouterConfiguration configuration(
                TopicKeySet<FilterTopic>(),
                TopicKeySet<FilterTopic>(),
                TopicKeySet<RealTopic>(),
                std::move(participant_configurations))
            , utils::ConfigurationException);
    }
}

/**
 * Test that creates a DDSRouter with a Pair of Participants of same kind.
 * It creates a DDSRouter with two Participants of same kind, starts it, then stops it and finally destroys it.
 *
 * This test will fail if it crashes.
 */
TEST(ImplementationsTest, pair_implementation)
{
    // TODO: Change to warning when fastdds warning:
    // [RTPS_MSG_OUT Warning] Error receiving data: receive_from: A blocking operation was interrupted by a call to WSACancelBlockingCall.:
    // A blocking operation was interrupted by a call to WSACancelBlockingCall. - 0000016CEBD18C10 (0000016CEBD17A40) ->
    // Function eprosima::fastdds::rtps::UDPChannelResource::Receive
    test::TestLogHandler test_log_handler(utils::Log::Kind::Error);

    // For each Participant Kind
    for (ParticipantKind kind : ALL_VALID_PARTICIPANT_KINDS)
    {
        ParticipantKeySet<std::shared_ptr<configuration::ParticipantConfiguration>> participant_configurations;
        participant_configurations.insert(test::random_participant_configuration(kind, 1));
        participant_configurations.insert(test::random_participant_configuration(kind, 2));

        // Generate configuration
        configuration::DDSRouterConfiguration configuration(
            TopicKeySet<FilterTopic>(),
            TopicKeySet<FilterTopic>(),
            TopicKeySet<RealTopic>(),
            std::move(participant_configurations));

        // Create DDSRouter entity
        DDSRouter router(configuration);
        // Start DDSRouter
        router.start();

        // Stop DDS Router
        router.stop();

        // Let DDSRouter object destroy for the next iteration
    }
}

/**
 * Test that creates a DDSRouter with a Pair of Participants of same kind.
 * It creates a DDSRouter with two Participants of same kind, starts it with an active topic,
 * then stops it and finally destroys it.
 *
 * This test will fail if it crashes.
 */
TEST(ImplementationsTest, pair_implementation_with_topic)
{
    // TODO: Change to warning when fastdds warning:
    // [RTPS_MSG_OUT Warning] Error receiving data: receive_from: A blocking operation was interrupted by a call to WSACancelBlockingCall.:
    // A blocking operation was interrupted by a call to WSACancelBlockingCall. - 0000016CEBD18C10 (0000016CEBD17A40) ->
    // Function eprosima::fastdds::rtps::UDPChannelResource::Receive
    test::TestLogHandler test_log_handler(utils::Log::Kind::Error);

    // For each Participant kind
    for (ParticipantKind kind : ALL_VALID_PARTICIPANT_KINDS)
    {
        TopicKeySet<RealTopic> builtin_topics = test::topic_set(
            {test::RealTopicInput("rt/chatter", "std_msgs::msg::dds_::String_", false, false, false, false)});

        ParticipantKeySet<std::shared_ptr<configuration::ParticipantConfiguration>> participant_configurations;
        participant_configurations.insert(test::random_participant_configuration(kind, 1));
        participant_configurations.insert(test::random_participant_configuration(kind, 2));

        // Generate configuration
        configuration::DDSRouterConfiguration configuration(
            TopicKeySet<FilterTopic>(),
            TopicKeySet<FilterTopic>(),
            std::move(builtin_topics),
            std::move(participant_configurations));

        // Create DDSRouter entity
        DDSRouter router(configuration);

        // Start DDSRouter
        router.start();

        // Stop DDS Router
        router.stop();

        // Let DDSRouter object destroy for the next iteration
    }
}

/**
 * Test that creates a DDSRouter with several Participants, one of each kind
 * It creates a DDSRouter with a Participant of each kind,
 * starts it with an active topic, then stops it and finally destroys it.
 *
 * This test will fail if it crashes.
 */
TEST(ImplementationsTest, all_implementations)
{
    // TODO: Change to warning when fastdds warning:
    // [RTPS_MSG_OUT Warning] Error receiving data: receive_from: A blocking operation was interrupted by a call to WSACancelBlockingCall.:
    // A blocking operation was interrupted by a call to WSACancelBlockingCall. - 0000016CEBD18C10 (0000016CEBD17A40) ->
    // Function eprosima::fastdds::rtps::UDPChannelResource::Receive
    test::TestLogHandler test_log_handler(utils::Log::Kind::Error);

    {
        // Set topic to active
        TopicKeySet<RealTopic> builtin_topics = test::topic_set(
            {test::RealTopicInput("rt/chatter", "std_msgs::msg::dds_::String_", false, false, false, false)});

        ParticipantKeySet<std::shared_ptr<configuration::ParticipantConfiguration>> participant_configurations;

        uint16_t participant_number = 0;

        // For each Participant Kind set it in configuration
        for (ParticipantKind kind : ALL_VALID_PARTICIPANT_KINDS)
        {
            // Add participant
            participant_configurations.insert(test::random_participant_configuration(kind, participant_number++));
        }

        // Generate configuration
        configuration::DDSRouterConfiguration configuration(
            TopicKeySet<FilterTopic>(),
            TopicKeySet<FilterTopic>(),
            TopicKeySet<RealTopic>(),
            std::move(participant_configurations));

        try
        {

            // Create DDSRouter entity
            DDSRouter router(configuration);

            // Start DDSRouter
            router.start();

            // Stop DDS Router
            router.stop();

            // Let DDSRouter object destroy for the next iteration
        }
        catch (const std::exception& exc)
        {
            std::cout << "Exception within test: " << exc.what() << "\n";
        }
    }
}

int main(
        int argc,
        char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
