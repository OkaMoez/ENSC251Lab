//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <vector> // vectors for holding student objects
#include "student.hpp" // header file from Lab1

int main(){
    string line; //Read the domestic-stu.txt file and exit if failed
    ifstream domesticFile("domestic-stu.txt");
    if(!domesticFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        return -1;
    }

    // Read the first line of domestic-stu.txt, which specifies
    // the file format and(don't) print it out to the screen
    getline(domesticFile, line);
    //cout << "File format: " << line << endl;

    // Keep reading the rest of the lines in domestic-stu.txt.
    // read data separated by commas, and print to screen
    int domestic_student_count = 0;

    // initialize InternationalStudent array
    vector<DomesticStudent> domestic_students;
    domestic_students.reserve(100); // vector size as specified in lab doc

    while( getline(domesticFile, line) ) {
    // Process each line, get each field separated by a comma.
    // using istringstream to handle it
    // assuming perfect file format until Lab Assignment 4
        istringstream ss(line);

        string firstname, lastname, province, s_cgpa, s_researchscore;
        float cgpa;
        int researchscore;

        // get firstName separated by comma
        getline(ss, firstname, ',');

        // get lastName separated by comma
        getline(ss, lastname, ',');

        // get province separated by comma
        getline(ss, province, ',');

        // get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = strtof(s_cgpa.c_str(), NULL); // replaced atof with strtof to remove warning
        //Using NULL to maybe dodge compile error on servers, but give local warning

        // get researchScore separated by comma, and convert it to int
        getline(ss, s_researchscore, ',');
        researchscore = atoi(s_researchscore.c_str());

        // create new instance of DomesticStudent, add to vector, increment count
        DomesticStudent currentDStudent(firstname, lastname, cgpa, researchscore, province);
        domestic_students.push_back(currentDStudent);
        unsigned d_count = unsigned(domestic_student_count++);

        //print the student info to the screen using getters
        cout << "Domestic student " << domestic_student_count
             << domestic_students[d_count]
             << endl;
    }

    //close your file
    domesticFile.close();

    // TEACHER COMMENTS END HERE

    // repeat process for International Students
    ifstream internationalFile("international-stu.txt");
    if (!internationalFile.is_open()) {
        cout << "Unable to open file international-stu.txt" << endl;
        return -1;
    }

    // read the first line of international-stu.txt, and (don't)print it on screen
    getline(internationalFile, line);
    //cout << "File format: " << line << endl;

    // keep reading data separated by a comma, and print it on screen.
    int international_student_count = 0;

    // initialize InternationalStudent array
    vector<InternationalStudent> international_students;
    international_students.reserve(100); // vector size as specified in lab doc

    while (getline(internationalFile, line)) {
        // process each line, get each field separated by a comma.
        istringstream ss(line);

        string firstname, lastname, country, s_cgpa, s_researchscore,
                s_reading, s_listening, s_speaking, s_writing;
        float cgpa;
        int researchscore, reading, listening, speaking, writing;

        // get data from file as done previously above, converting as needed
        getline(ss, firstname, ','); // retrieve student first name
        getline(ss, lastname, ','); // retrieve student last name
        getline(ss, country, ','); // retrieve student home country
        getline(ss, s_cgpa, ','); // retrieve student CGPA and convert
        cgpa = strtof(s_cgpa.c_str(), NULL); // replaced as above
        getline(ss, s_researchscore, ','); // retrieve student research score and convert
        researchscore = atoi(s_researchscore.c_str());

        // get ToelfScores separated by commas, and convert each to int
        getline(ss, s_reading, ','); // Toelf reading score
        reading = atoi(s_reading.c_str());
        getline(ss, s_listening, ','); // Toelf listening score
        listening = atoi(s_listening.c_str());
        getline(ss, s_speaking, ','); // Toelf speaking score
        speaking = atoi(s_speaking.c_str());
        getline(ss, s_writing, ','); // Toelf writing score
        writing = atoi(s_writing.c_str());

        // create new instance of InternationalStudent, add to vector, increment count
        InternationalStudent currentIStudent(firstname, "N/A", cgpa, researchscore, country, reading, speaking, listening, writing);
        international_students.push_back(currentIStudent);
        unsigned i_count = unsigned(international_student_count++);

        // print the student info to the screen using getters, including international specific data
        cout << "International student " << international_student_count
             << international_students[i_count]
             << endl;
    }

    // close the file
    internationalFile.close();

    return 0;
}

int compare_firstname(string student_a, string student_b){
    // compare results, 0 is =, -1 is <, 1 is > (alphabetically same case)
    return student_a.compare(student_b);
}

int compare_lastname(string student_a, string student_b){
    // compare results, 0 is =, -1 is <, 1 is > (alphabetically same case)
    return student_a.compare(student_b);
}

int compare_cgpa(int student_a, int student_b){
    // compare results, 0 is =, -1 is <, 1 is >
    if (student_a == student_b)
        return 0;
    else if (student_a < student_b)
        return (-1);
    else
        return 0;
}

int compare_researchscore(int student_a, int student_b){
    // compare results, 0 is =, -1 is <, 1 is >
    if (student_a == student_b)
        return 0;
    else if (student_a < student_b)
        return (-1);
    else
        return 0;
}
