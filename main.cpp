// ENSC251 Summer 2019 Semester Lab
//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <vector> // vectors for holding student objects
#include <algorithm> // for tranforming strings etc
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

void TestIOString (int student_type, string& string_in) { // Part 1.1 Implementation
    int num_actual = int(std::count(string_in.begin(), string_in.end(), ','));
    int num_expected = 0;
    if (student_type == kDomestic){
        num_expected = 4;
    }
    else if (student_type == kInternational) {
        num_expected = 8;
    }
    else {
        cout << "Error: No Student Format Type Specified" << endl;
    }

    if ( num_actual < num_expected){
        cout << "Error: Invalid File Line Format (" << (num_expected - num_actual) << " "
             << kStudentWordList[student_type] << " field(s) less than expected)" << endl;
        cout << "Error Line: " << string_in << endl;
        exit(EXIT_FAILURE);
    }
    else if (num_actual > num_expected) {
        cout << "Error: Invalid File Line Format (" << (num_actual - num_expected) << " "
             << kStudentWordList[student_type] << " field(s) more than expected)" << endl;
        cout << "Error Line: " << string_in << endl;
        exit(EXIT_FAILURE);
    }
}

string TestName(string name_in, string string_in) {
    if (name_in[0] == '\0') {
        cout << "Error: Missing Name in File" << endl;
        cout << "Error Line: "  << string_in << endl;
        exit(EXIT_FAILURE);
    }
    for (int unsigned i = 0; name_in[i] != '\0'; i++) {
        if (isdigit(name_in[i]) != 0) {
            cout << "Error: Invalid Name from File" << endl;
            cout << "Error Line: "  << string_in << endl;
            exit(EXIT_FAILURE);
        }
    }
    return CleanPNounInput(name_in);
}

string TestProvince (string province_in, string string_in) { // Part 1.2a Implementation
    string province = CleanProvinceInput(province_in);
    if (province[0] == '\0') {
        cout << "Error: Missing Province in File" << endl;
        cout << "Error Line: "  << string_in << endl;
        exit(EXIT_FAILURE);
    }
    else if (!StringArrayContains(kProvinceList, province)){
        cout << "Error: Invalid Province Specified in File" << endl;
        cout << "Error Line: "  << string_in << endl;
        exit(EXIT_FAILURE);
    }
    return province;
}

float TestCgpa (string s_cgpa_in, string string_in) { // Part 1.2b Implementation
    string s_cgpa = s_cgpa_in;
    s_cgpa_in = CleanCharacter(s_cgpa_in, kDecimal);
    if (s_cgpa_in[0] == '\0') {
        cout << "Error: Missing CGPA Value in File" << endl;
        cout << "Error Line: "  << string_in << endl;
        exit(EXIT_FAILURE);
    }
    else if (!StringContains(s_cgpa, '.')) {
        cout << "Warning: Low CGPA Precision in File" << endl;
        cout << "Warning Line: "  << string_in << endl;
    }
    for (int unsigned i = 0; s_cgpa_in[i] != '\0'; i++) {
        if (isdigit(s_cgpa_in[i]) == 0) {
            cout << "Error: Invalid CGPA from File" << endl;
            cout << "Error Line: "  << string_in << endl;
            exit(EXIT_FAILURE);
        }
    }

    float cgpa = strtof(s_cgpa.c_str(), nullptr);
    if ((cgpa < 0) || (double(cgpa) > 4.33)) {
        cout << "Error: Out of Range CGPA from File" << endl;
        cout << "Error Line: "  << string_in << endl;
        exit(EXIT_FAILURE);
    }
    return cgpa;
}

int TestResearchScore (string s_rscore_in, string string_in) { // Part 1.2c Implementation
    if (s_rscore_in[0] == '\0') {
        cout << "Error: Missing Research Score Value in File" << endl;
        cout << "Error Line: "  << string_in << endl;
        exit(EXIT_FAILURE);
    }
    else if (StringContains(s_rscore_in, '.')) {
        cout << "Warning: Research Score with Decimal in File" << endl;
        cout << "Warning Line: "  << string_in << endl;
    }
    for (int unsigned i = 0; s_rscore_in[i] != '\0'; i++) {
        if (isdigit(s_rscore_in[i]) == 0) {
            cout << "Error: Invalid Research Score from File" << endl;
            cout << "Error Line: "  << string_in << endl;
            exit(EXIT_FAILURE);
        }
    }

    int rscore = atoi(s_rscore_in.c_str());
    if ((rscore < 0) || (rscore > 100)) {
        cout << "Error: Out of Range Research Score from File" << endl;
        cout << "Error Line: "  << string_in << endl;
        exit(EXIT_FAILURE);
    }
    return rscore;
}

