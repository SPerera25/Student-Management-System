#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string course;

};

extern vector<Student> students;

void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();
void updateStudent();
int findStudentIndex(int id);
void saveToFile();
void loadFromFile();