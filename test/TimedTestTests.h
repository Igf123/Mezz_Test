// © Copyright 2010 - 2019 BlackTopp Studios Inc.
/* This file is part of The Mezzanine Engine.

    The Mezzanine Engine is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The Mezzanine Engine is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Mezzanine Engine.  If not, see <http://www.gnu.org/licenses/>.
*/
/* The original authors have included a copy of the license specified above in the
   'Docs' folder. See 'gpl.txt'
*/
/* We welcome the use of the Mezzanine engine to anyone, including companies who wish to
   Build professional software and charge for their product.

   However there are some practical restrictions, so if your project involves
   any of the following you should contact us and we will try to work something
   out:
    - DRM or Copy Protection of any kind(except Copyrights)
    - Software Patents You Do Not Wish to Freely License
    - Any Kind of Linking to Non-GPL licensed Works
    - Are Currently In Violation of Another Copyright Holder's GPL License
    - If You want to change our code and not add a few hundred MB of stuff to
        your distribution

   These and other limitations could cause serious legal problems if you ignore
   them, so it is best to simply contact us or the Free Software Foundation, if
   you have any questions.

   Joseph Toppi - toppij@gmail.com
   John Blackwood - makoenergy02@gmail.com
*/
#ifndef Mezz_Test_TimedTests_h
#define Mezz_Test_TimedTests_h

/// @file
/// @brief Header for unit tests for the testing framework, but only the time sensitive parts.

#include "MezzTest.h"

#include <stdexcept>
#include <thread>
#include <random>


/// @brief TestTests to verify that warnings works correctly.
/// @details This class is not called directly by the Unit Test framework and is called by the TimedTestTest to verify
/// everything fails.
SILENT_TEST_GROUP(WarningTimedTestTests, WarningTimedTest)
{
    // Here are some examples of tests that should warn.
    TEST_TIMED("TestTimedWarning", std::chrono::microseconds(5000), std::chrono::microseconds(1000), []{});
    TEST_TIMED_UNDER("TestTimedUnderWarning", std::chrono::microseconds(1),
               []{ std::this_thread::sleep_for( std::chrono::milliseconds(5) ); });
}

/// @brief This is the actual test class. This tests our test macros that are time sensitive.
BENCHMARK_TEST_GROUP(TimedTestTests, TimedTest)
{
    // Lets you make a random time for these tests so if this is run on a bunch of VMs on the same hardware there will
    // be subtle variations in the timing and it won't cause all the VMs to wake at the same time and possibly delay
    // some of the tests.
    std::mt19937 MersennTwisterRandomSource;
    MersennTwisterRandomSource.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> DistLength(1000,1500);
    std::uniform_int_distribution<std::mt19937::result_type>::result_type SleepTime =
            DistLength(MersennTwisterRandomSource);

    // Positive tests. This group should serve as examples of passing tests.
    // These amounts of time are too short to be measuring this way, longer running tests can be more precise.
    TEST_TIMED("TestTimedPassing", std::chrono::milliseconds(SleepTime), std::chrono::milliseconds(200),
            [SleepTime]{ std::this_thread::sleep_for( std::chrono::milliseconds(SleepTime) ); });

    TEST_TIMED_UNDER("TestTimedUnderPassing", std::chrono::microseconds(5000), []{ });

    // Warning timed tests.
    class WarningTimedTestTests Warnifier;
    Warnifier();
    for(const Mezzanine::Testing::TestData& SingleResult : Warnifier)
        { TEST_EQUAL(SingleResult.TestName, Mezzanine::Testing::TestResult::Warning, SingleResult.Results); }
}

#endif