int TestToelfScore (string s_tscore_in, string string_in) { // Part 1.2d Implementation
    if (s_tscore_in[0] == '\0') {
        cout << "Error: Missing Toelf Score Value in File" << endl;
        cout << "Error Line: "  << string_in << endl;
        exit(EXIT_FAILURE);
    }
    else if (StringContains(s_tscore_in, '.')) {
        cout << "Warning: Toelf Score Precision Too High in File" << endl;
        cout << "Warning Line: "  << string_in << endl;
    }
    for (int unsigned i = 0; s_tscore_in[i] != '\0'; i++) {
        if (isdigit(s_tscore_in[i]) == 0) {
            cout << "Error: Invalid Toelf Score from File" << endl;
            cout << "Error Line: "  << string_in << endl;
            exit(EXIT_FAILURE);
        }
    }

    int tscore = atoi(s_tscore_in.c_str());
    if ((tscore < 0) || (tscore > 30)) {
        cout << "Error: Out of Range Toelf Score from File" << endl;
        cout << "Error Line: "  << string_in << endl;
        exit(EXIT_FAILURE);
    }
    return tscore;
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
            string ss_test = ss.str();


            string firstname, lastname, province, s_cgpa, s_researchscore;
            float cgpa;
            int researchscore;

            // get firstname, lastname, province, cpga, and researchScore
            // separated by commas, and convert as needed
            getline(ss, firstname, ',');
            getline(ss, lastname, ',');
            getline(ss, province, ',');
            getline(ss, s_cgpa, ',');
            getline(ss, s_researchscore, ',');

            // Error Checks (Part 1)
            TestIOString(student_type, ss_test); // Part 1.1
            firstname = TestName(firstname, ss_test);
            lastname = TestName(lastname, ss_test);
            province = TestProvince(province, ss_test); // Part 1.2a
            cgpa = TestCgpa(s_cgpa, ss_test); // Part 1.2b
            researchscore = TestResearchScore(s_researchscore, ss_test); // Part 1.2c

            // create new instance of Student, add to list
            Student* currentDStudent = new DomesticStudent(firstname, lastname, cgpa, researchscore, province);
            student_list.NewStudent(currentDStudent);
        }
    }
    else if (student_type == kInternational) {
        while (getline(student_file, file_line)) {
            // process each line, get each field separated by a comma.
            istringstream ss(file_line);
            string ss_test = ss.str();

            string firstname, lastname, country, s_cgpa, s_researchscore,
                    s_reading, s_listening, s_speaking, s_writing;
            float cgpa;
            int researchscore, reading, listening, speaking, writing;

            // get data from file as done previously above, converting as needed
            getline(ss, firstname, ','); // retrieve student first name and condition
            getline(ss, lastname, ','); // retrieve student last name and condition
            getline(ss, country, ','); // retrieve student home country
            getline(ss, s_cgpa, ','); // retrieve student cgpa and convert
            getline(ss, s_researchscore, ','); // retrieve student research score and convert

            // get ToelfScores separated by commas, and convert each to int
            getline(ss, s_reading, ','); // Toelf reading score
            getline(ss, s_listening, ','); // Toelf listening score
            getline(ss, s_speaking, ','); // Toelf speaking score
            getline(ss, s_writing, ','); // Toelf writing score

            // Error Checks (Part 1)
            TestIOString(student_type, ss_test); // Part 1.1
            firstname = TestName(firstname, ss_test);
            lastname = TestName(lastname, ss_test);
            cgpa = TestCgpa(s_cgpa, ss_test); // Part 1.2b
            researchscore = TestResearchScore(s_researchscore, ss_test); // Part 1.2c
            reading = TestToelfScore(s_reading, ss_test); // Part 1.2d
            listening = TestToelfScore(s_listening, ss_test);
            speaking = TestToelfScore(s_speaking, ss_test);
            writing = TestToelfScore(s_writing, ss_test);

            // create new instance of InternationalStudent, add to vector, increment count
            Student* currentIStudent = new InternationalStudent(firstname, lastname, cgpa, researchscore, country,
                                                           reading, listening, speaking, writing);
            student_list.NewStudent(currentIStudent);
        }
    }
    else {
        cout << "Error: No StudentList Type Specified" << endl;
    }
    //close your file
    student_file.close();
}
