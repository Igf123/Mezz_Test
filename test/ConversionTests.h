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
#ifndef Mezz_Test_Conversion_h
#define Mezz_Test_Conversion_h

/// @file
/// @brief Tests for conversions used internally and presented as part of the Mezz Test API. These test are done in the
/// verbose style for example purposes.

#include "MezzTest.h"

using Mezzanine::Testing::StringToTestResult;
using Mezzanine::Testing::TestResult;

SAVE_WARNING_STATE
SUPPRESS_VC_WARNING(4625) // BS about implicit copy constructors, despite explicit deletion in parent class.
                          // Any time you don't use the test group macros you might need to handle VS warnings.
class ConversionTests : public Mezzanine::Testing::AutomaticTestGroup
{
    public:
        virtual ~ConversionTests() override = default;

        virtual void operator ()() override;
        virtual Mezzanine::String Name() const override
            { return "Conversion"; }
};

RESTORE_WARNING_STATE

void ConversionTests::operator ()()
{
    TEST_EQUAL("SuccessStringConvertsToResult",       TestResult::Success,       StringToTestResult("Success") )
    TEST_EQUAL("SkippedStringConvertsToResult",       TestResult::Skipped,       StringToTestResult("Skipped") )
    TEST_EQUAL("WarningStringConvertsToResult",       TestResult::Warning,       StringToTestResult("Warning") )
    TEST_EQUAL("CancelledStringConvertsToResult",     TestResult::Cancelled,     StringToTestResult("Cancelled") )
    TEST_EQUAL("InconclusiveStringConvertsToResult",  TestResult::Inconclusive,  StringToTestResult("Inconclusive") )
    TEST_EQUAL("UnknownStringConvertsToResult",       TestResult::Unknown,       StringToTestResult("Unknown") )
    TEST_EQUAL("FailedStringConvertsToResult",        TestResult::Failed,        StringToTestResult("Failed") )
    TEST_EQUAL("NotApplicableStringConvertsToResult", TestResult::NotApplicable, StringToTestResult("NotApplicable") )

    TEST_THROW("BedEmptyStrings",       std::invalid_argument, []{ StringToTestResult(""); } )
    TEST_THROW("BadSStringTestResults", std::invalid_argument, []{ StringToTestResult("Suplex"); } )
    TEST_THROW("BadWStringTestResults", std::invalid_argument, []{ StringToTestResult("Wrong(YesThisIs)"); } )
    TEST_THROW("BadCStringTestResults", std::invalid_argument, []{ StringToTestResult("ClearlyWrong(YesThisIs)"); } )
    TEST_THROW("BadIStringTestResults", std::invalid_argument, []{ StringToTestResult("Indecipherable"); } )
    TEST_THROW("BadUStringTestResults", std::invalid_argument, []{ StringToTestResult("Unknowable"); } )
    TEST_THROW("BadFStringTestResults", std::invalid_argument, []{ StringToTestResult("FThatIsYouGradeNow"); } )
    TEST_THROW("BadNStringTestResults", std::invalid_argument, []{ StringToTestResult("NeverApplicable"); } )

    // These tests aresort of an odd. These tests that XML output which is read by Jenkins and other test
    // result aggregation tools creates properly formatted XML when the test name might interfere. These won't
    // be reported in tests directly but will break our BTS Continuous integration if they don't work.
    TEST("Test&Ampersands&InTestNamesBreaksNothing&", true)
    TEST("Test\"QupteInTestNamesBreaksNothing\"", true)
    TEST("Test'ApostropheInTestNamesBreaksNothing'", true)
    TEST("Test>GreaterThanInTestNamesBreaksNothing>", true)
    TEST("Test<LessThanInTestNamesBreaksNothing<", true)
}

#endif
