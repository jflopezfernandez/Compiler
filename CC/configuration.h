
/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Jose Fernando Lopez Fernandez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef CC_CONFIGURATION_H_
#define CC_CONFIGURATION_H_

 /** @todo Include C standard library */

#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "version.h"

class Configuration
{
    /** @todo Create enum to handle verbosity levels */
    int optionVerbosity;
    int optionOptimizationLevel;

    std::string optionLanguage;
    std::string optionLanguageStd;

    std::string optionConfigFilename;

public:
    Configuration();

    Configuration(const int verbosity, const int optimizationLevel, const std::string& language, const std::string& std, const std::string& configFilename);

    void setVerbosity(const int n);

    void setOptimizationLevel(const int n);

    void setLanguage(const std::string_view& str);

    void setLanguageStandard(const std::string_view& str);

    void setConfigFilename(const std::string_view& str);

    int verbosity() const noexcept;

    int optimizationLevel() const noexcept;

    std::string language() const noexcept;

    std::string languageStandard() const noexcept;

    std::string configurationFilename() const noexcept;

    std::string toString() const noexcept;
};

#endif // CC_CONFIGURATION_H_
