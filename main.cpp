//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <vector>
#include "student.hpp"

/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */
int main(){
    //Read the domestic-stu.txt file and exit if failed
    string line;
    ifstream domesticFile("domestic-stu.txt");
    if(!domesticFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        return -1;
    }

    //Read the first line of domestic-stu.txt, which specifies
    //the file format. And then print it out to the screen
    getline(domesticFile, line);
    //cout << "File format: " << line << endl;

    /*Keep reading the rest of the lines in domestic-stu.txt.
    * In the example code here, I will read each data separated
    * by a comma, and then print it out to the screen.
    * In your lab assignment 1, you should use these read data
    * to initialize your DomesticStudent object. Then you can
    * use get and set functions to manipulate your object, and
    * print the object content to the screen
    */
    int domestic_student_count = 1;

    while( getline(domesticFile, line) ) {
    /*Process each line, get each field separated by a comma.
    * We use istringstream to handle it.
    * Note in this example code here, we assume the file format
    * is perfect and do NOT handle error cases. We will leave the
    * error and exception handling of file format to Lab Assignment 4
    */
        istringstream ss(line);

        string firstname, lastname, province, s_cgpa, s_researchscore;
        float cgpa;
        int researchscore;

        //get firstName separated by comma
        getline(ss, firstname, ',');

        //get lastName separated by comma
        getline(ss, lastname, ',');

        //get province separated by comma
        getline(ss, province, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = strtof(s_cgpa.c_str(), NULL); // replaced atof with strtof to remove warning

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchscore, ',');
        researchscore = atoi(s_researchscore.c_str());

        // create new instance of DomesticStudent, leave blank fields for Lab 1 required setting
        DomesticStudent currentDStudent(firstname, lastname, cgpa, 0, "N/A");

        // set values for Lab Assignment 1
        currentDStudent.set_researchscore(researchscore);
        currentDStudent.set_province(province);

        //print the student info to the screen using getters
        cout << "Domestic student " << domestic_student_count << " "
             << currentDStudent.firstname() << " " << currentDStudent.lastname()
             << " from " << currentDStudent.province() << " has a CGPA of "
             << currentDStudent.cgpa() << ", and a research score of "
             << currentDStudent.researchscore() << endl;

        domestic_student_count++;
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

    // read the first line of international-stu.txt, and print it on screen
    getline(internationalFile, line);
    //cout << "File format: " << line << endl;

    // keep reading lines with each piece of data separated
    // by a comma, and print it on screen.
    int international_student_count = 1;

    // initialize InternationalStudent array
    vector<InternationalStudent> i_students;
    i_students.reserve(2); // CURRENTLY AN ARBITRARY VALUE (and not really needed)

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

        // create new instance of InternationalStudent, leave blank fields for Lab 1 required setting
        InternationalStudent currentIStudent(firstname, "N/A", cgpa, researchscore, country, reading, speaking, listening, writing);

        // print the student info to the screen using getters, including international specific data
        cout << "International student " << international_student_count << " "
             << currentIStudent.firstname() << " " << currentIStudent.lastname()
             << " from " << currentIStudent.country() << " has a CGPA of "
             << currentIStudent.cgpa() << ", and a research score of "
             << currentIStudent.researchscore() << endl
             << "    TOELF scores are as follows: Reading " << currentIStudent.reading()
             << ", Listening: " << currentIStudent.listening() << ", Speaking: "
             << currentIStudent.speaking() << ", Writing: " << currentIStudent.writing()
             << ", Total: " << currentIStudent.total() << endl;

        international_student_count++;
    }

    // close the file
    internationalFile.close();

    return 0;
}
