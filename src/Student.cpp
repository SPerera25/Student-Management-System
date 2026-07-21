#include "Student.h"

vector<Student> students;

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

        if(age <= 0){
            cout << "Invalid age!" << endl;
        }
        else{
            ageValid = false;
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
    saveToFile();

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
        cout << "ID:\t" << students[i].id << endl;
        cout << "Name:\t" << students[i].name << endl;
        cout << "Age:\t" << students[i].age << endl;
        cout << "Course:\t" << students[i].course << endl;
        cout << "========================" << endl;
        cout << endl;
    }
    return;
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
    cout << "ID:\t" << students[i].id << endl;
    cout << "Name:\t" << students[i].name << endl;
    cout << "Age:\t" << students[i].age << endl;
    cout << "Course:\t" << students[i].course << endl;
    cout<< "============================" << endl;
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
    saveToFile();

    cout << "Student deleted successfully." << endl;
    
}

void updateStudent(){

    int newId,newAge;
    string newName,newCourse;
    bool ageValid = true;

    cout << "Enter ID to update: ";
    cin >> newId;
    cin.ignore();

    //"cin.ignore" Use it when a getline() comes after a cin >>.
    // Don't use it between two getline() calls.
    // Don't use it between two cin >> statements.

    int index = findStudentIndex(newId);
    
    if(index == -1){
        cout << "Student not found!";
        return;
    }

    cout << "New name: ";
    getline(cin,newName);

    
    while(ageValid){

        cout << "New age: ";
        cin >> newAge;
        cin.ignore();

        if(newAge <= 0){
            cout << "Invalid age!" << endl;
        }
        else{
            ageValid = false;
        }
    }

    cout << "New course: ";
    getline(cin,newCourse);
   
    students[index].age=newAge;
    students[index].name=newName;
    students[index].course=newCourse;
        
    saveToFile();

    cout << "\n===== Student Updated =====" << endl;
    cout << "ID:\t" << students[index].id << endl;
    cout << "Name:\t" << students[index].name << endl;
    cout << "Age:\t" << students[index].age << endl;
    cout << "course:\t" << students[index].course << endl;
    cout<< "============================" << endl;
    
}

int findStudentIndex(int id){

    for(int i=0; i<students.size(); i++){
        if(students[i].id==id){
            return i;
        }
    }
    return -1;

}

void saveToFile(){

    ofstream file("students.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    for(int i=0; i<students.size(); i++){
        file << students[i].id << "," 
        << students[i].name << "," 
        << students[i].age << "," 
        << students[i].course << endl;
    }

    file.close();
}

void loadFromFile(){

    students.clear();
    ifstream file("students.txt");

    if (!file) {
        return;
    }

    string line;

    while (getline(file, line)){

        stringstream ss(line);

        string idStr, name, ageStr, course;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, course, ',');
        
        //file stores everything as text. So we convert string into int.
        int id = stoi(idStr);
        int age = stoi(ageStr);

        Student s;

        s.id = id;
        s.name = name;
        s.age = age;
        s.course = course;

        students.push_back(s);
    }
}