/*
 *  Created by Phil on 28/10/2010.
 *  Copyright 2010 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_ASSERTIONRESULT_H_INCLUDED
#define TWOBLUECUBES_CATCH_ASSERTIONRESULT_H_INCLUDED

#include <string>
#include "catch_result_type.h"

namespace Catch {

    struct AssertionInfo
    {
        AssertionInfo() {}
        AssertionInfo( const std::string& _macroName, const SourceLineInfo& _lineInfo, const std::string& _capturedExpression = "", bool _shouldNegate = false )
        :   macroName( _macroName ),
            lineInfo( _lineInfo ),
            capturedExpression( _capturedExpression )
        {
            if( _shouldNegate )
                capturedExpression = "!" + _capturedExpression;
        }

        std::string macroName;
        SourceLineInfo lineInfo;
        std::string capturedExpression;
    };

    struct AssertionResultData
    {
        AssertionResultData() : resultType( ResultWas::Unknown ) {}

        std::string reconstructedExpression;
        std::string message;
        ResultWas::OfType resultType;
    };

    class AssertionResult {
    public:
        AssertionResult();
        AssertionResult( const AssertionInfo& info, const AssertionResultData& data );
        ~AssertionResult();
        
        bool ok() const;
        ResultWas::OfType getResultType() const;
        bool hasExpression() const;
        bool hasMessage() const;
        std::string getExpression() const;
        bool hasExpandedExpression() const;
        std::string getExpandedExpression() const;
        std::string getMessage() const;
        SourceLineInfo getSourceInfo() const;
        std::string getTestMacroName() const;

    protected:
        AssertionInfo m_info;
        AssertionResultData m_resultData;
    };
    
} // end namespace Catch

#endif // TWOBLUECUBES_CATCH_ASSERTIONRESULT_H_INCLUDED
