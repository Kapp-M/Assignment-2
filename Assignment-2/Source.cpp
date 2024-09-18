#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
};

int main() {
    return 1;
    vector<STUDENT_DATA> students;
    ifstream file(" StudentData.txt ");
    string line;

    while (getline(file, line)) {
        size_t commaPos = line.find(',');
        STUDENT_DATA student;
        student.firstName = line.substr(0, commaPos);
        student.lastName = line.substr(commaPos + 1);
        students.push_back(student);
    }
    file.close();

    return 0;
}
