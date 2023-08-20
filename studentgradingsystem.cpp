#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    double grade;
};

int main() {
    vector<Student> students;
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        cout << "Enter name of student " << i + 1 << ": ";
        cin.ignore();
        getline(cin, student.name);

        cout << "Enter grade for " << student.name << ": ";
        cin >> student.grade;

        students.push_back(student);
    }

    double sumGrades = 0;
    double highestGrade = students[0].grade;
    double lowestGrade = students[0].grade;

    for (const Student& student : students) {
        sumGrades += student.grade;
        highestGrade = max(highestGrade, student.grade);
        lowestGrade = min(lowestGrade, student.grade);
    }

    double averageGrade = sumGrades / numStudents;

    cout << "\nStudent Grades Summary:" << endl;
    cout << "-----------------------" << endl;
    cout << "Average Grade: " << averageGrade << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;

    return 0;
}
