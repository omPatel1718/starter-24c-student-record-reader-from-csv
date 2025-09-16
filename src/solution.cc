#include "solution.hpp"
#include "student.hpp"
#include <fstream>
#include <string>

Student ReadStudentRecFromStream(std::istream& is) {
    std::string first, last;
    if (!(is >> first)) return Student{};
    if (!(is >> last)) return Student{};

    // Check last name ends with comma
    if (last.empty() || last.back() != ',') return Student{};
    last.pop_back(); // remove comma

    unsigned int uin;
    if (!(is >> uin)) return Student{};

    char delim;
    if (!(is >> delim) || delim != ',') return Student{};

    double gpa;
    if (!(is >> gpa)) return Student{};

    std::string full_name = first + " " + last;

    return Student{full_name, uin, gpa};
}
