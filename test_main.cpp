#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <vector> // vectors for holding student objects
#include <algorithm> // for tranforming strings etc
#include <gtest/gtest.h> // for unit testing
#include "functions.hpp" // header includes info from Labs 1, 2, and 3

/*
int test_main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/

TEST(StudentDomestic, ConstructorTest){
    string firstname = "Brigham";
    string lastname = "Okano";
    float cgpa = float(2.9);
    int researchscore = 90;
    string province = "BC";

    DomesticStudent stu1 = DomesticStudent( firstname, lastname, cgpa, researchscore, province);
    EXPECT_EQ(firstname, stu1.firstname());
    EXPECT_EQ(lastname, stu1.lastname());
    EXPECT_EQ(cgpa, stu1.cgpa());
    EXPECT_EQ(researchscore, stu1.researchscore());
    EXPECT_EQ(province, stu1.province());
    EXPECT_EQ(province, stu1.location());
}
