
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

#include "configuration.h"

Configuration::Configuration()
    : optionVerbosity(0), optionOptimizationLevel(0), optionLanguage("C"), optionLanguageStd("C11"), optionConfigFilename("<None-Set>")
{
    // Default ctor
}

Configuration::Configuration(const int verbosity, const int optimizationLevel, const std::string& language, const std::string& std, const std::string& configFilename)
    : optionVerbosity(verbosity), optionOptimizationLevel(optimizationLevel), optionLanguage(language), optionLanguageStd(std), optionConfigFilename(configFilename)
{
    /** @todo Validate each and every input */
}

void Configuration::setVerbosity(const int n)
{
    optionVerbosity = n;
}

void Configuration::setOptimizationLevel(const int n)
{
    optionOptimizationLevel = n;
}

void Configuration::setLanguage(const std::string_view& str)
{
    optionLanguage = str;
}

void Configuration::setLanguageStandard(const std::string_view& str)
{
    optionLanguageStd = str;
}

void Configuration::setConfigFilename(const std::string_view& str)
{
    optionConfigFilename = str;
}

int Configuration::verbosity() const noexcept
{
    return optionVerbosity;
}

int Configuration::optimizationLevel() const noexcept
{
    return optionOptimizationLevel;
}

std::string Configuration::language() const noexcept
{
    return optionLanguage;
}

std::string Configuration::languageStandard() const noexcept
{
    return optionLanguageStd;
}

std::string Configuration::configurationFilename() const noexcept
{
    return optionConfigFilename;
}

/** @todo Finish implementing this function */
std::string Configuration::toString() const noexcept
{
    std::ostringstream outputStringStream;

    outputStringStream << "Configuration: " << "\n";
    outputStringStream << "\t" << "Verbosity: " << verbosity() << "\n";
    outputStringStream << "\t" << "Language: " << language() << "\n";
    outputStringStream << "\t" << "Standard: " << languageStandard() << "\n";
    outputStringStream << "\t" << "Config File: " << configurationFilename() << "\n" << "\n";

    return outputStringStream.str();
}
