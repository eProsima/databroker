// Copyright 2022 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#include <gtest_aux.hpp>
#include <gtest/gtest.h>

#include <ddsrouter_utils/macros/recursive_macros.hpp>

namespace test {

int global_int_value = 0;
std::string global_str_value = "";

#define SUM_TO_GLOBAL_INT(x) test::global_int_value += x;
#define SUM_CHAR_TO_GLOBAL_STR(c) test::global_str_value.push_back(c);

} /* namespace test */

/**
 * Test \c COUNT_ARGUMENTS macro
 *
 * Cases:
 *  0
 *  1
 *  5
 *  9
 */
TEST(recursiveMacrosTest, count_arguments)
{
    // 0
    {
        ASSERT_EQ(
            0,
            COUNT_ARGUMENTS()
        );
    }

    // 1
    {
        ASSERT_EQ(
            1,
            COUNT_ARGUMENTS(
                "el1"
            )
        );
    }

    // 5
    {
        ASSERT_EQ(
            5,
            COUNT_ARGUMENTS(
                "el1", "el2", "el3", "el4", "el5"
            )
        );
    }

    // 9
    {
        ASSERT_EQ(
            9,
            COUNT_ARGUMENTS(
                "el1", "el2", "el3", "el4", "el5",
                "el1", "el2", "el3", "el4"
            )
        );
    }
}

/**
 * Test \c APPLY_MACRO_FOR_EACH macro
 *
 * Cases:
 *  addition
 *  string concatenation
 */
TEST(recursiveMacrosTest, apply_APPLY_MACRO_FOR_EACH)
{

    // addition
    {
        APPLY_MACRO_FOR_EACH(
            SUM_TO_GLOBAL_INT,
            1,
            2,
            3
        );

        ASSERT_EQ(test::global_int_value, 6);
    }

    // TODO: This does not work on windows, check why
    // string concatenation
    // {
    //     APPLY_MACRO_FOR_EACH(
    //         SUM_CHAR_TO_GLOBAL_STR,
    //         'H',
    //         'e',
    //         'l',
    //         'l',
    //         '0',
    //         '.'
    //     );

    //     ASSERT_EQ(test::global_str_value, "Hell0.");
    // }
}

int main(
        int argc,
        char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
