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
void updateStudent();
int findStudentIndex(int id);

int main() {

    int choice,id;

    while(true){
        cout << "===== Student Management System =====" << endl;
        cout << "\n1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Update student" << endl;
        cout << "6. Exit\n" << endl;
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
                updateStudent();
                break;
            case 6:
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
    bool ageValid = true,idValid = true;

    while(idValid){

        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        if(id<=0){
            cout << "Invalid id!" << endl;
        }
        else if(id>0){
            idValid = false;
        }
        else{
            cout << "Invalid id!" << endl;
        }

    }

    if(findStudentIndex(id) != -1){
        cout << "A student with this ID already exists!"<< endl;
        return;
    }

    cout << "Enter name: ";
    getline(cin,name);

    while(ageValid){

        cout << "Age: ";
        cin >> age;
        cin.ignore();

        if(age<=0){
            cout << "Invalid age!" << endl;
        }
        else if(age>0){
            ageValid = false;
        }
        else{
            cout << "Invalid age!" << endl;
        }
    }

    cout << "Course: ";
    getline(cin,course);

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

    int i = findStudentIndex(id);

    if( i == -1 ){
        cout << "Student not found!" << endl;
        return;
    }
    
    cout << "\n===== Student Found =====" << endl;
    cout << "ID: " << students[i].id << endl;
    cout << "Name: " << students[i].name << endl;
    cout << "Age: " << students[i].age << endl;
    cout << "Course: " << students[i].course << endl;
    return;

}

void deleteStudent(){
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    int i = findStudentIndex(id);

    if( i == -1 ){
        cout << "Student not found!" << endl;
        return;
    }

    students.erase(students.begin() + i);
    cout << "Student deleted successfully." << endl;
    return;
    
    
}

void updateStudent(){

    int newId,newAge;
    string newName,newCourse;

    cout << "Enter ID to update: ";
    cin >> newId;
    cin.ignore();

    int index = findStudentIndex(newId);
    
    if(index == -1){
        cout << "Student not found!";
        return;
    }

    cout << "New name: ";
    getline(cin,newName);

    cout << "New age: ";
    cin >> newAge;
    cin.ignore();

    cout << "New course: ";
    getline(cin,newCourse);
   
    students[index].age=newAge;
    students[index].name=newName;
    students[index].course=newCourse;

    cout << "\n===== Student Updated =====" << endl;
    cout << "ID: " << students[index].id << endl;
    cout << "Name: " << students[index].name << endl;
    cout << "Age: " << students[index].age << endl;
    cout << "course: " << students[index].course << endl;
    return;
    
}

int findStudentIndex(int id){

    for(int i=0; i<students.size(); i++){
        if(students[i].id==id){
            return i;
        }
    }
    return -1;

}