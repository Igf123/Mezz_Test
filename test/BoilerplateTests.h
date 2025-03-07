// © Copyright 2010 - 2020 BlackTopp Studios Inc.
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
#ifndef Mezz_Test_Boilerplate_h
#define Mezz_Test_Boilerplate_h

/// @file
/// @brief A Test header suitable for copying as a starting point for tests.
/// @details This class's name is the filename. All test groups must inherit from Mezzanine::Testing::UnitTestGroup
/// but can do so by inheriting from one of the "policy implementing" unit test groupo.
/// @n
/// Tests in the Mezzanine::Testing::AutomaticTestGroup will run in threads along with most of the other test threads
/// and

// Add other headers you need here
#include "MezzTest.h"

// Pick any of the following styles to create your tests

/*
/// @brief The test suite will find all classes identified as tests in CMake, but they need to look like this.
class MEZZ_LIB BoilerplateTests : public Mezzanine::Testing::UnitTestGroup
//class MEZZ_LIB ConsoleLogicTests : public Mezzanine::Testing::AutomaticTestGroup
//class MEZZ_LIB WarningTimedTestTests : public Mezzanine::Testing::BenchmarkTestGroup
{
    public:
        /// @brief Default Constructor
        virtual ~BoilerplateTests() = default;

        /// @brief This is what will be run when executing the test
        virtual void operator ()() override;

        /// @brief This is used as the name of the test on the command prompt,
        virtual Mezzanine::String Name() const override
            { return "BoilerPlate"; }
};


void BoilerplateTests ::operator ()()
{
    // They should use the macros from TestMacros.h to automatically function, filename and line number.
    //TEST("ExamplePassingTest", true);
}

// */


DEFAULT_TEST_GROUP(BoilerplateTests, Boilerplate)
{
    // Tests should use the macros from TestMacros.h to automatically function, filename and line number.
    TEST("ExamplePassingTest", true)
}




#endif
