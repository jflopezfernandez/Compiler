
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

#ifndef CC_OPTIONS_H_
#define CC_OPTIONS_H_

#include <boost/optional.hpp>
#include <boost/program_options.hpp>

#include "configuration.h"

/** @namespace Options
 *
 *  @brief Alias for boost::program_options
 *
 */

namespace Options = boost::program_options;

using OptsDescription           = Options::options_description;
using PositionalOptsDescription = Options::positional_options_description;

/** @fn inline void PrintHelp() noexcept
 *
 *  @details This function simply prints the compiler help dialog.
 *
 */

inline void PrintHelp(const OptsDescription& options) noexcept
{
    std::cout << options << "\n";

    /** @todo Maybe create a list of arguments that trigger an exit call and handle all in a more modular fashion */
    std::exit(EXIT_SUCCESS);
}

inline void PrintVersion() noexcept
{
    std::cout << "Version: " << Version::toString() << "\n";

    std::exit(EXIT_SUCCESS);
}

/** @fn void HandleArgument(const OptsDescription& options, const Options::variables_map& map, const std::string& arg)
 *
 *  @details I'm looking for a better way to handle all the argument parsing
 *  and processing, rather than throwing it all in main the way it's shown in 
 *  the example code. I'm trying to come up with a way of creating a generic
 *  handler function that determines the action to take based on the actual
 *  argument passed. This might end up being a map in a map, though, I need
 *  to plan it out.
 *
 *  @returns <b>void</b>
 *
 */

inline void HandleArgument(const OptsDescription& options, const Options::variables_map& map, const std::string& arg)
{
    if (map.count(arg))
    {
        if (arg == "help")
        {
            PrintHelp(options);
        } else if (arg == "version") {
            PrintVersion();
        }
    }

    /** @todo Finish implementing this function with al the arguments */
}

/** @fn inline void HandleArguments(const std::vector<std::string>& args, const OptsDescription& options, const Options::variables_map& map)
 *
 *  @details This function is essentially just a wrapper for this range-based
 *  for loop. All it does differently is it takes a std::vector of std::strings,
 *  rather than just a single string, and it calls the HandleArgument() function
 *  individually for every element in the arguments vector.
 *
 *  @returns <b>void</b>
 *
 */

inline void HandleArguments(const std::vector<std::string>& args, const OptsDescription& options, const Options::variables_map& map)
{
    for (auto& arg : args)
    {
        HandleArgument(options, map, arg);
    }
}

#endif // CC_OPTIONS_H_
