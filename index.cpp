#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
    int rollNo;
    string name;
    vector<int> marks;
    double percentage;
    char grade;
};

char calculateGrade(double percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 75) return 'B';
    else if (percentage >= 50) return 'C';
    else return 'F';
}

void addStudent(vector<Student>& students) {
    Student s;
    int numSubjects, mark;
    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    cout << "Enter marks for " << numSubjects << " subjects:\n";
    int totalMarks = 0;
    for (int i = 0; i < numSubjects; i++) {
        cout << "Subject " << (i + 1) << ": ";
        cin >> mark;
        s.marks.push_back(mark);
        totalMarks += mark;
    }

    s.percentage = totalMarks / static_cast<double>(numSubjects);
    s.grade = calculateGrade(s.percentage);
    students.push_back(s);

    cout << "\nStudent added successfully!\n";
}

void displayStudent(const Student& s) {
    cout << "\n--- Report Card ---\n";
    cout << "Roll Number: " << s.rollNo << endl;
    cout << "Name: " << s.name << endl;
    cout << "Percentage: " << fixed << setprecision(2) << s.percentage << "%" << endl;
    cout << "Grade: " << s.grade << endl;
}

void searchStudent(const vector<Student>& students) {
    int rollNo;
    cout << "\nEnter Roll Number to Search: ";
    cin >> rollNo;

    for (const auto& s : students) {
        if (s.rollNo == rollNo) {
            displayStudent(s);
            return;
        }
    }
    cout << "Student not found!\n";
}

void menu() {
    cout << "\n1. Add Student\n";
    cout << "2. Display Student Report\n";
    cout << "3. Search Student\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2:
            for (const auto& s : students) {
                displayStudent(s);
            }
            break;
        case 3:
            searchStudent(students);
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
