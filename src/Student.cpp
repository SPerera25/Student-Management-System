#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string course;

};

vector<Student> students;

void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();

int main() {

    int choice;

    while(true){
        cout << "===== Student Management System =====" << endl;
        cout << "\n1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void addStudent() {

    int id,age;
    string name,course;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter name: ";
    getline(cin,name);

    cout << "Age: ";
    cin >> age;
    cin.ignore();

    cout << "Course: ";
    getline(cin,course);

    for(int i=0; i<students.size(); i++){
        if(students[i].id==id){
            cout << "A Student with the same id already exsist!" << endl;
            return;
        }
    }

    Student newStudent;

    newStudent.id=id;
    newStudent.name=name;
    newStudent.age=age;
    newStudent.course=course;

    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
    cout << endl;
}

void viewStudents(){

    if(students.empty()){
        cout << "No students found." << endl;
        return;
    }
    cout << "===== Student List =====" << endl;

    for(int i=0; i<students.size(); i++){
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl;
        cout << "------------------------" << endl;
        cout << endl;
    }
}

void searchStudent(){
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    if(students.empty()){
        cout << "Student not found!" << endl;
        return;
    }
    
    for(int i=0; i<students.size(); i++){

        if(students[i].id==id){
            cout << "\n===== Student Found =====" << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Course: " << students[i].course << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
    return;
}

void deleteStudent(){
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    if(students.empty()){
        cout << "Student not found!" << endl;
        return;
    }

    for(int i=0; i<students.size(); i++){

        if(students[i].id==id){
            students.erase(students.begin() + i);
            cout << "Student deleted successfully." << endl;
            return;
        }
    }

    cout << "Invalid ID!" << endl;
    return;
}