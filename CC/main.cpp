
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
#include <boost/program_options.hpp>

#include <Catch/catch.hpp>

#include <gsl/gsl>

//const std::vector<std::string> ops = "4D 5A 90 00 03 00 00 00 04 00 00 00 FF FF 00 00 B8 00 00 00 00 00 00 00 40 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 80 00 00 00 0E 1F BA 0E 00 B4 09 CD 21 B8 01 4C CD 21 54 68 69 73 20 70 72 6F 67 72 61 6D 20 63 61 6E 6E 6F 74 20 62 65 20 72 75 6E 20 69 6E 20 44 4F 53 20 6D 6F 64 65 2E 0D 0D 0A 24 00 00 00 00 00 00 00 50 45 00 00 64 86 02 00 0D A2 F0 5A 00 06 00 00 35 00 00 00 F0 00 27 02 0B 02 02 1E 00 02 00 00 00 02 00 00 00 00 00 00 00 10 00 00 00 10 00 00 00 00 40 00 00 00 00 00 00 10 00 00 00 02 00 00 04 00 00 00 00 00 00 00 05 00 02 00 00 00 00 00 00 30 00 00 00 02 00 00 F0 20 00 00 03 00 00 00 00 00 20 00 00 00 00 00 00 10 00 00 00 00 00 00 00 00 10 00 00 00 00 00 00 10 00 00 00 00 00 00 00 00 00 00 10 00 00 00 00 00 00 00 00 00 00 00 00 20 00 00 14 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00";
//const std::vector<std::string> ops = {
//    "4D", "5A", "90", "00 ", "03", "00", "00", "00", "04", "00", "00",
//    "00", "FF", "FF", "00", "00", "B8", "00", "00", "00", "00", "00", "00", "00", "40 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "80 ", "00 ", "00 ", "00 ", "0E ", "1F ", "BA ", "0E ", "00 ", "B4 ", "09 ", "CD ", "21 ", "B8 ", "01 ", "4C ", "CD ", "21 ", "54 ", "68 ", "69 ", "73 ", "20 ", "70 ", "72 ", "6F ", "67 ", "72 ", "61 ", "6D ", "20 ", "63 ", "61 ", "6E ", "6E ", "6F ", "74 ", "20 ", "62 ", "65 ", "20 ", "72 ", "75 ", "6E ", "20 ", "69 ", "6E ", "20 ", "44 ", "4F ", "53 ", "20 ", "6D ", "6F ", "64 ", "65 ", "2E ", "0D ", "0D ", "0A ", "24 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "50 ", "45 ", "00 ", "00 ", "64 ", "86 ", "02 ", "00 ", "0D ", "A2 ", "F0 ", "5A ", "00 ", "06 ", "00 ", "00 ", "35 ", "00 ", "00 ", "00 ", "F0 ", "00 ", "27 ", "02 ", "0B ", "02 ", "02 ", "1E ", "00 ", "02 ", "00 ", "00 ", "00 ", "02 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "10 ", "00 ", "00 ", "00 ", "10 ", "00 ", "00 ", "00 ", "00 ", "40 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "10 ", "00 ", "00 ", "00 ", "02 ", "00 ", "00 ", "04 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "05 ", "00 ", "02 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "30 ", "00 ", "00 ", "00 ", "02 ", "00 ", "00 ", "F0 ", "20 ", "00 ", "00 ", "03 ", "00 ", "00 ", "00 ", "00 ", "00 ", "20 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "10 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "10 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "10 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "10 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "20 ", "00 ", "00 ", "14 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00 ", "00" };

const std::vector<std::string> ops = {
"4D","5A","90","00","03","00","00","00","04","00","00",
"00","FF","FF","00","00","B8","00","00","00","00","00","00","00","40","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","80","00","00","00","0E","1F","BA","0E","00","B4","09","CD","21","B8","01","4C","CD","21","54","68","69","73","20","70","72","6F","67","72","61","6D","20","63","61","6E","6E","6F","74","20","62","65","20","72","75","6E","20","69","6E","20","44","4F","53","20","6D","6F","64","65","2E","0D","0D","0A","24","00","00","00","00","00","00","00","50","45","00","00","64","86","02","00","0D","A2","F0","5A","00","06","00","00","35","00","00","00","F0","00","27","02","0B","02","02","1E","00","02","00","00","00","02","00","00","00","00","00","00","00","10","00","00","00","10","00","00","00","00","40","00","00","00","00","00","00","10","00","00","00","02","00","00","04","00","00","00","00","00","00","00","05","00","02","00","00","00","00","00","00","30","00","00","00","02","00","00","F0","20","00","00","03","00","00","00","00","00","20","00","00","00","00","00","00","10","00","00","00","00","00","00","00","00","10","00","00","00","00","00","00","10","00","00","00","00","00","00","00","00","00","00","10","00","00","00","00","00","00","00","00","00","00","00","00","20","00","00","14","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00","00"};

