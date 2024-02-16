#include <iostream>
#include <string>

using namespace std;

class Course {
public:
    string course_code;
    string course_name;
};

class Grade {
public:
    int mark;
    char the_grade;
};

class Student {
private:
    string reg_number;
    string name;
    int age;
    Course course;
    Grade grade;
    bool grades_calculated;

public:
    void addStudent();
    void editStudent();
    void addMarks();
    void displayStudent();

    string getRegNumber() const {
        return reg_number;
    }

    void setGradesCalculated(bool value) {
        grades_calculated = value;
    }

    bool areGradesCalculated() const {
        return grades_calculated;
    }
};

const int MAX_STUDENTS = 40;
Student students[MAX_STUDENTS];
int numStudents = 0;

void Student::addStudent() {
    if (numStudents < MAX_STUDENTS) {
        cout << "Enter registration number: ";
        cin >> reg_number;

        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter course code: ";
        cin >> course.course_code;

        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, course.course_name);

        grades_calculated = false;
        cout << "Student added successfully!\n";
        numStudents++;
    } else {
        cout << "Error:Maximum limit.\n";
    }
}

void Student::editStudent() {
    string regNum;
    cout << "Enter the registration number of the student: ";
    cin >> regNum;

    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].getRegNumber() == regNum) {
            cout << "Enter new registration number: ";
            cin >> students[i].reg_number;

            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, students[i].name);

            cout << "Enter new age: ";
            cin >> students[i].age;

            cout << "Enter new course code: ";
            cin >> students[i].course.course_code;

            cout << "Enter new course name: ";
            cin.ignore();
            getline(cin, students[i].course.course_name);

            found = true;
            cout << "Student details updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Student with registration number " << regNum << " not found.\n";
    }
}

void Student::addMarks() {
    string regNum;
    cout << "Enter the registration number of the student to add marks: ";
    cin >> regNum;

    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].getRegNumber() == regNum) {
            if (!students[i].areGradesCalculated()) {
                cout << "Enter marks for " << students[i].name << ": ";
                cin >> students[i].grade.mark;

                if (students[i].grade.mark > 69)
                    students[i].grade.the_grade = 'A';
                else if (students[i].grade.mark > 59)
                    students[i].grade.the_grade = 'B';
                else if (students[i].grade.mark > 49)
                    students[i].grade.the_grade = 'C';
                else if (students[i].grade.mark > 39)
                    students[i].grade.the_grade = 'D';
                else
                    students[i].grade.the_grade = 'E';

                students[i].setGradesCalculated(true);
                cout << "Grades calculated and added successfully!\n";
            } else {
                cout << "Grades for " << students[i].name << " are already calculated and cannot be altered.\n";
            }

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with registration number " << regNum << " not found.\n";
    }
}

void Student::displayStudent() {
    cout << "Registration Number: " << reg_number << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Course Code: " << course.course_code << endl;
    cout << "Course Name: " << course.course_name << endl;
    cout << "Grade: " << grade.the_grade << endl;
    cout << "---------------------------\n";
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add student\n";
        cout << "2. Edit student\n";
        cout << "3. Add marks and calculate grades\n";
        cout << "4. Display all students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: students[numStudents].addStudent(); break;
            case 2: students[numStudents].editStudent(); break;
            case 3: students[numStudents].addMarks(); break;
            case 4:
                if (numStudents > 0) {
                    cout << "\nList of students:\n";
                    for (int i = 0; i < numStudents; ++i) {
                        students[i].displayStudent();
                    }
                } else {
                    cout << "No students to display.\n";
                }
                break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}