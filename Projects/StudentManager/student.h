#pragma once
#include <vector>
#include <cstdint>
#include <string>
#include <map>

using std::string;
using std::vector;

typedef std::uint16_t date_t;
typedef std::uint16_t grade_t;

class Date {
public:
    Date(date_t year, date_t month, date_t day) : year(year), month(month), day(day) {}

    [[nodiscard]] date_t getYear() const { return year; }
    [[nodiscard]] date_t getMonth() const { return month; }
    [[nodiscard]] date_t getDay() const { return day; }

private:
    const date_t year;
    const date_t month;
    const date_t day;
};

class Subject {
public:
    // Add grade
    void addGrade(grade_t grade) { grades.push_back(grade); }

    // Remove grade
    void removeGrade(grade_t grade) {
        for (auto i = grades.begin(); i != grades.end(); i++) {
            if (*i == grade) {
                grades.erase(i);
                break;
            }
        }
    }

    // Getter
    [[nodiscard]] vector<grade_t> getGrades() const { return grades; }

private:
    vector<grade_t> grades;
};

class Grade {
public:
private:
    std::map<string, Subject> subjects;
    // std::map<key, value>
    // for example: std::map<"Luca", 3495710582> dictionary;
    //              std::map<"Luca", 3318708024"> dictionary;
};




class Student {
public:
private:
    string name;
    string surname;
};