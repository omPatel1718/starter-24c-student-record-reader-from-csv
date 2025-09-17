#include "solution.hpp"
#include "student.hpp"
#include <fstream>
#include <string>

Student ReadStudentRecFromStream(std::istream& is) {
    std::string first, last;
    unsigned int uin;
    double gpa;
    char delim;

    // read first and last name
    if (!(is >> first >> last)) {
        return Student{}; // failed to read
    }

    // check that last name ends with a comma
    if (last.empty() || last.back() != ',') {
        return Student{}; 
    }
    last.pop_back(); // remove the comma

    // combine full name
    std::string fullname = first + " " + last;

    // read delimiter and UIN
    if (!(is >> delim) || delim != ',') {
        return Student{};
    }
    if (!(is >> uin)) {
        return Student{};
    }

    // read delimiter and GPA
    if (!(is >> delim) || delim != ',') {
        return Student{};
    }
    if (!(is >> gpa)) {
        return Student{};
    }

    return Student(fullname, uin, gpa);
}
