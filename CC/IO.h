#ifndef CC_IO_H_
#define CC_IO_H_

#include <iostream>

template <typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_ostream<CharT, Traits>&
NL(std::basic_ostream<CharT, Traits>& outputStream)
{
    return outputStream << outputStream.widen('\n');
}

/** @fn template <typename CharT, typename Traits = std::char_traits<CharT>, typename T> std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& outputStream, const std::vector<T>& elements)
 *
 *  @details This function takes in a std::vector containing any datatype
 *  T, and iterates through the vector, printing out each element one by one, 
 *  inserting a space in between.
 *
 *  @note The datatype T must have the output stream operator (<<) defined in
 *  order for this function to work.
 *
 *  @todo Move this function into the IO Module
 *
 */

template <typename CharT, typename Traits = std::char_traits<CharT>, typename T>
std::basic_ostream<CharT, Traits>&
operator << (std::basic_ostream<CharT, Traits>& outputStream, const std::vector<T>& elements)
{
    for (auto& element : elements)
    {
        outputStream << element << ' ';
    }

    return outputStream;
}

#endif // CC_IO_H_