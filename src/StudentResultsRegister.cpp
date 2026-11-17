
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>

#include "../include/DynamicArray.h"
#include "../include/Sorting.h"
#include "../include/Searching.h"

// Student information structure
struct StudentRecord {
    int id;
    std::string name;
    std::string course;
    double score;
};


struct ById {
    bool operator()(const StudentRecord& a,
                    const StudentRecord& b) const {
        return a.id < b.id;
    }
};

struct ByScore {
    bool operator()(const StudentRecord& a,
                    const StudentRecord& b) const {
        return a.score < b.score;
    }
};

struct ByName {
    bool operator()(const StudentRecord& a,
                    const StudentRecord& b) const {
        return a.name < b.name;
    }
};

// Function to load student records from a file
void loadStudents(DynamicArray<StudentRecord>& students,
                  const std::string& filename) {

    std::ifstream file(filename);

if (!file.is_open()) {
    std::cerr << "Current file path: " << filename << "\n";
    std::cerr << "Could not open the file.\n";
    return;
}

    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << "\n";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {

        std::stringstream ss(line);

        std::string idText;
        std::string name;
        std::string course;
        std::string scoreText;

        std::getline(ss, idText, ',');
        std::getline(ss, name, ',');
        std::getline(ss, course, ',');
        std::getline(ss, scoreText, ',');

        try {
            StudentRecord student;

            student.id = std::stoi(idText);
            student.name = name;
            student.course = course;
            student.score = std::stod(scoreText);

            students.push_back(student);
        }
        catch (const std::exception& error) {
            std::cerr << "Skipping invalid record: "
                      << line << " (" << error.what() << ")\n";
        }
    }

    file.close();
}


void saveStudents(const DynamicArray<StudentRecord>& students,
                  const std::string& filename) {

    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not save to "
                  << filename << "\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {

        file << students.at(i).id << ","
             << students.at(i).name << ","
             << students.at(i).course << ","
             << students.at(i).score << "\n";
    }

    file.close();

    std::cout << "Student records saved successfully.\n";
}

//add student

void addStudent(DynamicArray<StudentRecord>& students,
                const StudentRecord& student) {

    // Check whether the student ID already exists
    for (int i = 0; i < students.size(); i++) {
        if (students.at(i).id == student.id) {
            std::cout << "Error: Student ID already exists.\n";
            return;
        }
    }

    students.push_back(student);

    std::cout << "Student added successfully.\n";
}


//find a student

int findStudent(const DynamicArray<StudentRecord>& students,
                int studentId) {

    for (int i = 0; i < students.size(); i++) {

        if (students.at(i).id == studentId) {
            return i;
        }
    }

    return -1;
}

//remove student

void removeStudent(DynamicArray<StudentRecord>& students,
                   int studentId) {

    int index = findStudent(students, studentId);

    if (index == -1) {
        std::cout << "Student not found.\n";
        return;
    }

    students.removeAt(index);

    std::cout << "Student removed successfully.\n";
}






// Main function
int main() {

    DynamicArray<StudentRecord> students;

    std::cout << "Student Results Register\n";
    std::cout << "========================\n";

    loadStudents(students, "students.txt");

    std::cout << "\nStudent Records:\n";

    for (int i = 0; i < students.size(); i++) {

        std::cout << "ID: " << students.at(i).id
                  << " | Name: " << students.at(i).name
                  << " | Course: " << students.at(i).course
                  << " | Score: " << students.at(i).score
                  << "\n";
    }

    std::cout << "\nTotal students: "
              << students.size() << "\n";

    std::cout << "Array capacity: "
              << students.getCapacity() << "\n";
              
// Test adding a student
StudentRecord newStudent = {111, "Alice", "CS104", 87};

addStudent(students, newStudent);

// Test adding a duplicate student ID
std::cout << "\nTesting duplicate student ID:\n";

StudentRecord duplicateStudent = {111, "Michael", "CS105", 90};

int countBeforeDuplicate = students.size();

addStudent(students, duplicateStudent);

if (students.size() == countBeforeDuplicate) {
    std::cout << "Duplicate ID test PASSED.\n";
} else {
    std::cout << "Duplicate ID test FAILED.\n";
}

// Test searching for a student
int position = findStudent(students, 105);

if (position != -1) {
    std::cout << "Found student: "
              << students.at(position).name << "\n";
} else {
    std::cout << "Student not found.\n";
}

// Test removing a student
removeStudent(students, 103);

// Display updated total
std::cout << "Updated student count: "
          << students.size() << "\n";

// Save updated records

std::cout << "\nSorting students by score using Insertion Sort:\n";

insertionSort(students.raw(), students.size(), ByScore{});

for (int i = 0; i < students.size(); i++) {
    std::cout << students.at(i).name
              << " - " << students.at(i).score << "\n";
}

std::cout << "\nSorting students by ID using Merge Sort:\n";

mergeSort(students.raw(), students.size(), ById{});

std::cout << "\nBinary Search Test:\n";

// Search for student ID 105
StudentRecord target = {105, "", "", 0};

int result = binarySearch(
    students.raw(),
    students.size(),
    target,
    ById{}
);

if (result != -1) {

    std::cout << "Student found: "
              << students.at(result).name
              << " | ID: "
              << students.at(result).id << "\n";

} else {

    std::cout << "Student not found.\n";
}

// Search for a student who does not exist
StudentRecord missing = {999, "", "", 0};

int missingResult = binarySearch(
    students.raw(),
    students.size(),
    missing,
    ById{}
);

if (missingResult == -1) {
    std::cout << "Student ID 999 was not found.\n";
}


for (int i = 0; i < students.size(); i++) {
    std::cout << students.at(i).id
              << " - " << students.at(i).name << "\n";
}

saveStudents(students, "students_updated.txt");


    return 0;
}
