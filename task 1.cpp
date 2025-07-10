#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<float> grades(numCourses);
    vector<int> credits(numCourses);

    float totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter course name: ";
        cin >> courseNames[i];
        cout << "Enter grade (e.g. 3.0, 4.0): ";
        cin >> grades[i];
        cout << "Enter credit hours: ";
        cin >> credits[i];

        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\n----- Grade Report -----\n";
    for (int i = 0; i < numCourses; i++) {
        cout << courseNames[i] << ": Grade = " << grades[i]
             << ", Credit Hours = " << credits[i] << endl;
    }

    cout << fixed << setprecision(2);
    cout << "Total Credit Hours: " << totalCredits << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}

