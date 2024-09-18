//Kalp Mehta
//CSCN73030
//Assignment-2
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold student data (first name, last name)
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

#ifdef PRE_RELEASE
// Function to load email data from a text file into a vector
void Load_EmailDataFile(vector<string>& emails) {
    ifstream emailFile("StudentData_Emails.txt");  // Open the email data file
    string email;

    // Read the file line by line and store each email in the vector
    while (getline(emailFile, email)) {
        emails.push_back(email);
    }

    emailFile.close();  // Close the email file after reading
}

// Function to print student data along with emails in pre-release mode
void PreRelease_Print(const vector<STUDENT_DATA>& students, const vector<string>& emails) {
    cout << "PRE-RELEASE MODE: Student Information with Emails:" << endl;
    // Iterate through each student and print their details along with the corresponding email
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "First Name: " << students[i].firstName << ", Last Name: " << students[i].lastName;
        if (i < emails.size()) {
            cout << ", Email: " << emails[i];
        }
        cout << endl;
    }
}
#endif

int main() {
    vector<STUDENT_DATA> students;  // Vector to hold student data
    Load_StudentDataFile(students); // Load student data from file

#ifdef _DEBUG
    Debug_Print(students);  // If in debug mode, it will print student information
#endif

#ifdef PRE_RELEASE
    vector<string> emails;  // Vector to hold email data
    Load_EmailDataFile(emails);  // Load email data from file
    PreRelease_Print(students, emails);  // Print student data along with emails in pre-release mode
#else
    cout << "Running standard version of the application." << endl;  // Default message for standard mode
#endif

    return 0;

#ifdef PRE_RELEASE
    // This code block would run in pre-release mode
    std::cout << "Running in Pre-Release mode" << std::endl;
#else
    // This block would run in standard mode
    std::cout << "Running in Standard mode" << std::endl;
#endif
}