const std::string opsChars = "4D5A90000300000004000000FFFF0000B800000000000000400000000000000000000000000000000000000000000000000000000000000000000000800000000E1FBA0E00B409CD21B8014CCD21546869732070726F6772616D2063616E6E6F742062652072756E20696E20444F53206D6F64652E0D0D0A240000000000000050450000648602000DA2F05A0006000035000000F00027020B02021E000200000002000000000000001000000010000000004000000000000010000000020000040000000000000005000200000000000030000000020000F020000003000000000020000000000000100000000000000000100000000000001000000000000000000000100000000000000000000000002000001400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

const std::string PE_HEADER = "\x4D\x5A\x90\x00\x03\x00\x00\x00\x04\x00\x00\x00\xFF\xFF\x00\x00\xB8\x00\x00\x00\x00\x00\x00\x00\x40\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x80\x00\x00\x00\x0E\x1F\xBA\x0E\x00\xB4\x09\xCD\x21\xB8\x01\x4C\xCD\x21\x54\x68\x69\x73\x20\x70\x72\x6F\x67\x72\x61\x6D\x20\x63\x61\x6E\x6E\x6F\x74\x20\x62\x65\x20\x72\x75\x6E\x20\x69\x6E\x20\x44\x4F\x53\x20\x6D\x6F\x64\x65\x2E\x0D\x0D\x0A\x24\x00\x00\x00\x00\x00\x00\x00\x50\x45\x00\x00\x64\x86\x02\x00\x0D\xA2\xF0\x5A\x00\x06\x00\x00\x35\x00\x00\x00\xF0\x00\x27\x02\x0B\x02\x02\x1E\x00\x02\x00\x00\x00\x02\x00\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x10\x00\x00\x00\x00\x40\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x02\x00\x00\x04\x00\x00\x00\x00\x00\x00\x00\x05\x00\x02\x00\x00\x00\x00\x00\x00\x30\x00\x00\x00\x02\x00\x00\xF0\x20\x00\x00\x03\x00\x00\x00\x00\x00\x20\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x20\x00\x00\x14\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";

template <typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_ostream<CharT, Traits>&
EndLine(std::basic_ostream<CharT, Traits>& outputStream)
{
    return outputStream << outputStream.widen('\n');
}


