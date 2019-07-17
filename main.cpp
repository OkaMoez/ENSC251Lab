//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <vector> // vectors for holding student objects
#include <algorithm> // for tranforming strings etc #### Revise ####
#include "functions.hpp" // header includes info from Labs 1, 2, and 3

void PopulateStudentList (int student_type, StudentList& student_list, string file_path);

int main(){

    // Use function calls to reduce repeated code
    StudentList domestic_students;
    PopulateStudentList(kDomestic, domestic_students, "domestic-stu.txt");
    StudentList international_students;
    PopulateStudentList(kInternational, international_students, "international-stu.txt");

    StartMenu(domestic_students, international_students);

    return 0;
}

void PopulateStudentList (int student_type, StudentList& student_list, string file_path) {
    string file_line; //Read the student file and exit if failed
    ifstream student_file(file_path);
    if(!student_file.is_open()) {
        cout << "Unable to open file " << file_path << endl;
    }

    // Read the first line of student file, which specifies
    // the file format and(don't) print it out to the screen
    getline(student_file, file_line);
    cout << "File format: " << file_line << endl;

    if (student_type == kDomestic){

        while( getline(student_file, file_line) ) {
        // Process each line, get each field separated by a comma.
        // using istringstream to handle it
            istringstream ss(file_line);

            string firstname, lastname, province, s_cgpa, s_researchscore;
            float cgpa;
            int researchscore;

            // get firstname, lastname, province, cpga, and researchScore
            // separated by commas, and convert as needed
            getline(ss, firstname, ',');
            getline(ss, lastname, ',');
            getline(ss, province, ',');
            getline(ss, s_cgpa, ',');
            cgpa = strtof(s_cgpa.c_str(), nullptr); // replaced atof with strtof to remove warning
            getline(ss, s_researchscore, ',');
            researchscore = atoi(s_researchscore.c_str());

            // create new instance of Student, add to list
            Student* currentDStudent = new DomesticStudent(firstname, lastname, cgpa, researchscore, province);
            student_list.NewStudent(currentDStudent);
        }
    }
    else if (student_type == kInternational) {
        while (getline(student_file, file_line)) {
            // process each line, get each field separated by a comma.
            istringstream ss(file_line);

            string firstname, lastname, country, s_cgpa, s_researchscore,
                    s_reading, s_listening, s_speaking, s_writing;
            float cgpa;
            int researchscore, reading, listening, speaking, writing;

            // get data from file as done previously above, converting as needed
            getline(ss, firstname, ','); // retrieve student first name and condition
            transform(firstname.begin(), firstname.end(), firstname.begin(), ::tolower);
            firstname[0] = toupper(firstname[0]);
            getline(ss, lastname, ','); // retrieve student last name and condition
            transform(lastname.begin(), lastname.end(), lastname.begin(), ::tolower);
            lastname[0] = toupper(lastname[0]);
            getline(ss, country, ','); // retrieve student home country
            getline(ss, s_cgpa, ','); // retrieve student cgpa and convert
            cgpa = strtof(s_cgpa.c_str(), nullptr); // replaced as above
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
            Student* currentIStudent = new InternationalStudent(firstname, lastname, cgpa, researchscore, country,
                                                           reading, listening, speaking, writing);
            student_list.NewStudent(currentIStudent);
        }
    }
    else {
        cout << "Error: No StudentList type specified." << endl;
    }
    //close your file
    student_file.close();
}
