#include <iostream>
#include <string>

using namespace std;

struct Course {
    string course_code;
    string course_name;
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    string reg_number;
    string name;
    int age;
    Course course;
    Grade grade;
    bool grades_calculated;  
};

const int MAX_STUDENTS = 40;
Student students[MAX_STUDENTS];
int numStudents = 0;

void addStudent() {
    if (numStudents < MAX_STUDENTS) {
        cout << "Enter registration number: ";
        cin >> students[numStudents].reg_number;

        cout << "Enter name: ";
        cin.ignore();
        getline(cin, students[numStudents].name);

        cout << "Enter age: ";
        cin >> students[numStudents].age;

        cout << "Enter course code: ";
        cin >> students[numStudents].course.course_code;

        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, students[numStudents].course.course_name);

        students[numStudents].grades_calculated = false;  
        cout << "Student added successfully!\n";
        numStudents++;
    } else {
        cout << "Cannot add more students. Maximum limit reached.\n";
    }
}

void editStudent() {
    string regNum;
    cout << "Enter the registration number of the student to edit: ";
    cin >> regNum;

    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].reg_number == regNum) {
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

void addMarks() {
    string regNum;
    cout << "Enter the registration number of the student to add marks: ";
    cin >> regNum;

    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].reg_number == regNum) {
            if (!students[i].grades_calculated) {
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

                students[i].grades_calculated = true;  
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

void displayStudents() {
    if (numStudents > 0) {
        cout << "\nList of students:\n";
        for (int i = 0; i < numStudents; ++i) {
            cout << "Registration Number: " << students[i].reg_number << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course Code: " << students[i].course.course_code << endl;
            cout << "Course Name: " << students[i].course.course_name << endl;
            cout << "Grade: " << students[i].grade.the_grade << endl;
            cout << "---------------------------\n";
        }
    } else {
        cout << "No students to display.\n";
    }
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
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: addMarks(); break;
            case 4: displayStudents(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}