#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
};

// Function to load student data from a text file into a vector
void Load_StudentDataFile(vector<STUDENT_DATA>& students) {
    ifstream inputFile("StudentData.txt");  // Open the input file
    string line;

    // Read the file line by line
    while (getline(inputFile, line)) {
        size_t commaPos = line.find(',');  // Find the position of the comma separating first and last name
        if (commaPos != string::npos) {
            STUDENT_DATA student;
            student.firstName = line.substr(0, commaPos);        // Extract first name
            student.lastName = line.substr(commaPos + 1);        // Extract last name
            students.push_back(student);                        // Add student data to the vector
        }
    }

    inputFile.close();  // Close the file after reading
}

#ifdef _DEBUG
// Function to print student data in debug mode
void Debug_Print(const vector<STUDENT_DATA>& students) {
    cout << "DEBUG MODE: Student Information:" << endl;
    // Iterate through each student and print their details
    for (const auto& student : students) {
        cout << "First Name: " << student.firstName << ", Last Name: " << student.lastName << endl;
    }
}
#endif

int main() {
    vector<STUDENT_DATA> students;  // Vector to hold student data
    Load_StudentDataFile(students); // Load student data from file

#ifdef _DEBUG
    Debug_Print(students);  // If in debug mode, it will print student information
#endif

    return 0;
}
