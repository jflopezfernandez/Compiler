
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

/** @todo Include C standard library */

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include <boost/convert.hpp>
#include <boost/convert/base.hpp>
#include <boost/convert/stream.hpp>

#include <gsl/gsl>

#include "version.h"
#include "options.h"
#include "IO.h"
#include "test-configuration.h"

/** @fn int main(int argc, char *argv[])
 *
 *  @details This is the entry point of the compiler. From here the
 *  compiler will call all auxiliary functions required to process and compile
 *  the source. We are using boost::program_options because of its versatility
 *  in handling varied program input and options.
 *
 *  @returns int
 *  @returns on error  <b>EXIT_FAILURE</b>
 *  @returns otherwise <b>EXIT_SUCCESS</b>
 *
 */

int main(int argc, char *argv[])
{
    int optVerbosity = 0;
    int optOptimizationLevel = 0;

    /** @todo Add specific warning flags */

    std::string optLanguage = "C";
    std::string optLanguageStandard = "C11";
    std::string optConfigurationFileName = "<None-Set>";

    bool optPrintASTs = false;

    OptsDescription genericOptions("Generic Options");
    genericOptions.add_options()
        ("help,h", "Display help dialog")
        ("version", "Display compiler version")
        ("config-file,c", Options::value<std::string>(&optConfigurationFileName)->default_value("<None-Set>"), "Configuration file name")
    ;

    OptsDescription configurationOptions("Configuration Settings");
    configurationOptions.add_options()
        ("verbosity,v", Options::value<int>(&optVerbosity)->default_value(0), "Verbosity of output [1-5]")
        ("language,l", Options::value<std::string>(&optLanguage)->default_value("C"), "Source files language")
        ("std", Options::value<std::string>(&optLanguageStandard)->default_value("C11"), "Language standard")
        ("optimization-level,O", Options::value<int>(&optOptimizationLevel)->default_value(0), "Compiler optimization level [0 - 3]")
        ("include-path,I", Options::value<std::vector<std::string>>(), "Include path")
    ;

    OptsDescription hiddenOptions("Hidden options");
    hiddenOptions.add_options()
        ("input-file", Options::value<std::vector<std::string>>(), "input-file")
        ("print-ASTs", Options::value<bool>(&optPrintASTs)->default_value(false), "Print Compiler-Generated Abstract Syntax Trees")
    ;

    OptsDescription cmdLineOptions;
    cmdLineOptions.add(genericOptions).add(configurationOptions).add(hiddenOptions);

    OptsDescription configurationFileOptions;
    configurationFileOptions.add(configurationOptions).add(hiddenOptions);

    OptsDescription visibleOptions("Allowed options");
    visibleOptions.add(genericOptions).add(configurationOptions);

    PositionalOptsDescription positionalOptions;
    positionalOptions.add("input-file", -1);

    Options::variables_map map;

    try {
        Options::store(Options::command_line_parser(argc, argv).options(cmdLineOptions).positional(positionalOptions).run(), map);
        Options::notify(map);


        if (optConfigurationFileName != "<None-Set>")
        {
            std::ifstream configurationFileStream { optConfigurationFileName, std::ios::in };

            if (!configurationFileStream.is_open())
            {
                std::cerr << "[Error]: Failed to open configuration file.\n";

                return EXIT_FAILURE;
            }
            else
            {
                Options::store(Options::parse_config_file(configurationFileStream, configurationFileOptions), map);
                Options::notify(map);

                configurationFileStream.close();
            }
        }
        
        const std::vector<std::string> arguments = {
            "help",
            "version"
        };

        /** @todo I might have to change the argument opts from visible to all of them */
        HandleArguments(arguments, visibleOptions, map);

        /** @todo Create program version structure to handle this information in a modular way
         *  @todo Create a program configuration class to handle program settings
         *
         */

        if (map.count("version"))
        {
            /** @todo Create compiler version struct */

            std::cout << "Compiler Version: " << "0.0.1" << "\n";

            return EXIT_SUCCESS;
        }

        if (map.count("optimization-level"))
        {
            /** @todo Validate optimization level. It must be no greater than 3 and no less than 0.
             *  @todo Implement configuration class to handle log verbosity
             *
             */

            std::cout << "Optimization Level: " << optOptimizationLevel << "\n";
        }

        if (map.count("input-file"))
        {
            /** @todo Implement verbosity setting to prevent outputting to console all the time */

            std::cout
                << "Input files: "
                << map["input-file"].as<std::vector<std::string>>() << "\n";
        }
        else
        {
            std::cerr << "[Error]: No input files!\n";

            return EXIT_FAILURE;
        }

        if (map.count("include-path")) {
            /** @todo Implement verbosity setting to prevent these console logs every time */

            std::cout 
                << "Include paths: "
                << map["include-path"].as<std::vector<std::string>>() << "\n";
        }
    }
    catch (std::exception& e)
    {
        /** @todo Implement an actual error-handling module, rather than dealing with each error one by one */

        std::cerr << "[Error]: " << e.what() << "\n";
    }

    #ifdef CATCH_TEST_ENABLED
    return Catch::Session().run(argc, argv);
    #else
    return EXIT_SUCCESS;
    #endif
}