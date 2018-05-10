
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

#ifndef CC_VERSION_H_
#define CC_VERSION_H_

#include <sstream>

/** @class Version
 *
 *  @details This class holds the compiler version information. It also
 *  contains the toString() method used for returning the compiler
 *  version as a string, already formatted for output in the form
 *  <Major>.<Minor>.<Build>.
 *
 */

class Version
{
    static constexpr auto Major = 0;
    static constexpr auto Minor = 0;
    static constexpr auto Build = 1;

public:
    
    /** @fn inline static std::string toString() noexcept
     *
     *  @details This function returns the formatted compiler version ready to
     *  print. It does this by using an output string stream which it uses as
     *  a holder as it individually appends each component of the version, as
     *  well as the formatting dots, after which it returns the ostringstream
     *  using the .str() method, effectively returning a std::string.
     *
     *  @returns <b>std::string</b> containing the formatted compiler version
     *
     */

    inline static std::string toString() noexcept
    {
        std::ostringstream outputStringStream;

        outputStringStream << Version::Major << "." << Version::Minor << "." << Version::Build;

        return outputStringStream.str();
    }
};

#endif // CC_VERSION_H_