int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "<Need file>" << EndLine;

        return EXIT_FAILURE;
    }

    std::map<std::string, char> asciimap;
    asciimap["00"] = '\x0';
    asciimap["01"] = '\x1';
    asciimap["02"] = '\x2';
    asciimap["03"] = '\x3';
    asciimap["04"] = '\x4';
    asciimap["05"] = '\x5';
    asciimap["06"] = '\x6';
    asciimap["07"] = '\x7';
    asciimap["08"] = '\x8';
    asciimap["09"] = '\x9';
    asciimap["0A"] = '\xA';
    asciimap["0B"] = '\xB';
    asciimap["0C"] = '\xC';
    asciimap["0D"] = '\xD';
    asciimap["0E"] = '\xE';
    asciimap["0F"] = '\xF';
    asciimap["10"] = '\x10';
    asciimap["11"] = '\x11';
    asciimap["12"] = '\x12';
    asciimap["13"] = '\x13';
    asciimap["14"] = '\x14';
    asciimap["15"] = '\x15';
    asciimap["16"] = '\x16';
    asciimap["17"] = '\x17';
    asciimap["18"] = '\x18';
    asciimap["19"] = '\x19';
    asciimap["1A"] = '\x1A';
    asciimap["1B"] = '\x1B';
    asciimap["1C"] = '\x1C';
    asciimap["1D"] = '\x1D';
    asciimap["1E"] = '\x1E';
    asciimap["1F"] = '\x1F';
    asciimap["20"] = ' ';
    asciimap["21"] = '!';
    asciimap["22"] = '"';
    asciimap["23"] = '#';
    asciimap["24"] = '$';
    asciimap["25"] = '%';
    asciimap["26"] = '&';
    asciimap["27"] = '\'';
    asciimap["28"] = '(';
    asciimap["29"] = ')';
    asciimap["2A"] = '*';
    asciimap["2B"] = '+';
    asciimap["2C"] = ',';
    asciimap["2D"] = '-';
    asciimap["2E"] = '.';
    asciimap["2F"] = '/';
    asciimap["30"] = '0';
    asciimap["31"] = '1';
    asciimap["32"] = '2';
    asciimap["33"] = '3';
    asciimap["34"] = '4';
    asciimap["35"] = '5';
    asciimap["36"] = '6';
    asciimap["37"] = '7';
    asciimap["38"] = '8';
    asciimap["39"] = '9';
    asciimap["3A"] = ':';
    asciimap["3B"] = ';';
    asciimap["3C"] = '<';
    asciimap["3D"] = '=';
    asciimap["3E"] = '>';
    asciimap["3F"] = '?';
    asciimap["40"] = '@';
    asciimap["41"] = 'A';
    asciimap["42"] = 'B';
    asciimap["43"] = 'C';
    asciimap["44"] = 'D';
    asciimap["45"] = 'E';
    asciimap["46"] = 'F';
    asciimap["47"] = 'G';
    asciimap["48"] = 'H';
    asciimap["49"] = 'I';
    asciimap["4A"] = 'J';
    asciimap["4B"] = 'K';
    asciimap["4C"] = 'L';
    asciimap["4D"] = 'M';
    asciimap["4E"] = 'N';
    asciimap["4F"] = 'O';
    asciimap["50"] = 'P';
    asciimap["51"] = 'Q';
    asciimap["52"] = 'R';
    asciimap["53"] = 'S';
    asciimap["54"] = 'T';
    asciimap["55"] = 'U';
    asciimap["56"] = 'V';
    asciimap["57"] = 'W';
    asciimap["58"] = 'X';
    asciimap["59"] = 'Y';
    asciimap["5A"] = 'Z';
    asciimap["5B"] = '[';
    asciimap["5C"] = '\\';
    asciimap["5D"] = ']';
    asciimap["5E"] = '^';
    asciimap["5F"] = '_';
    asciimap["60"] = '`';
    asciimap["61"] = 'a';
    asciimap["62"] = 'b';
    asciimap["63"] = 'c';
    asciimap["64"] = 'd';
    asciimap["65"] = 'e';
    asciimap["66"] = 'f';
    asciimap["67"] = 'g';
    asciimap["68"] = 'h';
    asciimap["69"] = 'i';
    asciimap["6A"] = 'j';
    asciimap["6B"] = 'k';
    asciimap["6C"] = 'l';
    asciimap["6D"] = 'm';
    asciimap["6E"] = 'n';
    asciimap["6F"] = 'o';
    asciimap["70"] = 'p';
    asciimap["71"] = 'q';
    asciimap["72"] = 'r';
    asciimap["73"] = 's';
    asciimap["74"] = 't';
    asciimap["75"] = 'u';
    asciimap["76"] = 'v';
    asciimap["77"] = 'w';
    asciimap["78"] = 'x';
    asciimap["79"] = 'y';
    asciimap["7A"] = 'z';
    asciimap["7B"] = '{';
    asciimap["7C"] = '|';
    asciimap["7D"] = '}';
    asciimap["7E"] = '~';
    asciimap["7F"] = '\x7F';

    std::ofstream outputFile { argv[1], std::ios::out };

    for (auto& op : ops)
    {
        outputFile << asciimap[op];
    }

    outputFile.close();

    // Read in the value of the current ops element
    // Find it in the ascii table
    // Print that value

    // Output code:
    std::ofstream assemblyFile { "a.asm", std::ios::out };

    if (!assemblyFile.is_open())
    {
        std::cerr << "[Error]: Could not create output file." << EndLine;

        return EXIT_FAILURE;
    }

    assemblyFile << "\n" << EndLine;
    assemblyFile << "; file a.asm" << EndLine;
    assemblyFile << "; For x86 (32-bit), assemble with debug information:" << EndLine;
    assemblyFile << ";   ml -c -Zi a.asm" << EndLine;
    assemblyFile << "; For x64 (64-bit), assemble with debug information:" << EndLine;
    assemblyFile << ";   ml64 -c -DX64 -Zi a.asm" << EndLine;
    assemblyFile << "; Then, link with:" << EndLine;
    assemblyFile << ";   ld a.obj" << EndLine;
    assemblyFile << ";" << EndLine;
    assemblyFile << "; In this sample, the 'x64' define excludes source not used" << EndLine;
    assemblyFile << "; when targeting the x64 architecture." << EndLine;

    assemblyFile << "\n" << EndLine;
    assemblyFile << "ifndef x64" << EndLine;
    assemblyFile << ".686p" << EndLine;
    assemblyFile << ".XMM" << EndLine;
    assemblyFile << ".model flat, C" << EndLine;
    assemblyFile << "endif" << EndLine;

    assemblyFile << "\n" << EndLine;
    assemblyFile << ".data" << EndLine;
    assemblyFile << "; user data" << EndLine;

    assemblyFile << "\n" << EndLine;
    assemblyFile << ".code" << EndLine;
    assemblyFile << "; user code" << EndLine;

    assemblyFile << "\n" << EndLine;
    assemblyFile << "fxn PROC public" << EndLine;
    assemblyFile << "\txor eax, eax ; zero function return value" << EndLine;
    assemblyFile << "\tret" << EndLine;
    assemblyFile << "fxn ENDP" << EndLine;

    assemblyFile << "\n" << EndLine;
    assemblyFile << "end" << EndLine;

    assemblyFile.close();
}