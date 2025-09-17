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
        return Student{}; 
    }

    // check last name ends with comma
    if (last.empty() || last.back() != ',') {
        return Student{};
    }
    last.pop_back();

    std::string fullname = first + " " + last;

    // consume space then comma before UIN
    is >> std::ws;               // eat whitespace
    if (!is.get(delim) || delim != ',') {
        return Student{};
    }

    if (!(is >> uin)) {
        return Student{};
    }

    // consume space then comma before GPA
    is >> std::ws;
    if (!is.get(delim) || delim != ',') {
        return Student{};
    }

    if (!(is >> gpa)) {
        return Student{};
    }

    return Student(fullname, uin, gpa);
}
