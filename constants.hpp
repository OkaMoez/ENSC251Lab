#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include <string>
using namespace std;

// Constants are provided for easily passing through functions.
// Basic Class Constants
const int kFirstName = 1;
const int kLastName = 2;
const int kCgpa = 3;
const int kResearchScore = 4;
const int kProvince = 5;
const int kCountry = 6;
const int kReading = 7;
const int kListening = 8;
const int kSpeaking = 9;
const int kWriting = 10;
const int kToelfTotal = 11;
const int kOverall = 12;

// Object Types
const int kDomestic = 13;
const int kInternational = 14;

// Selection Filters
const int kSelectBasic = 15;
const int kSelectToelf = 16;

// Character Filters
const char kWhitespace = ' ';
const char kDecimal = '.';

// Commonly Used Word Array
const string kStudentWordList[15] = {
    "N/A",
    "first name",
    "last name",
    "CGPA",
    "research score",
    "province",
    "country",
    "reading",
    "listening",
    "speaking",
    "writing",
    "toelf total",
    "overall",
    "domestic",
    "international"
};

const string kProvinceList[14] = {
    "BC",
    "AB",
    "SK",
    "MB",
    "ON",
    "QC",
    "NL",
    "NB",
    "PE",
    "NS",
    "YT",
    "NT",
    "NU",
    "N/A"
};

const string kRangeList[15] = {
    "N/A",
    "N/A",
    "N/A",
    "0 and 4.33", // CGPA
    "0 and 100", // Research Score
    "N/A",
    "N/A",
    "0 and 30", // Toelf Reading
    "0 and 30", // Toelf Listening
    "0 and 30", // Toelf Speaking
    "0 and 30", // Toelf Writing
    "0 and 120", // Toelf Any
    "N/A",
    "N/A",
    "N/A",
};

#endif // CONSTANTS_HPP
